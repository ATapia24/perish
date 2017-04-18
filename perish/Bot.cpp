#include "Bot.h"



Bot::Bot()
{
}


Bot::~Bot()
{
}

void Bot::load(b2World* _physWorld, DrawLayer& _layer) {
	physWorld = _physWorld;
	layer = &_layer;
	type = OTHER;
	loadDefaults();

	//physics setup
	size = 30;
	physicsBodySetup();
	physicsBoxSetup(size, size);

	texture.loadFromFile("assets/topdown.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(size / 2, size / 2));
}

//UPDATE
void Bot::update() {
	if (spawned) {
		if (target != NULL) {
			float targetAngle = misc::lineAngle(body->GetPosition(), target->GetPosition());
			std::cout << "angle: " << targetAngle*misc::RAD2DEG << '\n';
			body->SetTransform(body->GetPosition(), -targetAngle);
		}
		
		sprite.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));
		sprite.setRotation(body->GetAngle() * misc::RAD2DEG);
	}
}

//UNLOAD
void Bot::unload() {
	physicsDelete();
}

//SET TARGET
void Bot::setTarget(b2Body* _target) {
	if (_target != NULL) {
		target = _target;
	}
}

//SPAWN
void Bot::_spawn() {
	body->SetTransform(spawnPoint, spawnRotation);
	update();
	layerIndex = layer->add(sprite);
	spawned = true;
}