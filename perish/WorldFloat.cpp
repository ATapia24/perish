#include "WorldFloat.h"

WorldFloat::WorldFloat() : WorldObject(sf::Sprite(), WorldObjectType::FLOATING) {}

WorldFloat::WorldFloat(sf::Sprite &_sprite, const float _x, const float _y) :
	WorldObject(_sprite, WorldObjectType::FLOATING), x(_x), y(_y) {}


WorldFloat::~WorldFloat() {}

float WorldFloat::getX() const {
	return x;
}

float WorldFloat::getY() const {
	return y;
}