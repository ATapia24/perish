#include "LightManager.h"

//CONSTRUCTOR
LightManager::LightManager(){
	blockers = new Blocker[max_blockers];
	pcount = 0;
	points.setPrimitiveType(sf::Triangles);
	lastCenter = b2Vec2(0, 0);

	lightTexture.loadFromFile("assets/light.png");
	light.setTexture(lightTexture);
	light.setColor(sf::Color(255, 255, 255, 250));
	float s = 1.f;
	light.scale(s, s);
	light.setOrigin(sf::Vector2f(lightTexture.getSize().x / 2.f, lightTexture.getSize().y / 2.f));
	renderTexture.create(lightTexture.getSize().x * s, lightTexture.getSize().y * s);
	lightMap.setOrigin(sf::Vector2f(lightTexture.getSize().x/2.f*s, lightTexture.getSize().y/2.f*s));
	lightMap.setTexture(renderTexture.getTexture());

	//texture origin offset
	widthOrginOffset = lightTexture.getSize().x / 2.f*s;
	heightOrginOffset = lightTexture.getSize().y / 2.f*s;

	type = EntityType::LIGHT;
}

//DECONSTRUCTOR
LightManager::~LightManager(){
	delete[] blockers;
}


//UPDATE
void LightManager::update() {
	Timer t;
	t.start();


	center = player->getBody()->GetPosition();
	body->SetTransform(center, 0);
	circle.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));

	//check for new center or rotation or movables
	//if (center != lastCenter || containsMovables || true) 
	//{

	pcount = 0;
	int n_calculated = 0;

	
	for (int i = 0; n_calculated != n_blockers; i++){
		if (blockers[i].entity != NULL && misc::distance(player->getBody()->GetPosition(), blockers[i].entity->getBody()->GetPosition())<widthOrginOffset) {
			calculateBlocker(blockers[i]);
			n_calculated++;
		}
	}

	sf::BlendMode blendMode(
		sf::BlendMode::Factor::Zero,              // color src
		sf::BlendMode::Factor::DstColor,          // color dst
		sf::BlendMode::Equation::Add,             // color eq
		sf::BlendMode::Factor::Zero,              // alpha src
		sf::BlendMode::Factor::OneMinusSrcAlpha,  // alpha dst
		sf::BlendMode::Equation::Add);

	//render texture
	light.setPosition(sf::Vector2f(center.x / misc::PHYSICS_SCALE + widthOrginOffset, center.y / misc::PHYSICS_SCALE + heightOrginOffset));
	renderTexture.clear(sf::Color::Transparent);
	renderTexture.draw(light);
	renderTexture.draw(points, blendMode);
	renderTexture.display();
	lightMap.setPosition(sf::Vector2f(center.x * misc::PHYSICS_SCALE, center.y * misc::PHYSICS_SCALE));

	//set last
	lastCenter = center;
	t.stop();

	//std::cout << "n: " << n_blockers << " t: " << (float)t.getNanoseconds() / 1000000.f << '\n';
}

