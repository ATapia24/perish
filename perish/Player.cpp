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

	circleHitbox.setFillColor(sf::Color::Red);
	circleHitbox.setPosition(0, 0);
	circleHitbox.setRadius(15);
	circleHitbox.setOrigin(sf::Vector2f(circleHitbox.getRadius(), circleHitbox.getRadius()));

	type = PLAYER;

	physicsBodySetup();
	physicsCircleSetup(circleHitbox.getRadius());

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
		view->setCenter(misc::pointLocation(circleHitbox.getPosition(), -body->GetAngle() + misc::PIh, (float)VIEW_OFFSET));
		view->setRotation(circleHitbox.getRotation());
	}
}

//spawn
void Player::_spawn() {
	layerIndex = layer->add(circleHitbox);
}
