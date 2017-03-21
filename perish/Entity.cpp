#include "Entity.h"

Entity::Entity() {

	Location dud(0, 0);
	loc = dud;

	moveable = false;

}

Entity::Entity(Location _loc, bool _moveable) {

	loc = _loc;
	moveable = _moveable;

}

// setters
void Entity::teleport(Location _loc) {

	loc = _loc;

}

// getters
Location Entity::getLocation() const {

	return loc;

}

bool Entity::isMoveable() const {

	return moveable;

}