#include "Controller.h"


//CONSTRUCTOR
Controller::Controller()
{
	speed = 0;
	rotationSpeed = 0;

}

//DECONSTRUCTOR
Controller::~Controller()
{
}

//LOAD
void Controller::load(b2Body* _body, float _speed, float _rotationSpeed) {
	body = _body;
	speed = _speed;
	rotationSpeed = _rotationSpeed;
	m_forward = 0;
	m_backward = 0;
	m_left = 0;
	m_right = 0;
	sprintMultiplier = 3.f;
	isSprinting = 0;
	wasDirectionalInput = true;
	lastHorizontalRate = 1.f;
	lastVerticalRate = 1.f;
}

//UPDATE
void Controller::update() {
	input();

	//movement
	diagonalAdjust();
	body->SetLinearVelocity(forwardVel + backwardVel + leftVel + rightVel);
	wasDirectionalInput = false;
}

//INPUT
void Controller::input() {

}

//WALK FORWARD
void Controller::walkForward()
{
	m_forward = 1;
	float32 angle = body->GetAngle();
	forwardVel = speed * b2Vec2(sin(angle), -cos(angle));
	if (isSprinting)
		sprintAdjust(forwardVel);

	wasDirectionalInput = true;
}

//STOP WALK FORWARD
void Controller::stopWalkForward()
{
	m_forward = 0;
	forwardVel.SetZero();
	wasDirectionalInput = true;
}

//WALK BACKWARDS
void Controller::walkBackward()
{
	m_backward = 1;
	float32 angle = body->GetAngle() + misc::PI;
	backwardVel = speed * b2Vec2(sin(angle), -cos(angle));
	wasDirectionalInput = true;
}

//STOP WALK BACKWARDS
void Controller::stopWalkBackwards()
{
	m_backward = 0;
	backwardVel.SetZero();
	wasDirectionalInput = true;
}

//WALK RIGHT
void Controller::walkRight()
{
	m_right = 1;
	float32 angle = body->GetAngle() - misc::PIh;
	rightVel = speed * b2Vec2(-sin(angle), cos(angle));
	wasDirectionalInput = true;
}

//STOP WALK RIGHT
void Controller::stopWalkRight()
{
	m_right = 0;
	rightVel.SetZero();
	wasDirectionalInput = true;
}

//WALK LEFT
void Controller::walkLeft()
{
	m_left = 1;
	float32 angle = body->GetAngle() + misc::PIh;
	leftVel = speed * b2Vec2(-sin(angle), cos(angle));
	wasDirectionalInput = true;
}

//STOP WALK LEFT
void Controller::stopWalkLeft()
{
	m_left = 0;
	leftVel.SetZero();
	wasDirectionalInput = true;
}

//TURN RIGHT
void Controller::turnRight() {
	body->SetFixedRotation(false);
	body->SetTransform(body->GetPosition(), body->GetAngle() + rotationSpeed);
	body->SetFixedRotation(true);
}

//TURN LEFT
void Controller::turnLeft() {
	body->SetFixedRotation(false);
	body->SetTransform(body->GetPosition(), body->GetAngle() - rotationSpeed);
	body->SetFixedRotation(true);
}

//DIAGONAL ADJUST
//desc. adjust speed when moving diagonally
void Controller::diagonalAdjust()
{
	if (m_forward && wasDirectionalInput)
	{
		if (m_left)
		{
			leftVel.SetZero();
			float32 angle = body->GetAngle() + misc::PI7d4;
			if (lastVerticalRate < 0)
				lastVerticalRate *= -1;
			forwardVel =  speed * b2Vec2(sin(angle), -cos(angle));
			if (isSprinting)
				sprintAdjust(forwardVel);
		}
		else if (m_right)
		{
			rightVel.SetZero();
			float32 angle = body->GetAngle() + misc::PId4;
			if (lastVerticalRate < 0)
				lastVerticalRate *= -1;
			forwardVel = speed * b2Vec2(sin(angle), -cos(angle));
			if (isSprinting)
				sprintAdjust(forwardVel);
		}
	}
	else if (m_backward && wasDirectionalInput)
	{
		if (m_left)
		{
			leftVel.SetZero();
			float32 angle = body->GetAngle() + misc::PI5d4;
			backwardVel = speed * b2Vec2(sin(angle), -cos(angle));
		}
		else if (m_right)
		{
			rightVel.SetZero();
			float32 angle = body->GetAngle() + misc::PI3d4;
			backwardVel = speed * b2Vec2(sin(angle), -cos(angle));
		}
	}
}

