#include "UserController.h"


//CONSTUCTOR
UserController::UserController()
{
}

//DECONSTRUCTOR
UserController::~UserController()
{
}

//LOAD
void UserController::load(sf::View* _view, b2Body* _body, float _speed, float _rotationSpeed) {
	view = _view;
	body = _body;
	speed = _speed;
	rotationSpeed = _rotationSpeed;
	forwardKey.set(sf::Keyboard::W, KeyType::REPEATED);
	backwardKey.set(sf::Keyboard::S, KeyType::REPEATED);
	leftKey.set(sf::Keyboard::A, KeyType::REPEATED);
	rightKey.set(sf::Keyboard::D, KeyType::REPEATED);
	turnLeftKey.set(sf::Keyboard::Left, KeyType::REPEATED);
	turnRightKey.set(sf::Keyboard::Right, KeyType::REPEATED);
	sprintKey.set(sf::Keyboard::LShift, KeyType::REPEATED);
	m_forward = 0;
	m_backward = 0;
	m_left = 0;
	m_right = 0;
	sprintMultiplier = 3.f;
	isSprinting = 0;
}

//UPDATE
void UserController::update() {
	input();

	//movement
	diagonalAdjust();
	body->SetLinearVelocity(forwardVel + backwardVel + leftVel + rightVel);
}

//INPUT
void UserController::input() {
	//forward
	if (forwardKey.getValue())
		walkForward();
	else if (m_forward && !forwardKey.getValue())
		stopWalkForward();

	//backward
	if (backwardKey.getValue())
		walkBackward();
	else if (m_backward && !backwardKey.getValue())
		stopWalkBackwards();

	//left
	if (leftKey.getValue())
		walkLeft();
	else if (m_left && !leftKey.getValue())
		stopWalkLeft();

	//right
	if (rightKey.getValue())
		walkRight();
	else if (m_right && !rightKey.getValue())
		stopWalkRight();

	//turn left
	if (turnLeftKey.getValue())
		turnLeft();
	else if (turnRightKey.getValue())
		turnRight();

	isSprinting = sprintKey.getValue();
}