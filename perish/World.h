/*
 * This class holds all the world tiles in a multidimensional array,
 * so it can be easily rendered. The idea is to build the world first,
 * then pass it to a class that can interperet it and render it using
 * the DrawManager class
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "WorldTile.h"
#include "DrawLayer.h"

class World {

private:

	// name of the world
	std::string name;

	// holds the dimensions of the world
	const int WIDTH, HEIGHT;

	// A nice array of world tiles!
	WorldTile*** tiles;

public:

	// Constructors
	World();
	World(const std::string&, const int, const int);
	~World();

	// set tile by tile to build the world
	void setTile(int, int, sf::Sprite*);

	// get each tile for printing
	WorldTile *** getTiles() const;

	// Get world dimensions
	int getHeight() const;
	int getWidth() const;

	// Used to build a layer
	void buildLayer(DrawLayer*);

};