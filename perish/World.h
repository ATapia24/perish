/*

This class is a container for all types that have the WorldObject
as their base class. You can build layers from this or seperate it
into multiple layers for easiness!

*/

#pragma once

#include <string>

#include "WorldObject.h"
#include "WorldTile.h"
#include "WorldFloat.h"

class World {

private:

	// Stores the tiles for the world
	WorldTile **worldTiles;

	// stores the floats for the world
	WorldFloat *worldFloats;
	uint8_t *openFloats;

	// Used to store the max dimensions of the world
	const int MAX_X, MAX_Y;

	// used to keep track of the max floats in the world
	const int MAX_FLOATS;

	// Used to store the world name
	const std::string NAME;

public:

	World(std::string&, const int, const int, const int);
	~World();

	// get the max world dimensions
	int getMaxX() const;
	int getMaxY() const;

	// Used to set a static tile in the map
	void setTile(const int, const int, sf::Sprite&);

	// Used to add a floating tile in the map
	// that doesn't have to snap to a grid
	void addFloat(sf::Sprite&);

	// get the tiles easily
	WorldTile ** getWorldTiles() const;

	// gets the world floats and its speedy counterpart
	WorldFloat * getWorldFloats() const;
	uint8_t * getOpenFloats() const;

};

