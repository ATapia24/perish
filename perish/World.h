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

	const int DIM_X, DIM_Y;

	// Used to store the world name
	const std::string NAME;

public:

	World(const std::string&, const int, const int, const int, const int, const int);
	~World();

	// get the max world dimensions
	int getMaxX() const;
	int getMaxY() const;

	// For fetching the tile dimensions
	int getDimX() const;
	int getDimY() const;

	// Used to set a static tile in the map
	void setTile(const int, const int, sf::Sprite&);

	// get the maximum amount of world floats
	int getMaxFloats() const;

	// Used to add a floating tile in the map
	// that doesn't have to snap to a grid
	void addFloat(sf::Sprite&);

	// get the tiles easily
	WorldTile ** getWorldTiles() const;

	// gets the world floats and its speedy counterpart
	WorldFloat * getWorldFloats() const;
	uint8_t * getOpenFloats() const;

	// Used to get the world name
	std::string getName() const;

	// Should explain itself.. Really. For those of you who
	// haven't messed with operator overloading, I'm basically
	// setting this class up so I can do:

	/*
	
	World world1;
	World world2;

	world1 = world2;
	
	*/

	World operator=(const World&);

};

