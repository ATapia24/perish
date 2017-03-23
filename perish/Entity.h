/*
 * This class serves as a base for almost every object you can see.
 * It stores a pointer to its sprite, and it's location. This class
 * doesn't deconstruct any items, so the sprite that you pass to it,
 * must be deleted elsewhere.
 */

#pragma once

#include <SFML/Graphics.hpp>

class Entity {

protected:

	// Does the entity need to move?
	bool movable;

	/*
	 * This item is more powerful than it looks! We can just return
	 * a non constant pointer of the sprite because it already has
	 * functions for locations, scale, and rotation!
	 */
	sf::Sprite *sprite;

public:

	// Set up the constructors
	Entity(sf::Sprite*, bool);
	~Entity();

	// Nice getters
	virtual sf::Sprite * getSprite();

	// A setter, too!
	virtual void setSprite(sf::Sprite*);

	// check to see if the sprite is movable or not
	virtual bool isMovable() const;

};

