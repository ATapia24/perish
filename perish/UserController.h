#pragma once

#include <iostream>
#include "Controller.h"
#include "InputManager.h"


class UserController : public Controller
{
public:
	UserController();
	~UserController();
	void load(sf::View* _view, b2Body* _body, float _speed, float _rotationSpeed);
	void update();
private:
	void input();
	sf::View* view;
	Key forwardKey, backwardKey, leftKey, rightKey;
	Key turnLeftKey, turnRightKey;
	Key sprintKey;

};

