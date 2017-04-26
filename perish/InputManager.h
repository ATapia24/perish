#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>
#include "Timer.h"


enum XboxButton {
	A = 0,
	B = 1,
	X = 2,
	Y = 3,
	LB = 4,
	RB = 5,
	BACK = 6,
	START = 7,
	L3 = 8,
	R3 = 9,
};

enum KeyType {
	SINGLE,
	REPEATED,
	SINGLE_COOLDOWN,
};

class Key {
private:
	sf::Keyboard::Key key;
	KeyType type;
	int controllerNumber;
	XboxButton button;
	bool isController;
	bool released;
	bool singleCheck();
	bool repeatedCheck();
	bool singleCooldownCheck();
	Timer cooldownTimer;
	int cooldownTime;

public:
	Key();
	Key(sf::Keyboard::Key _key, KeyType _type);
	Key(XboxButton _button, KeyType _type);
	~Key();
	void set(sf::Keyboard::Key _key, KeyType _type);
	void set(XboxButton _button, KeyType _type);
	void setCooldownTime(const int _cooldownTime);
	const int getCooldownTime();
	const bool getValue();
};

class Key_M {
private:
	short int key;
	KeyType type;
	bool released;
	bool singleCheck();
	bool repeatedCheck();
	bool singleCooldownCheck();
	Timer cooldownTimer;
	int cooldownTime;

public:
	Key_M();
	Key_M(short int _key, KeyType _type);
	~Key_M();
	void set(short int _key, KeyType _type);
	void setCooldownTime(const int _cooldownTime);
	const int getCooldownTime();
	const bool getValue();
};

class Joystick {
private:
	int stickNumber;
	const float DEADZONE = 15.f;
	const float MAX_VALUE = 70.f;
	int controllerNumber;
	float adjustValue(float value);
public:
	Joystick();
	Joystick(int _stickNumber);
	void set(int _stickNumber);
	float leftX();
	float leftY();
	float rightX();
	float rightY();
	float dPadX();
	float dPadY();
	float leftTrigger();
	float rightTrigger();
	
};

#endif