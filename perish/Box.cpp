#include "Box.h"



Box::Box()
{
}


Box::~Box()
{
	unload();
}

void Box::load(b2World* _physWorld, DrawLayer& _layer) {
	physWorld = _physWorld;
	layer = &_layer;
	type = PLAYER;
	layerIndex = layer->add(sprite);
	loadDefaults();

	//physics setup
	physicsBodySetup();
	physicsBoxSetup(25, 25);

	texture.loadFromFile("assets/box.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(250/2, 250/2));
	sprite.setScale(0.1f, 0.1f);
}

void Box::update() {
	if (spawned) {
		sprite.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));
		sprite.setRotation(body->GetAngle() * misc::RAD2DEG);
	}
}
void Box::unload() {
	physicsDelete();
}


//SPAWN
void Box::_spawn() {
	layerIndex = layer->add(sprite);
}