//MOVE
//Desc. move at a specific rate. *useful for joysticks
void Controller::move(float horizontalRate, float verticalRate) {
	if (!wasDirectionalInput) {
		float32 angle = body->GetAngle();
		lastHorizontalRate = horizontalRate;
		lastVerticalRate = verticalRate;
		forwardVel = verticalRate * speed * (isSprinting ? sprintMultiplier : 1.f) * b2Vec2(sin(angle), -cos(angle));
		angle -= misc::PIh;
		rightVel = horizontalRate * speed * (isSprinting ? sprintMultiplier : 1.f) * b2Vec2(-sin(angle), cos(angle));
		updateMovingDirections(horizontalRate, verticalRate);
	}
}

//MOVE w/ onlySprintForward
//Desc. move at a specific rate.
void Controller::move(float horizontalRate, float verticalRate, bool onlySprintForward) {

	if (!wasDirectionalInput) {
		float32 angle = body->GetAngle();
		lastHorizontalRate = horizontalRate;
		lastVerticalRate = verticalRate;	forwardVel = verticalRate * speed * (isSprinting && (onlySprintForward ? verticalRate >= 0 : 0) ? sprintMultiplier : 1.f) * b2Vec2(sin(angle), -cos(angle));
		angle -= misc::PIh;
		rightVel = horizontalRate * speed * (isSprinting ? sprintMultiplier : 1.f) * b2Vec2(-sin(angle), cos(angle));
		updateMovingDirections(horizontalRate, verticalRate);
	}
}

//MOVE w/onlySprintForward
//Desc. move at specific rate
void Controller::move(float horizontalRate, float verticalRate, bool onlySprintForward, bool sprintHorizontally) {
	if (!wasDirectionalInput) {
		float32 angle = body->GetAngle();
		lastHorizontalRate = horizontalRate;
		lastVerticalRate = verticalRate;
		forwardVel = verticalRate * speed * (isSprinting && (onlySprintForward ? verticalRate >= 0 : 0) ? sprintMultiplier : 1.f) * b2Vec2(sin(angle), -cos(angle));
		angle -= misc::PIh;
		rightVel = horizontalRate * speed * (isSprinting && sprintHorizontally ? sprintMultiplier : 1.f) * b2Vec2(-sin(angle), cos(angle));
		updateMovingDirections(horizontalRate, verticalRate);
	}
}

//UPDATE MOVING DIRECTIONS
//Desc. update the moving direction to reflect current rates
void Controller::updateMovingDirections(float horizontalRate, float verticalRate) {
	
	//horizontal
	if (horizontalRate > 0) {
		m_right = true;
		m_left = false;
	}
	else if (horizontalRate < 0) {
		m_left = true;
		m_right = false;
	}
	else {
		m_right = false;
		m_left = false;
	}

	//vertical
	if (verticalRate > 0) {
		m_forward = true;
		m_backward = false;
	}
	else if (verticalRate < 0) {
		m_backward = true;
		m_forward = false;
	}
	else {
		m_forward = false;
		m_backward = false;
	}

}


//TURN
//Desc. turn at a specific rate
void Controller::turn(float rate) {
	body->SetFixedRotation(false);
	body->SetTransform(body->GetPosition(), body->GetAngle() + rotationSpeed * rate);
	body->SetFixedRotation(true);
}

//SPRINT ADJUST
void Controller::sprintAdjust(b2Vec2& vect){
	vect *= sprintMultiplier;
}

//GET MOVEMENT VECTORS
b2Vec2 Controller::getMovementVectors() const {
	return forwardVel + backwardVel + leftVel + rightVel;
}

//IS MOVING FORWARD
bool Controller::isMovingForward() const {
	return m_forward;
}

//IS MOVING BACKWARD
bool Controller::isMovingBackward() const {
	return m_backward;
}

//IS MOVING LEFT
bool Controller::isMovingLeft() const {
	return m_left;
}

//IS MOVING RIGHT
bool Controller::isMovingRight() const {
	return m_right;
}