#include "World.h"

// Default constructor
World::World() : HEIGHT(1), WIDTH(1) {

	name = "Default";

	// instantiate the multidimensional array
	tiles = new WorldTile**[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		tiles[i] = new WorldTile*[WIDTH];
	}

}

// The constructor you should use
World::World(std::string &_name, int height, int width) : 
	HEIGHT(height), WIDTH(width), name(_name) {

	// instantiate the multidimensional array
	tiles = new WorldTile**[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		tiles[i] = new WorldTile*[WIDTH];
	}

}

World::~World() {

	// Delete the multidimensional array
	for (int i = 0; i < HEIGHT; i++) {
		delete[] tiles[i];
	}
	delete[] tiles;

}

// control the tiles
void World::setTile(int height, int width, sf::Sprite *sprite) {

	tiles[height][width]->setSprite(sprite);

}

// get the tiles
WorldTile *** World::getTiles() const {

	return tiles;

}

// get the dimensions
int World::getHeight() const {

	return HEIGHT;

}

int World::getWidth() const {

	return WIDTH;

}