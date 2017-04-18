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
	type = OTHER;
	loadDefaults();

	//physics setup
	size = (float)misc::random(5, 30);
	physicsBodySetup();
	physicsBoxSetup(size, size);

	texture.loadFromFile("assets/box.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(250/2, 250/2));
	sprite.setScale(size/250.f, size/250.f);
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
	body->SetTransform(spawnPoint, spawnRotation);
	update();
	layerIndex = layer->add(sprite);
	spawned = true;
}