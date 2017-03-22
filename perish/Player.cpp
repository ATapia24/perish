#include "Player.h"

Player::Player(std::string &_name) {

	name = _name;

}


Player::~Player() {}

std::string Player::getName() const {

	return name;

}