/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   DrawObject.h
* Author: activates
*
* Created on March 13, 2017, 8:54 PM
*/

#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include <cstddef>
#include <SFML/Graphics.hpp>
#include "DrawManager.h"

enum class RenderType {
	SPRITE,
	TEXT,
	CIRCLE,
	RECTANGLE,
	CONVEX
};

class DrawManager;

class DrawObject {
public:

	// Constructors
	DrawObject(const int, const RenderType, DrawManager*);
	DrawObject(const DrawObject& orig);
	~DrawObject();

	// Getters and setters
	int getBufferLoc() const;
	RenderType getType() const;

	// Get different object types
	sf::Sprite &getSprite();
	sf::Text &getText();
	sf::CircleShape &getCircle();
	sf::RectangleShape &getRectangle();
	sf::ConvexShape &getConvex();

	// For removal
	void remove();

private:

	int bufferLoc;
	RenderType type;
	DrawManager *manager;

};

#endif /* DRAWOBJECT_H */