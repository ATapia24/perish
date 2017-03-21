#pragma once
#pragma once

#include "Location.h"

class Location;

class Entity {

private:

	// store the entities location
	Location loc;
	// store if they are movable or not
	bool moveable;

public:

	// default constructor
	Entity();

	// best constructor! :D
	Entity(Location, bool);

	// setters
	virtual void teleport(Location);

	// getters
	virtual Location getLocation() const;
	virtual bool isMoveable() const;

};

