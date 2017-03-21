#include "DrawLayer.h"

DrawLayer::DrawLayer() {

	sprites = new sf::Sprite*[BUFFER_SIZE];
	texts = new sf::Text*[BUFFER_SIZE];
	cshapes = new sf::CircleShape*[BUFFER_SIZE];
	rshapes = new sf::RectangleShape*[BUFFER_SIZE];
	cnshapes = new sf::ConvexShape*[BUFFER_SIZE];

	openSprites = new uint8_t[BUFFER_SIZE];
	openTexts = new uint8_t[BUFFER_SIZE];
	openCircs = new uint8_t[BUFFER_SIZE];
	openRects = new uint8_t[BUFFER_SIZE];
	openConvs = new uint8_t[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++) {

		openSprites[i] = 1;
		openTexts[i] = 1;
		openCircs[i] = 1;
		openRects[i] = 1;
		openConvs[i] = 1;

	}

}


DrawLayer::~DrawLayer() {

	// housekeeping !
	delete[] sprites;
	delete[] texts;
	delete[] cshapes;
	delete[] rshapes;
	delete[] cnshapes;

	delete[] openSprites;
	delete[] openTexts;
	delete[] openCircs;
	delete[] openRects;
	delete[] openConvs;

}

int DrawLayer::getBufferSize() const {

	return BUFFER_SIZE;

}

int DrawLayer::addConvex(sf::ConvexShape *convex) {

	// loop through the openSprites to see the first open section
	for (int i = 0; i < BUFFER_SIZE; i++) {

		if (openConvs[i] == 1) {
			cnshapes[i] = convex;
			openConvs[i] = 0;
			return i;
		}

	}

}

void DrawLayer::deleteConvex(int loc) {

	openConvs[loc] = 1;

}

// Useful getters!
sf::Sprite * DrawLayer::getSprites() const {

	return *sprites;

}

uint8_t * DrawLayer::getSetSprites() const {

	return openSprites;

}

sf::Text * DrawLayer::getTexts() const {

	return *texts;

}

uint8_t * DrawLayer::getSetTexts() const {

	return openTexts;

}

sf::CircleShape * DrawLayer::getCircles() const {

	return *cshapes;

}

uint8_t * DrawLayer::getSetCircles() const {

	return openCircs;

}

sf::RectangleShape * DrawLayer::getRectangles() const {

	return *rshapes;

}

uint8_t * DrawLayer::getsetRectangles() const {

	return openRects;

}

sf::ConvexShape * DrawLayer::getConvexes() const {

	return *cnshapes;

}

uint8_t * DrawLayer::getSetConvexes() const {

	return openConvs;

}

DrawLayer& DrawLayer::operator=(DrawLayer &layer) {

	for (int i = 0; i < BUFFER_SIZE; i++) {

		sprites[i] = layer.sprites[i];
		texts[i] = layer.texts[i];
		cshapes[i] = layer.cshapes[i];
		rshapes[i] = layer.rshapes[i];
		cnshapes[i] = layer.cnshapes[i];

		openSprites[i] = layer.openSprites[i];
		openTexts[i] = layer.openTexts[i];
		openRects[i] = layer.openRects[i];
		openCircs[i] = layer.openCircs[i];
		openConvs[i] = layer.openConvs[i];

	}

	return *this;

}