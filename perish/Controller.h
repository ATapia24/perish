#pragma once

#include <SFML\Graphics.hpp>
#include "Box2D.h"
#include "Miscellaneous.h"

class Controller
{
public:
	Controller();
	~Controller();
	virtual void load(b2Body* _body, float _speed, float _rotationSpeed);
	virtual void update();
	virtual void input();
protected:
	b2Body* body;
	float speed;
	float rotationSpeed;
	float sprintMultiplier;
	b2Vec2 forwardVel, backwardVel, leftVel, rightVel;
	bool m_forward, m_backward, m_left, m_right;
	bool isSprinting;
	void walkForward();
	void stopWalkForward();
	void walkBackward();
	void stopWalkBackwards();
	void walkRight();
	void walkLeft();
	void stopWalkRight();
	void stopWalkLeft();
	void diagonalAdjust();
	void turnRight();
	void turnLeft();
	void sprintAdjust(b2Vec2& vect);
	b2Vec2 getMovementVectors();
};

