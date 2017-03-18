/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   DrawManager.cpp
* Author: activates
*
* Created on March 13, 2017, 4:47 PM
*/

#include "DrawManager.h"
#include <iostream>

// Construction
DrawManager::DrawManager(sf::RenderWindow *_window, const float _rotation, const sf::Vector2f &_scale, const sf::Vector2f &_pos) {

	window = _window;
	rotation = _rotation;
	scale = _scale;
	position = _pos;

	sprites = new std::list<sf::Sprite>();
	texts = new std::list<sf::Text>();
	cshapes = new std::list<sf::CircleShape>();
	rshapes = new std::list<sf::RectangleShape>();
	cnshapes = new std::list<sf::ConvexShape>();


}

DrawManager::DrawManager(const DrawManager &orig) {}

DrawManager::~DrawManager() {

	delete sprites;
	delete texts;
	delete cshapes;
	delete rshapes;
	delete cnshapes;

}

sf::RenderWindow * DrawManager::getWindow() {

	return window;

}

std::list<sf::Sprite> * DrawManager::getSprites() const {

	return sprites;

}

std::list<sf::Text> * DrawManager::getTexts() const {

	return texts;

}

std::list<sf::CircleShape> * DrawManager::getCircles() const {

	return cshapes;

}

std::list<sf::RectangleShape> * DrawManager::getRectangles() const {

	return rshapes;

}

std::list<sf::ConvexShape> * DrawManager::getConvexes() const {

	return cnshapes;

}

void DrawManager::updateScale(const sf::Vector2f& _scale) {

	scale = _scale;

}

void DrawManager::updatePos(const sf::Vector2f& _pos) {

	position = _pos;

}

void DrawManager::updateRotation(const float _rotation) {

	rotation = _rotation;

}

// ADRIAN STYLE: BUILD SPRITE
DrawObject DrawManager::addSprite(sf::Sprite &sprite) {

	return DrawObject(addToSprites(sprite), RenderType::SPRITE, this);

}

// BUILD TEXT
DrawObject DrawManager::addText(sf::Text &text) {

	return DrawObject(addToTexts(text), RenderType::TEXT, this);

}

// BUILD SHAPES
DrawObject DrawManager::addShape(Shape &shape) {

	switch (shape.getType()) {

	case ShapeType::CIRCLE:

		return DrawObject(addToShapes(shape), RenderType::CIRCLE, this);

		break;

	case ShapeType::RECTANGLE:

		return DrawObject(addToShapes(shape), RenderType::RECTANGLE, this);

		break;

	case ShapeType::CONVEX:

		return DrawObject(addToShapes(shape), RenderType::CONVEX, this);

		break;

	}

}

// Private function
int DrawManager::addToSprites(sf::Sprite &sprite) {

	sprites->push_back(sprite);
	return sprites->size() - 1;

}

// Another private function
int DrawManager::addToTexts(sf::Text &text) {

	texts->push_back(text);
	return texts->size() - 1;

}

int DrawManager::addToShapes(Shape &shape) {

	ShapeType type = shape.getType();

	if (type == ShapeType::CIRCLE) {

		cshapes->push_back(shape.getCircle());
		return cshapes->size() - 1;

	}
	else if (type == ShapeType::RECTANGLE) {

		rshapes->push_back(shape.getRectangle());
		return rshapes->size() - 1;

	}
	else if (type == ShapeType::CONVEX) {

		cnshapes->push_back(shape.getConvex());
		return cnshapes->size() - 1;

	}

}

void DrawManager::threadHandler() {

	while (window->isOpen()) {

		// clear the screen
		window->clear(sf::Color::White);

		draw();

		window->display();

	}

}

// Private!
void DrawManager::draw() {

	// Draw sprites first
	for (auto it = sprites->begin(); it != sprites->end(); it++) {
		window->draw(*it);
	}

	// Now draw text
	for (auto it = texts->begin(); it != texts->end(); it++) {
		window->draw(*it);
	}

	// Next up is circles
	for (auto it = cshapes->begin(); it != cshapes->end(); it++) {
		window->draw(*it);
	}

	// Rectangles baby
	for (auto it = rshapes->begin(); it != rshapes->end(); it++) {
		window->draw(*it);
	}

	// Finally convexes
	for (auto it = cnshapes->begin(); it != cnshapes->end(); it++) {
		window->draw(*it);
	}

}