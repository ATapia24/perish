#include "WorldFloat.h"

WorldFloat::WorldFloat() : WorldObject(sf::Sprite(), WorldObjectType::FLOATING) {}

WorldFloat::WorldFloat(sf::Sprite &_sprite) :
	WorldObject(_sprite, WorldObjectType::FLOATING) {}


WorldFloat::~WorldFloat() {}

float WorldFloat::getX() const {
	return x;
}

float WorldFloat::getY() const {
	return y;
}