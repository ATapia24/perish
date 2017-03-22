#pragma once

#include <SFML/Graphics.hpp>
#include "WorldTile.h"
#include "DrawLayer.h"
#include <string>

class World {

private:

	// A nice multidimensional array to hold the world's goodness
	/*
	 * It has 3 pointers because it is a 2 dimensional array that holds memory addreses!
	 * (the more you know)
	 */
	WorldTile ***tiles;

	// Holds the world's dimensions
	const int MAX_HEIGHT, MAX_WIDTH;
	const std::string WORLD_NAME;

	// A blank sprite for filling empty tiles
	WorldTile *dud;

	// Used for completely resetting the current world
	void flushTiles();

public:

	// Constructors!
	World(const int, const int, const std::string&);
	~World();

	// Get world dimensions
	int getHeight() const;
	int getWidth() const;

	// used for setting tiles
	void setTile(int, int, WorldTile*);

	// layout the tiles in a nice manner, so they can be easily
	// printed
	void layoutTiles();

	// Builds a nice layer for ya!
	void buildLayer(DrawLayer*);

};

