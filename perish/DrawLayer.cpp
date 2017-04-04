#include "DrawLayer.h"

DrawLayer::DrawLayer() {

	sprites = new sf::Sprite*[BUFFER_SIZE];
	texts = new sf::Text*[BUFFER_SIZE];
	cshapes = new sf::CircleShape*[BUFFER_SIZE];
	rshapes = new sf::RectangleShape*[BUFFER_SIZE];
	cnshapes = new sf::ConvexShape*[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++) {

		sprites[i] = NULL;
		texts[i] = NULL;
		cshapes[i] = NULL;
		rshapes[i] = NULL;
		cnshapes[i] = NULL;

	}

}

DrawLayer::~DrawLayer() {

	// housekeeping !
	delete[] sprites;
	delete[] texts;
	delete[] cshapes;
	delete[] rshapes;
	delete[] cnshapes;

}

int DrawLayer::getBufferSize() const {

	return BUFFER_SIZE;

}

int DrawLayer::add(sf::Sprite *sprite) {

	// loop through the openSprites to see the first open section
	for (int i = 0; i < BUFFER_SIZE; i++) {

		if (sprites[i] == NULL) {
			sprites[i] = sprite;
			return i;
		}

	}

}

int DrawLayer::add(sf::Text *text) {

	// loop through the openSprites to see the first open section
	for (int i = 0; i < BUFFER_SIZE; i++) {

		if (texts[i] == NULL) {
			texts[i] = text;
			return i;
		}

	}

}

int DrawLayer::add(sf::CircleShape *circle) {

	// loop through the openSprites to see the first open section
	for (int i = 0; i < BUFFER_SIZE; i++) {

		if (cshapes[i] == NULL) {
			cshapes[i] = circle;
			return i;
		}

	}

}

int DrawLayer::add(sf::RectangleShape *rectangle) {

	// loop through the openSprites to see the first open section
	for (int i = 0; i < BUFFER_SIZE; i++) {

		if (rshapes[i] == NULL) {
			rshapes[i] = rectangle;
			return i;
		}

	}

}

int DrawLayer::add(sf::ConvexShape *convex) {

	// loop through the openSprites to see the first open section
	for (int i = 0; i < BUFFER_SIZE; i++) {

		if (cnshapes[i] == NULL) {
			cnshapes[i] = convex;
			return i;
		}

	}

}

void DrawLayer::deleteSprite(int loc) {

	sprites[loc] = NULL;

}

void DrawLayer::deleteText(int loc) {

	texts[loc] = NULL;

}

void DrawLayer::deleteCircle(int loc) {

	cshapes[loc] = NULL;

}

void DrawLayer::deleteRectangle(int loc) {

	rshapes[loc] = NULL;

}

void DrawLayer::deleteConvex(int loc) {

	cnshapes[loc] = NULL;

}

// Useful getters!
sf::Sprite ** DrawLayer::getSprites() const {

	return sprites;

}

sf::Text ** DrawLayer::getTexts() const {

	return texts;

}

sf::CircleShape ** DrawLayer::getCircles() const {

	return cshapes;

}

sf::RectangleShape ** DrawLayer::getRectangles() const {

	return rshapes;

}

sf::ConvexShape ** DrawLayer::getConvexes() const {

	return cnshapes;

}

DrawLayer& DrawLayer::operator=(DrawLayer &layer) {

	for (int i = 0; i < BUFFER_SIZE; i++) {

		sprites[i] = layer.sprites[i];
		texts[i] = layer.texts[i];
		cshapes[i] = layer.cshapes[i];
		rshapes[i] = layer.rshapes[i];
		cnshapes[i] = layer.cnshapes[i];

	}

	return *this;

}

void DrawLayer::flush() {

	for (int i = 0; i < BUFFER_SIZE; i++) {

		sprites[i] = NULL;
		texts[i] = NULL;
		cshapes[i] = NULL;
		rshapes[i] = NULL;
		cnshapes[i] = NULL;

	}

}