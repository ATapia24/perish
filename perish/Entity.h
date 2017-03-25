/*
 * This class serves as a base for almost every object you can see.
 * It stores a copy of the sprite you pass to it, and it's location. 
 * This class doesn't use any new operators.. so everything will be
 * removed automatically
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
	sf::Sprite sprite;

public:

	// Set up the constructors
	Entity(sf::Sprite&, bool);
	~Entity();

	// Nice getters
	virtual sf::Sprite & getSprite();

	// A setter, too!
	virtual void setSprite(sf::Sprite&);

	// check to see if the sprite is movable or not
	virtual bool isMovable() const;

};

