#include "World.h"



World::World(const std::string &_name, const int height, const int width) :
	name(_name), HEIGHT(height), WIDTH(width) {

	// initialize the array
	tiles = new WorldTile**[height];

	for (int i = 0; i < height; i++) {

		tiles[i] = new WorldTile*[width];

	}

	// fill it with values
	for (int h = 0; h < height; h++) {

		for (int w = 0; w < width; w++) {

			tiles[w][h] = new WorldTile();

		}

	}

}

World::~World() {

	// Deconstruct that massive array

	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			delete tiles[w][h];
		}
	}

	for (int h = 0; h < HEIGHT; h++) {
		delete[] tiles[h];
	}
	
	delete[] tiles;

}

int World::getMaxHeight() const {

	return HEIGHT;

}

int World::getMaxWidth() const {

	return WIDTH;

}

void World::setTile(const int x, const int y, sf::Sprite &_sprite) {

	tiles[x][y]->setSprite(_sprite);

}

void World::buildLayer(DrawLayer *layer, const int x, const int y) {

	sf::Sprite *dud;

	// Loop through the sprites and space them out accordingly
	for (int h = 0; h < HEIGHT; h++) {

		for (int w = 0; w < WIDTH; w++) {

			float x1 = x * 0.5;
			float y1 = y * 0.5;
			
			tiles[h][w]->getSprite().scale(0.5f, 0.5f);
			tiles[h][w]->getSprite().move(x1 * h, y1 * w);

			layer->add(&tiles[h][w]->getSprite());

		}

	}

}

sf::Sprite & World::getTile(const int x, const int y) const {

	return tiles[x][y]->getSprite();

}