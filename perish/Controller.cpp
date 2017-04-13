#include "Controller.h"


//CONSTRUCTOR
Controller::Controller()
{
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
	sprintMultiplier = 1.5f;
	isSprinting = 0;
}

//UPDATE
void Controller::update() {
	input();

	//movement
	diagonalAdjust();
	body->SetLinearVelocity(forwardVel + backwardVel + leftVel + rightVel);
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
}

//STOP WALK FORWARD
void Controller::stopWalkForward()
{
	m_forward = 0;
	forwardVel.SetZero();
}

//WALK BACKWARDS
void Controller::walkBackward()
{
	m_backward = 1;
	float32 angle = body->GetAngle() + misc::PI;
	backwardVel = speed * b2Vec2(sin(angle), -cos(angle));
}

//STOP WALK BACKWARDS
void Controller::stopWalkBackwards()
{
	m_backward = 0;
	backwardVel.SetZero();
}

//WALK RIGHT
void Controller::walkRight()
{
	m_right = 1;
	float32 angle = body->GetAngle() - misc::PIh;
	b2Vec2 vector = speed * b2Vec2(-sin(angle), cos(angle));
	rightVel = vector;
}

//STOP WALK RIGHT
void Controller::stopWalkRight()
{
	m_right = 0;
	rightVel.SetZero();
}

//WALK LEFT
void Controller::walkLeft()
{
	m_left = 1;
	float32 angle = body->GetAngle() + misc::PIh;
	leftVel = speed * b2Vec2(-sin(angle), cos(angle));
}

//STOP WALK LEFT
void Controller::stopWalkLeft()
{
	m_left = 0;
	leftVel.SetZero();
}

//ROTATE RIGHT
void Controller::turnRight() {
	body->SetFixedRotation(false);
	body->SetTransform(body->GetPosition(), body->GetAngle() + rotationSpeed);
	body->SetFixedRotation(true);
}

//ROTATE LEFT
void Controller::turnLeft() {
	body->SetFixedRotation(false);
	body->SetTransform(body->GetPosition(), body->GetAngle() - rotationSpeed);
	body->SetFixedRotation(true);
}

//DIAGONAL ADJUST
void Controller::diagonalAdjust()
{
	if (m_forward)
	{
		if (m_left)
		{
			leftVel.SetZero();
			float32 angle = body->GetAngle() + misc::PI7d4;
			forwardVel = speed * b2Vec2(sin(angle), -cos(angle));
			if (isSprinting)
				sprintAdjust(forwardVel);
		}
		else if (m_right)
		{
			rightVel.SetZero();
			float32 angle = body->GetAngle() + misc::PId4;
			forwardVel = speed * b2Vec2(sin(angle), -cos(angle));
			if (isSprinting)
				sprintAdjust(forwardVel);
		}
	}
	else if (m_backward)
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

//SPRINT ADJUST
void Controller::sprintAdjust(b2Vec2& vect){
	vect *= sprintMultiplier;
}

//GET MOVEMENT VECTORS
b2Vec2 Controller::getMovementVectors() {
	return forwardVel + backwardVel + leftVel + rightVel;
}