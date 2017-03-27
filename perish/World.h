/* 
 * This class holds an array of pointers to a bunch of world tiles.
 * The world tiles can be easily converted into a layer of niceness!
 */

#pragma once

#include <string>

#include "WorldTile.h"
#include "DrawLayer.h"

class World {

private:

	// Holds the world tiles in a 2D array
	WorldTile *** tiles;

	// Holds the world's dimensions
	const int HEIGHT, WIDTH;
	
	// Holds the world's name
	const std::string name;

public:

	// Beautiful construction
	World(const std::string&, const int, const int);
	~World();

	// Used to get the world's dimensions
	int getMaxHeight() const;
	int getMaxWidth() const;

	// Used to set invidual tiles
	void setTile(const int, const int, sf::Sprite&);

	// Builds a layer for easy use
	void buildLayer(DrawLayer*, const int, const int);

	// A nice getter for debugging
	sf::Sprite & getTile(const int, const int) const;

};

