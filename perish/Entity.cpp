#include "Entity.h"



Entity::Entity(sf::Sprite* _sprite, bool shouldMove) {

	sprite = _sprite;
	movable = shouldMove;

}


Entity::~Entity() {
	/*
	 * Nothing will be deleted here.. you must delete the sprites elsewhere
	 */
}

sf::Sprite * Entity::getSprite() {

	return sprite;

}

void Entity::setSprite(sf::Sprite *_sprite) {

	sprite = _sprite;

}

bool Entity::isMovable() const {

	return movable;

}