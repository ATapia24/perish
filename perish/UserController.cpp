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
	sprintKey1.set(sf::Keyboard::LShift, KeyType::REPEATED);
	sprintKey2.set(XboxButton::L3, KeyType::REPEATED);
	m_forward = 0;
	m_backward = 0;
	m_left = 0;
	m_right = 0;
	sprintMultiplier = 3.f;
	isSprinting = 0;
}

//INPUT
void UserController::input() {
	
	//forward
	if (forwardKey.getValue())
		walkForward();
	else if (m_forward && !forwardKey.getValue() && wasDirectionalInput) {
		stopWalkForward();
	}
	//backward
	if (backwardKey.getValue())
		walkBackward();
	else if (m_backward && !backwardKey.getValue() && wasDirectionalInput)
		stopWalkBackwards();

	//left
	if (leftKey.getValue())
		walkLeft();
	else if (m_left && !leftKey.getValue() && wasDirectionalInput)
		stopWalkLeft();

	//right
	if (rightKey.getValue())
		walkRight();
	else if (m_right && !rightKey.getValue() && wasDirectionalInput)
		stopWalkRight();
	
	
	move(joystick.leftX(), -joystick.leftY(), true);
	turn(joystick.rightX());

	


	//turn left
	if (turnLeftKey.getValue())
		turnLeft();
	else if (turnRightKey.getValue())
		turnRight();

	isSprinting = sprintKey1.getValue() || sprintKey2.getValue();
}