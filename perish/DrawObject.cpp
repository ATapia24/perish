/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   DrawObject.cpp
* Author: activates
*
* Created on March 13, 2017, 8:54 PM
*/

#include "DrawObject.h"
#include "DrawManager.h"
#include <cstddef>

// Construction
DrawObject::DrawObject(const int loc, const RenderType t, DrawManager *_manager) :
	bufferLoc(loc), type(t), manager(_manager) {}

DrawObject::DrawObject(const DrawObject& orig) {

	bufferLoc = orig.bufferLoc;
	type = orig.type;

}

DrawObject::~DrawObject() {}

// Getters and setters
int DrawObject::getBufferLoc() const {
	return bufferLoc;
}

RenderType DrawObject::getType() const {
	return type;
}

sf::Sprite &DrawObject::getSprite() {

	if (type == RenderType::SPRITE) {

		std::list<sf::Sprite>::iterator iter = manager->getSprites()->begin();
		std::advance(iter, bufferLoc);

		return *iter;
	}
}

sf::Text &DrawObject::getText() {

	if (type == RenderType::TEXT) {

		std::list<sf::Text>::iterator iter = manager->getTexts()->begin();
		std::advance(iter, bufferLoc);

		return *iter;
	}

}

sf::CircleShape &DrawObject::getCircle() {

	if (type == RenderType::CIRCLE) {

		std::list<sf::CircleShape>::iterator iter = manager->getCircles()->begin();
		std::advance(iter, bufferLoc);

		return *iter;

	}

}

sf::RectangleShape &DrawObject::getRectangle() {

	if (type == RenderType::CIRCLE) {

		std::list<sf::RectangleShape>::iterator iter = manager->getRectangles()->begin();
		std::advance(iter, bufferLoc);

		return *iter;

	}

}

sf::ConvexShape &DrawObject::getConvex() {

	if (type == RenderType::CONVEX) {

		std::list<sf::ConvexShape>::iterator iter = manager->getConvexes()->begin();
		std::advance(iter, bufferLoc);

		return *iter;

	}

}

void DrawObject::remove() {

	switch (type) {

	case RenderType::SPRITE: {

		std::list<sf::Sprite>::iterator iter = manager->getSprites()->begin();
		manager->getSprites()->erase(iter);

		break;
	}
	case RenderType::TEXT: {

		std::list<sf::Text>::iterator iter = manager->getTexts()->begin();
		manager->getTexts()->erase(iter);

		break;
	}
	}

}
