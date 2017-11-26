#ifndef USERCONTROLLER_H
#define USERCONTROLLER_h

#include <iostream>
#include "Controller.h"
#include "InputManager.h"


class UserController : public Controller
{
public:
	UserController();
	~UserController();
	void load(sf::View* _view, b2Body* _body, float _speed, float _rotationSpeed);
private:
	void input();
	sf::View* view;
	Joystick joystick;
	Key forwardKey, backwardKey, leftKey, rightKey;
	Key turnLeftKey, turnRightKey;
	Key sprintKey1;
	Key sprintKey2;

};

#endif