//CALCULATE BLOCKER
void LightManager::calculateBlocker(Blocker& blocker) {

	//if (blocker.entity->getPolyShape() == NULL && blocker.entity->getPolyShape()->GetVertexCount() < 4)
	//	return;

	//get body points
	b2Vec2 p[4];
	float d[4];
	for (int i = 0; i < 4; i++) {
		std::cout << "a\n";
		//p[i] = blocker.entity->getBody()->GetWorldPoint(blocker.entity->getPolyShape()->GetVertex(i));
		std::cout << "b\n";
		d[i] = b2Distance(p[i], center);
	}

	//insertion sort body points by distance array ascending order
	for (int i = 0; i < 4; i++) {
		int j = i;
		while (j > 0 && d[j-1] > d[j]) {
			misc::swap(p[j], p[j - 1]);
			misc::swap(d[j], d[j - 1]);
			j--;
		}
	}

	//calc triangle bottom points
	b2Vec2 bp1, bp2;
	if (misc::intersects(p[0], p[1], center, p[2])) {
		bp1 = p[0];
		bp2 = p[1];
	} else {
		bp1 = p[1];
		bp2 = p[2];
	}

	//calc triangle top points
	b2Vec2 tip1 = misc::pointLocation(bp1, misc::lineAngle(center, bp1), PL_DISTANCE), tip2 = misc::pointLocation(bp2, misc::lineAngle(center, bp2), PL_DISTANCE);

	//setup triangle in points array
	points.resize(pcount + 6);
	points[pcount++] = sf::Vertex(sf::Vector2f(bp1.x * misc::PHYSICS_SCALE - (center.x * misc::PHYSICS_SCALE) + widthOrginOffset, bp1.y * misc::PHYSICS_SCALE - (center.y * misc::PHYSICS_SCALE) + heightOrginOffset));
	points[pcount++] = sf::Vertex(sf::Vector2f(tip1.x * misc::PHYSICS_SCALE - (center.x * misc::PHYSICS_SCALE) + widthOrginOffset, tip1.y * misc::PHYSICS_SCALE - (center.y * misc::PHYSICS_SCALE) + heightOrginOffset));
	points[pcount++] = sf::Vertex(sf::Vector2f(tip2.x * misc::PHYSICS_SCALE - (center.x * misc::PHYSICS_SCALE) + widthOrginOffset, tip2.y * misc::PHYSICS_SCALE - (center.y * misc::PHYSICS_SCALE) + heightOrginOffset));
	points[pcount++] = sf::Vertex(sf::Vector2f(bp1.x * misc::PHYSICS_SCALE - (center.x * misc::PHYSICS_SCALE) + widthOrginOffset, bp1.y * misc::PHYSICS_SCALE - (center.y * misc::PHYSICS_SCALE) + heightOrginOffset));
	points[pcount++] = sf::Vertex(sf::Vector2f(bp2.x * misc::PHYSICS_SCALE - (center.x * misc::PHYSICS_SCALE) + widthOrginOffset, bp2.y * misc::PHYSICS_SCALE - (center.y * misc::PHYSICS_SCALE) + heightOrginOffset));
	points[pcount++] = sf::Vertex(sf::Vector2f(tip2.x * misc::PHYSICS_SCALE - (center.x * misc::PHYSICS_SCALE) + widthOrginOffset, tip2.y * misc::PHYSICS_SCALE - (center.y * misc::PHYSICS_SCALE) + heightOrginOffset));
}

//SET
void LightManager::set(Entity* _entity, DrawLayer& _layer, b2World* _physWorld) {
	layer = &_layer;
	player = _entity;
	physWorld = _physWorld;
	//lightMap.setColor(misc::randomColor());
	lightMap.setColor(sf::Color(55, 55, 55, 200));
	layer->add(lightMap, sf::BlendAdd);
	layer->add(lightHitbox);
	//layer->add(circle);

	//sensor setup

	//body def
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;

	//body
	body = physWorld->CreateBody(bodyDef);
	body->SetActive(true);
	body->SetUserData(this);

	//fixture
	fixtureDef = new b2FixtureDef();

	circleShape = new b2CircleShape();
	circleShape->m_radius = widthOrginOffset / misc::PHYSICS_SCALE;
	fixtureDef->shape = circleShape;
	body->CreateFixture(fixtureDef);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(2.f);
	circle.setRadius(widthOrginOffset);
	circle.setOrigin(widthOrginOffset, heightOrginOffset);
}

//ADD OBJECT
void LightManager::addObject(Entity* obj) {
	
	if (obj->getLightIndex() != -1)
		return;
	/*
	for (int i = 0; i < max_blockers; i++) {
		if (blockers[i].entity == NULL) {
			blockers[i].entity = obj;
			obj->setLightIndex(i);
			n_blockers++;
			return;
		}
	}*/

	if (obj == player || obj->getLightIndex() != -1)
		return;

	for (int i = 0; i < max_blockers; i++)
	{
		if (blockers[i].entity == NULL) {
			blockers[i].entity = obj;
			//obj->setLightIndex(i);
			n_blockers++;
			break;
		}
	}
	//blockers[n_blockers].entity = obj;
	//n_blockers++;
	
}

//REMOVE OBJECT
void LightManager::removeObject(int index) {
	//blockers[index].entity->setLightIndex(-1);
	//blockers[index].entity = NULL;
	//n_blockers--;
}

bool LightManager::beginContact(Entity* entity, b2Contact* contact) {
	return false;
}

bool LightManager::endContact(Entity* entity, b2Contact* contact) {

	/*r (int i = 0; i < max_blockers; i++) {
		if (blockers[i].entity == entity) {
			blockers[i].entity = NULL;
			n_blockers--;
			break;
		}
	}*/
	return false;
}

bool LightManager::preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold) {

	/*r (int i = 0; i < max_blockers; i++) {
		if (blockers[i].entity == entity)
			return false;
	}

	contact->SetEnabled(false);
	for (int i = 0; i < max_blockers; i++) {
		if (blockers[i].entity == NULL) {
			blockers[i].entity = entity;
			n_blockers++;
			break;
		}
	}*/
	return false;
}

bool LightManager::postSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
	return false;
}
