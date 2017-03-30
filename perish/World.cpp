#include "World.h"

World::World(std::string &_name, const int maxX, const int maxY, const int maxFloats) :
	NAME(_name), MAX_X(maxX), MAX_Y(maxY), MAX_FLOATS(maxFloats) {

	// fill up the max tiles
	worldTiles = new WorldTile*[maxX];

	// now fill up the innerds!
	for (int i = 0; i < maxX; i++) {
		worldTiles[i] = new WorldTile[maxY];
	}

	// now fill in the max floats
	worldFloats = new WorldFloat[maxFloats];
	openFloats = new uint8_t[maxFloats];

	for (int i = 0; i < maxFloats; i++) {
		openFloats[i] = 1;
	}

}

World::~World() {

	// deconstruct the multidimensional array
	for (int x = 0; x < MAX_X; x++) {
		delete[] worldTiles[x];
	}
	delete[] worldTiles;

	delete[] openFloats;
	delete[] worldFloats;

}

int World::getMaxX() const {
	return MAX_X;
}

int World::getMaxY() const {
	return MAX_Y;
}

void World::setTile(const int x, const int y, sf::Sprite &sprite) {

	worldTiles[x][y] = WorldTile(sprite, x, y);

}

void World::addFloat(sf::Sprite &sprite) {

	for (int i = 0; i < MAX_FLOATS; i++) {

		if (openFloats[i] == 1) {
			worldFloats[i] = WorldFloat(sprite);
			return;
		}

	}

}

WorldTile ** World::getWorldTiles() const {

	return worldTiles;

}

WorldFloat * World::getWorldFloats() const {

	return worldFloats;

}

uint8_t * World::getOpenFloats() const {

	return openFloats;

}