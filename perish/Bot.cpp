#include "Bot.h"



Bot::Bot()
{
}


Bot::~Bot()
{
}

void Bot::load(b2World* _physWorld, DrawLayer& _layer) {

	if (!loaded) {
		loaded = true;
		physWorld = _physWorld;
		layer = &_layer;
		type = ENEMY;
		loadDefaults();

		width = 20;
		height = 20;
		density = 0.001f;
		physicsBodySetup();
		physicsBoxSetup(width, height);
		controller.load(body, 1.f, 5.f);


		texture.loadFromFile("assets/topdown.png");
		sprite.setTexture(texture);
		sprite.setColor(misc::randomColor());
		sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f));
		sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
		rect.setSize(sf::Vector2f(width, height));
		rect.setOrigin(sf::Vector2f(width / 2, height / 2));
	}
}

//UPDATE
void Bot::update() {

	controller.update();

	if (spawned) {
		//look at target
		if (true) {
			float targetAngle = misc::lineAngle(body->GetPosition(),target.getTargetPoint()) + misc::PIh;
			body->SetTransform(body->GetPosition(), targetAngle);
		}

		
		//move to target
		float speed = 0.0005;
		float32 angle = body->GetAngle() + misc::PI/2;
		body->ApplyLinearImpulseToCenter(b2Vec2(-sin(angle) * speed, cos(angle) * speed), true);
		angle += misc::PIh;

		//body->ApplyLinearImpulseToCenter(b2Vec2(-sin(angle) * speed, cos(angle) * speed), true);

		misc::mutex.lock();
		sprite.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));
		sprite.setRotation(body->GetAngle() * misc::RAD2DEG + 180.f);
		misc::mutex.unlock();
	}
	if (!spawned)
		spawn();
}

//UNLOAD
void Bot::unload() {

}


//SPAWN
void Bot::_spawn() {
	if (!physReady) {
		physicsBodySetup();
		physicsBoxSetup(width, height);
	}
	
	body->SetTransform(spawnPoint, spawnRotation);
	update();
	layerIndex = layer->add(sprite);
	spawned = true;
}

//KILL
void Bot::kill() {
	if (spawned) {
		spawned = false;
		layer->remove(layerIndex);
		body->SetActive(false);
	}
}

//BEGIN CONTACT
bool Bot::beginContact(Entity* entity, b2Contact* contact) {
	if (entity->getType() == LIGHT){
		sprite.setColor(sf::Color::Green);
		//std::cout << "start\n";
	}
	return false;
}

//END CONTACT
bool Bot::endContact(Entity* entity, b2Contact* contact) {
	 if (entity->getType() == LIGHT) {
		sprite.setColor(sf::Color::White);
		//std::cout << "end\n";
	}
	return false;
}

//PRE-SOLVE
bool Bot::preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold) {
	
	/*if (static_cast<Entity*>(contact->GetFixtureB()->GetUserData())->getType() == EntityType::ENEMY) {
		//contact->SetEnabled(false);
		Bot* bot = static_cast<Bot*>(contact->GetFixtureB()->GetUserData());
		std::cout << bot->getType() << '\n';
	}*/

	return false;
}

//POST-SOLVE
bool Bot::postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse) {
	if (entity->getType() == PLAYER)
		return true;

	return false;
}