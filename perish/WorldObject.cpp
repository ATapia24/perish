#include "WorldObject.h"

WorldObject::WorldObject(sf::Sprite &_sprite, WorldObjectType _type) {
	sprite = _sprite;
	type = _type;
}

// No need for the deconstructor, yet
WorldObject::~WorldObject() {}

sf::Sprite & WorldObject::getSprite() {
	return sprite;
}

WorldObjectType WorldObject::getType() const {
	return type;
}