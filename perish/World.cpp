#include <iostream>

#include "World.h"

// Default constructor
World::World() : HEIGHT(1), WIDTH(1) {

	name = "Default";

	// instantiate the multidimensional array
	tiles = new WorldTile**[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		tiles[i] = new WorldTile*[WIDTH];
	}

	for (int i = 0; i < HEIGHT; i++) {
		tiles[i] = new WorldTile*[WIDTH];
	}

	// instantiate the every, for JIC moments
	for (int h = 0; h < HEIGHT; h++) {

		for (int w = 0; w < WIDTH; w++) {

			tiles[h][w] = new WorldTile();

		}

	}

}

// The constructor you should use
World::World(const std::string &_name, const int height, const int width) : 
	HEIGHT(height), WIDTH(width), name(_name) {

	// instantiate the multidimensional array
	tiles = new WorldTile**[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		tiles[i] = new WorldTile*[WIDTH];
	}

	// instantiate the every, for JIC moments
	for (int h = 0; h < HEIGHT; h++) {

		for (int w = 0; w < WIDTH; w++) {

			tiles[h][w] = new WorldTile();

		}

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

// Builds a nice layer to be printed
void World::buildLayer(DrawLayer *layer) {

	/*
	 * At this point, we hope all the sprites are of the same
	 * square size.. or there will be unhappiness
	 */

	// For easiness of storing scale
	int x, y;

	// loop through each tile one at a time
	for (int h = 0; h < HEIGHT; h++) {

		for (int w = 0; w < WIDTH; w++) {

			// position the sprite accordingly, then pass it too
			// the layer

			x = tiles[h][w]->getSprite()->getScale().x;
			y = tiles[h][w]->getSprite()->getScale().y;

			// position
			tiles[h][w]->getSprite()->move(x * (h + 1), y * (w + 1));

			// add to the layer
			layer->add(tiles[h][w]->getSprite());

		}

	}

}