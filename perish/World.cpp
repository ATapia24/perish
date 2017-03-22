#include "World.h"



World::World(const int height, const int width, const std::string &name) 
	 : MAX_HEIGHT(height), MAX_WIDTH(width) {

	tiles = new WorldTile**[height];

	// now to populate the rest of the array!
	for (int i = 0; i < height; i++) {

		tiles[i] = new WorldTile*[width];

	}

	// create the dud sprite
	dud = new WorldTile;

}


World::~World() {

	// deconstruct the multidimensional array
	for (int i = 0; i < MAX_HEIGHT; i++) {

		delete[] tiles[i];

	}

	delete[] tiles;
	delete dud;

}

// Get world dimensions
int World::getHeight() const {

	return MAX_HEIGHT;

}

int World::getWidth() const {

	return MAX_WIDTH;

}

// A private function used for flushing filling/flushing the world
// with blank tiles
void World::flushTiles() {

	// create one dynamic sprite for them all to point too

	for (int height = 0; height < MAX_HEIGHT; height++) {

		for (int width = 0; width < MAX_WIDTH; width++) {

			tiles[height][width] = dud;

		}

	}

}

// Used for setting tiles
void World::setTile(int height, int width, WorldTile *tile) {

	if (height < MAX_HEIGHT && width < MAX_HEIGHT)
		tiles[height][width] = tile;

}

// Lays out the tiles in a nice manner
void World::layoutTiles() {

	const float WIDTH = 0.1,
		HEIGHT = 0.1;

	Location tempLoc;

	for (int h = 0; h < MAX_HEIGHT; h++) {

		for (int w = 0; w < MAX_WIDTH; w++) {

			tiles[h][w]->getTile()->setScale(HEIGHT, WIDTH);

			tiles[h][w]->getLocation().setLocation(h + HEIGHT, w + WIDTH);

			tempLoc = tiles[h][w]->getLocation();

			tiles[h][w]->getTile()->setPosition(tempLoc.getX(), tempLoc.getY());

		}

	}

}

// Builds the layer for ya, so it can be easily printed
void World::buildLayer(DrawLayer *layer) {

	WorldTile tempTile;
	sf::Sprite tempSprite;

	// loop through the multidimensional array and print everything out
	for (int h = 0; h < MAX_HEIGHT; h++) {

		for (int w = 0; w < MAX_WIDTH; w++) {

			// store the tile in our temp variable
			layer->add(tiles[h][w]->getTile());

		}

	}

}