#ifndef CONTROLELR_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>
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
	void turn(float rate);
	void move(float horizontalRate, float verticalRate);
	void move(float horizontalRate, float verticalRate, bool onlySprintForward);
	void move(float horizontalRate, float verticalRate, bool onlySprintForward, bool sprintHorizontally);
	void updateMovingDirections(float horizontalRate, float verticalRate);
	b2Vec2 getMovementVectors() const;
	bool isMovingForward() const;
	bool isMovingBackward() const;
	bool isMovingLeft() const;
	bool isMovingRight() const;

protected:
	b2Body* body;
	float speed;
	float rotationSpeed;
	float sprintMultiplier;
	b2Vec2 forwardVel, backwardVel, leftVel, rightVel;
	bool m_forward, m_backward, m_left, m_right;
	bool isSprinting;
	void sprintAdjust(b2Vec2& vect);
	float lastHorizontalRate, lastVerticalRate;
	bool wasDirectionalInput;
	int count=0;
};

#endif