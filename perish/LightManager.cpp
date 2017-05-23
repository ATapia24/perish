#include "LightManager.h"


//CONSTRUCTOR
LightManager::LightManager(){
	blockers = new Blocker[max_blockers];
	pcount = 0;
	points.setPrimitiveType(sf::Triangles);
	blockerColor = sf::Color(255, 0, 0, 255);
	lastCenter = b2Vec2(0, 0);

	renderTexture.create(1280, 720, true);
	//lightTexture.loadFromFile("assets/light.png");
	light.setTexture(lightTexture);
	light.setOrigin(sf::Vector2f(lightTexture.getSize().x / 2, lightTexture.getSize().y / 2));
	//light.setColor(sf::Color(255, 255, 255, 255));
	light.setScale(2, 2);
}

//DECONSTRUCTOR
LightManager::~LightManager(){
	delete[] blockers;
}

//UPDATE
void LightManager::update() {
	center = player->getBody()->GetPosition();

	//check for new center or rotation or movables
	if (center != lastCenter || containsMovables || true)
	{
		pcount = 0;
		for (int i = 0; i < n_blockers; i++)
			//if (blockers[i].entity->isOneScreen())
				calculateBlocker(blockers[i]);

		sf::BlendMode blendMode(sf::BlendMode::Zero, sf::BlendMode::OneMinusSrcColor, sf::BlendMode::Equation::Add);


		light.setPosition(center.x * misc::PHYSICS_SCALE, center.y * misc::PHYSICS_SCALE);
		renderTexture.clear(sf::Color(255, 255, 255, 100));
		renderTexture.draw(light);
		renderTexture.draw(points, blendMode);
		renderTexture.display();

		lightMap.setTexture(renderTexture.getTexture());
	}

	//set last
	lastCenter = center;

}

//CALCULATE BLOCKER
void LightManager::calculateBlocker(Blocker& blocker) {
	//get body points
	b2Vec2 p[4];
	p[0] = blocker.entity->getBody()->GetWorldPoint(blocker.entity->getPolyShape()->GetVertex(0));
	p[1] = blocker.entity->getBody()->GetWorldPoint(blocker.entity->getPolyShape()->GetVertex(1));
	p[2] = blocker.entity->getBody()->GetWorldPoint(blocker.entity->getPolyShape()->GetVertex(2));
	p[3] = blocker.entity->getBody()->GetWorldPoint(blocker.entity->getPolyShape()->GetVertex(3));

	//sort body points by distance ascending order
	b2Vec2 tmp;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			//if (misc::distance(p[i], center) < misc::distance(p[j], center))
			if(b2Distance(p[i], center) < b2Distance(p[j], center))
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
			j == i - 1 ? j++ : j;
		}

	//calc triangle bottom points
	b2Vec2 bp1, bp2;

	if (misc::intersects(p[0], p[1], center, p[2])) {
		bp1 = p[0];
		bp2 = p[1];
	}
	else
	{
		if (misc::intersects(center, p[1], p[0], p[2])) {
			bp1 = p[0];
			bp2 = p[2];
		}
		else {
			bp1 = p[1];
			bp2 = p[2];
		}
	}

	//calc triangle top points
	b2Vec2 tip1 = misc::pointLocation(bp1, misc::lineAngle(center, bp1), 60000);
	b2Vec2 tip2 = misc::pointLocation(bp2, misc::lineAngle(center, bp2), 60000);

	//setup triangle in points array
	points.resize(pcount + 6);
	points[0 + pcount] = sf::Vertex(sf::Vector2f(bp1.x *misc::PHYSICS_SCALE, bp1.y * misc::PHYSICS_SCALE));
	points[1 + pcount] = sf::Vertex(sf::Vector2f(tip1.x * misc::PHYSICS_SCALE, tip1.y * misc::PHYSICS_SCALE));
	points[2 + pcount] = sf::Vertex(sf::Vector2f(tip2.x * misc::PHYSICS_SCALE, tip2.y * misc::PHYSICS_SCALE));
	points[3 + pcount] = sf::Vertex(sf::Vector2f(bp1.x * misc::PHYSICS_SCALE, bp1.y * misc::PHYSICS_SCALE));
	points[4 + pcount] = sf::Vertex(sf::Vector2f(bp2.x * misc::PHYSICS_SCALE, bp2.y * misc::PHYSICS_SCALE));
	points[5 + pcount] = sf::Vertex(sf::Vector2f(tip2.x * misc::PHYSICS_SCALE, tip2.y * misc::PHYSICS_SCALE));

	//set color
	points[0 + pcount].color = blockerColor;
	points[1 + pcount].color = blockerColor;
	points[2 + pcount].color = blockerColor;
	points[3 + pcount].color = blockerColor;
	points[4 + pcount].color = blockerColor;
	points[5 + pcount].color = blockerColor;

	//adjust pcount
	pcount += 6;

	//set last postition
	blocker.lastPosition = blocker.entity->getBody()->GetPosition();

	//lightMap.setPosition(sf::Vector2f(center.x * misc::PHYSICS_SCALE, center.y * misc::PHYSICS_SCALE));//
}

//SET
void LightManager::set(DrawLayer* _layer, Entity* _player) {
	layer = _layer;
	player = _player;
	layer->add(lightMap, sf::BlendAlpha);
}

//ADD OBJECT
void LightManager::addObject(Entity* obj) {
	blockers[n_blockers].entity = obj;
	n_blockers++;
}
