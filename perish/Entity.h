#pragma once
#pragma once

#include "Location.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Location;

class Entity {

private:

	// store the entities location
	Location loc;
	// store if they are movable or not
	bool moveable;
	// Holds the sprity goodness
	sf::Sprite sprite;

public:

	// default constructor
	Entity();

	// best constructor! :D
	Entity(Location, bool, sf::Sprite&);

	// setters
	virtual void teleport(Location);
	virtual void setSprite(sf::Sprite&);

	// getters
	virtual Location getLocation() const;
	virtual bool isMoveable() const;
	virtual sf::Sprite & getSprite();

};

