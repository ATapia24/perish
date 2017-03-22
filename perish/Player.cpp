#include "Player.h"

Player::Player(std::string &_name, Location &_loc, sf::Sprite &_sprite)
	  : Entity(_loc, true, _sprite) {

	name = _name;

}


Player::~Player() {}

std::string Player::getName() const {

	return name;

}