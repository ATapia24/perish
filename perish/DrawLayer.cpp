#include "DrawLayer.h"

DrawLayer::DrawLayer() {

	spriteArr = new sf::Sprite*[BUFFER_SIZE];
	textArr = new sf::Text*[BUFFER_SIZE];
	circleArr = new sf::CircleShape*[BUFFER_SIZE];
	rectangleArr = new sf::RectangleShape*[BUFFER_SIZE];
	convexArr = new sf::ConvexShape*[BUFFER_SIZE];

	openSpriteArr = new uint8_t[BUFFER_SIZE];
	openTextArr = new uint8_t[BUFFER_SIZE];
	openCircleArr = new uint8_t[BUFFER_SIZE];
	openRectangleArr = new uint8_t[BUFFER_SIZE];
	openConvexArr = new uint8_t[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++) {

		openSpriteArr[i] = 1;
		openTextArr[i] = 1;
		openCircleArr[i] = 1;
		openRectangleArr[i] = 1;
		openConvexArr[i] = 1;
	}

}


DrawLayer::~DrawLayer() {

	// housekeeping !
	delete[] spriteArr;
	delete[] textArr;
	delete[] circleArr;
	delete[] rectangleArr;
	delete[] convexArr;

	delete[] openSpriteArr;
	delete[] openTextArr;
	delete[] openCircleArr;
	delete[] openRectangleArr;
	delete[] openConvexArr;
}

//ADD SPRITE
int DrawLayer::add(sf::Sprite *sprite) {
	for (int i = 0; i < BUFFER_SIZE; i++)
		if (openSpriteArr[i] == 1) {
			spriteArr[i] = sprite;
			openSpriteArr[i] = 0;
			return i;
		}

	return -1;
}

//ADD RECTANGLE
int DrawLayer::add(sf::RectangleShape *rectangle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
		if (openRectangleArr[i] == 1) {
			rectangleArr[i] = rectangle;
			openRectangleArr[i] = 0;
			return i;
		}

	return -1;
}

//ADD TEXT
int DrawLayer::add(sf::Text *text) {
	for (int i = 0; i < BUFFER_SIZE; i++)
		if (openTextArr[i] == 1) {
			textArr[i] = text;
			openTextArr[i] = 0;
			return i;
		}

	return -1;
}

//ADD CIRCLE
int DrawLayer::add(sf::CircleShape *circle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
		if (openCircleArr[i] == 1) {
			circleArr[i] = circle;
			openCircleArr[i] = 0;
			return i;
		}

	return -1;
}

//ADD CONVEX
int DrawLayer::add(sf::ConvexShape *convex)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
		if (openConvexArr[i] == 1) {
			convexArr[i] = convex;
			openConvexArr[i] = 0;
			return i;
		}

	return -1;
}

void DrawLayer::deleteConvex(int loc) {

	openConvexArr[loc] = 1;

}


DrawLayer& DrawLayer::operator=(DrawLayer &layer) {

	for (int i = 0; i < BUFFER_SIZE; i++) {

		spriteArr[i] = layer.spriteArr[i];
		textArr[i] = layer.textArr[i];
		circleArr[i] = layer.circleArr[i];
		rectangleArr[i] = layer.rectangleArr[i];
		convexArr[i] = layer.convexArr[i];

		openSpriteArr[i] = layer.openSpriteArr[i];
		openTextArr[i] = layer.openTextArr[i];
		openRectangleArr[i] = layer.openRectangleArr[i];
		openCircleArr[i] = layer.openCircleArr[i];
		openConvexArr[i] = layer.openConvexArr[i];

	}

	return *this;
}