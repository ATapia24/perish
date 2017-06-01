#include "Player.h"



Player::Player()
{
}

Player::~Player()
{
	unload();
}

//LOAD
void Player::load(sf::View* _view, b2World* _physWorld, DrawLayer& _layer) {
	view = _view;
	physWorld = _physWorld;
	layer = &_layer;
	loadDefaults();

	float size = 30.f;
	texture.loadFromFile("assets/redball.png");
	circleHitbox.setTexture(texture);
	circleHitbox.setOrigin(sf::Vector2f(texture.getSize().x / 2, texture.getSize().y / 2));
	circleHitbox.setScale(size / texture.getSize().x, size / texture.getSize().y);

	type = PLAYER;
	density = 10.0f;
	physicsBodySetup();
	physicsCircleSetup(size/2.f);

	controller.load(view, body, speed, rotationSpeed);
}

//UNLOAD
void Player::unload() {
	if(layerIndex != -1)
		layer->remove(layerIndex);
	physicsDelete();
}

//UPDATE
void Player::update() {
	if (spawned) {
		controller.update();
		circleHitbox.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));
		circleHitbox.setRotation(body->GetAngle() * misc::RAD2DEG);
		view->setCenter(misc::pointLocation(circleHitbox.getPosition(), body->GetAngle(), (float)VIEW_OFFSET));
		view->setRotation(circleHitbox.getRotation());
	}
}

//spawn
void Player::_spawn() {
	layerIndex = layer->add(circleHitbox);
}


//START CONTACT
bool Player::beginContact(Entity* entity, b2Contact* contact) {
	return false;
}

//END CONTACT
bool Player::endContact(Entity* entity, b2Contact* contact) {
	return false;
}

//PRE-SOLVE
bool Player::preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold) {
	return false;
}

//POST SOLVE
bool Player::postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse) {
	return false;
}