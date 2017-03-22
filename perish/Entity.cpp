#include "Entity.h"

Entity::Entity() {

	Location dud(0, 0);
	loc = dud;

	moveable = false;

}

Entity::Entity(Location _loc, bool _moveable, sf::Sprite &_sprite) {

	loc = _loc;
	moveable = _moveable;
	sprite = _sprite;

}

// setters
void Entity::teleport(Location _loc) {

	loc = _loc;

}

void Entity::setSprite(sf::Sprite &_sprite) {

	sprite = _sprite;

}

// getters
Location Entity::getLocation() const {

	return loc;

}

bool Entity::isMoveable() const {

	return moveable;

}

sf::Sprite & Entity::getSprite() {

	return sprite;

}

