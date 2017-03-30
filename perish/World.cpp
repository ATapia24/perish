#include "World.h"

World::World(std::string &_name, const int maxX, const int maxY, const int maxFloats) :
	NAME(_name), MAX_X(maxX), MAX_Y(maxY) {

	// fill up the max tiles
	worldTiles = new WorldTile*[maxX];

	// now fill up the innerds!
	for (int i = 0; i < maxX; i++) {
		worldTiles[i] = new WorldTile[maxY];
	}

	// now fill in the max floats
	worldFloats = new WorldFloat[maxFloats];

}

World::~World() {

	// deconstruct the multidimensional array
	for (int x = 0; x < MAX_X; x++) {
		delete[] worldTiles[x];
	}
	delete[] worldTiles;

	delete[] worldFloats;

}

int World::getMaxX() const {
	return MAX_X;
}

int World::getMaxY() const {
	return MAX_Y;
}
