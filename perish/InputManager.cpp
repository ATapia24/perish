#include "InputManager.h"


//CONSTRUCTOR
Key::Key()
{
	cooldownTime = 120;
	controllerNumber = 0;
}

//DESTRUCTOR
Key::~Key()
{
}

//CONSTRUCTOR W/ key setup
Key::Key(sf::Keyboard::Key _key, KeyType _type)
{
	key = _key;
	type = _type;
	isController = false;
}

//CONSTRUCTOR W/ button setup
Key::Key(XboxButton _button, KeyType _type)
{
	button = _button;
	type = _type;
	isController = true;
	controllerNumber = 0;
}

//SET w/ key
void Key::set(sf::Keyboard::Key _key, KeyType _type)
{
	key = _key;
	type = _type;
	isController = false;
}

//SET w/ button
void Key::set(XboxButton _button, KeyType _type)
{
	button = _button;
	type = _type;
	isController = true;
	controllerNumber = 0;
}

//SINGLE CHECK
bool Key::singleCheck()
{
	if (isController) {
		if (sf::Joystick::isButtonPressed(controllerNumber, button) && released)
		{
			released = 0;
			return true;
		}
		else if (!sf::Joystick::isButtonPressed(controllerNumber, button) && !released)
		{
			released = 1;
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(key) && released)
		{
			released = 0;
			return true;
		}
		else if (!sf::Keyboard::isKeyPressed(key) && !released)
		{
			released = 1;
		}

		return false;
	}
}

//REPEATED CHECK
bool Key::repeatedCheck()
{
	if (isController)
		return sf::Joystick::isButtonPressed(controllerNumber, button);

	return sf::Keyboard::isKeyPressed(key);
}

//SINGLE COOLDOWN CHECK
bool Key::singleCooldownCheck()
{
	//controller
	if (isController) {
		if (sf::Joystick::isButtonPressed(controllerNumber, button) && released)
		{
			released = 0;
			cooldownTimer.start();
			return true;
		}
		else if ((!sf::Joystick::isButtonPressed(controllerNumber, button) && !released) || cooldownTimer.getMilliseconds() > cooldownTime)
		{
			released = 1;
		}
	}
	else {

		//key
		if (sf::Keyboard::isKeyPressed(key) && released)
		{
			released = 0;
			cooldownTimer.start();
			return true;
		}
		else if ((!sf::Keyboard::isKeyPressed(key) && !released) || cooldownTimer.getMilliseconds() > cooldownTime)
		{
			released = 1;
		}
	}

	return false;
}

//SET COOLDOWN TIME
void Key::setCooldownTime(const int _cooldownTime)
{
	cooldownTime = _cooldownTime;
}

//GET COOLDOWN TIME
const int Key::getCooldownTime()
{
	return cooldownTime;
}

//GET VALUE
const bool Key::getValue()
{
	switch (type)
	{
	case SINGLE:
		return singleCheck();
		break;
	case REPEATED:
		return repeatedCheck();
		break;
	case SINGLE_COOLDOWN:
		return singleCooldownCheck();
		break;
	default:
		return 0;
	}
}

//JOYSTICK #########################################################################################################################################################################################################

Joystick::Joystick() {
	controllerNumber = 0;
}

Joystick::Joystick(int _stickNumber) {
	stickNumber = _stickNumber;
	controllerNumber = 0;
}

void Joystick::set(int _stickNumber) {
	stickNumber = _stickNumber;
}

//ADJUST VALUE
//desc. map value outside of DEADZONE and within MAX_VALUE and convert to a -1 to 1 scale
float Joystick::adjustValue(float value) {
	//deadzone
	value = value > -DEADZONE && value < DEADZONE ? 0 : (value < 0 ? value += DEADZONE : value -= DEADZONE);

	//max value
	if (value > MAX_VALUE)
		value = MAX_VALUE;
	else if (value < -MAX_VALUE)
		value = -MAX_VALUE;

	//scale
	return value / MAX_VALUE;
}

//LEFT STICK X
float Joystick::leftX() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::X));
}


//LEFT STICK Y
float Joystick::leftY() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::Y));
}


//RIGHT STICK X
float Joystick::rightX() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::U));
}

//RIGHT STICK Y
float Joystick::rightY() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::R));
}

//DPAD X
float Joystick::dPadX() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::PovX));
}

//DPAD Y
float Joystick::dPadY() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::PovY));
}

//LEFT TRIGGER *NOTE: LT and RT axis are combined for some reason, move to xinput?
float Joystick::leftTrigger() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::Z));
}

//RIGHT TRIGGER *NOTE: LT and RT axis are combined for some reason, move to xinput?
float Joystick::rightTrigger() {
	return adjustValue(sf::Joystick::getAxisPosition(controllerNumber, sf::Joystick::Axis::X));
}

//MOUSE #########################################################################################################################################################################################################

//CONSTRUCTOR
Key_M::Key_M()
{
	cooldownTime = 120;
}

//DESTRUCTOR
Key_M::~Key_M()
{
}

//CONSTRUCTOR W/ setup
Key_M::Key_M(short int _key, KeyType _type)
{
	key = _key;
	type = _type;
}

//SET
void Key_M::set(short int _key, KeyType _type)
{
	key = _key;
	type = _type;
}

//SINGLE CHECK
bool Key_M::singleCheck()
{
	if (sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(key)) && released)
	{
		released = 0;
		return true;
	}
	else if (!sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(key)) && !released)
	{
		released = 1;
	}

	return false;
}

//LIVE CHECK
bool Key_M::repeatedCheck()
{
	return (sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(key)));
}

//SINGLE COOLDOWN CHECK
bool Key_M::singleCooldownCheck()
{
	if (sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(key)) && released)
	{
		released = 0;
		cooldownTimer.start();
		return true;
	}
	else if ((!sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(key)) && !released) || cooldownTimer.getMilliseconds() > cooldownTime)
	{
		released = 1;
	}

	return false;
}

//SET COOLDOWN TIME
void Key_M::setCooldownTime(const int _cooldownTime)
{
	cooldownTime = _cooldownTime;
}

//GET COOLDOWN TIME
const int Key_M::getCooldownTime()
{
	return cooldownTime;
}

//GET VALUE
const bool Key_M::getValue()
{
	switch (type)
	{
	case SINGLE:
		return singleCheck();
		break;
	case REPEATED:
		return repeatedCheck();
		break;
	case SINGLE_COOLDOWN:
		return singleCooldownCheck();
		break;
	default:
		return 0;
	}
}