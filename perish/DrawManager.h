/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   DrawManager.h
* Author: activates
*
* Created on March 13, 2017, 4:47 PM
*/

#include <SFML/Graphics.hpp>
#include <list>
#include "DrawObject.h"
#include "Shape.h"

#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

// For compiler stuff..
class DrawObject;
class Shape;

class DrawManager {
public:

	// construction etc
	DrawManager(sf::RenderWindow *_window, const float _rotation, const sf::Vector2f &_scale, const sf::Vector2f &_pos);
	DrawManager(const DrawManager& orig);
	~DrawManager();

	// Getters and setters
	sf::RenderWindow * getWindow();
	std::list<sf::Sprite> * getSprites() const;
	std::list<sf::Text> * getTexts() const;
	std::list<sf::CircleShape> * getCircles() const;
	std::list<sf::RectangleShape> * getRectangles() const;
	std::list<sf::ConvexShape> * getConvexes() const;

	void updateScale(const sf::Vector2f &_scale);
	void updatePos(const sf::Vector2f &_pos);
	void updateRotation(const float _rotation);

	// Add items
	DrawObject addSprite(sf::Sprite&);
	DrawObject addText(sf::Text&);
	DrawObject addShape(Shape&);

	// to be called by the thread
	void threadHandler();

private:

	// The window object
	sf::RenderWindow *window;

	// Arrays of all items to be drawn
	std::list<sf::Sprite> *sprites;
	std::list<sf::Text> *texts;
	std::list<sf::CircleShape> *cshapes;
	std::list<sf::RectangleShape> *rshapes;
	std::list<sf::ConvexShape> *cnshapes;

	// Settings
	sf::Vector2f scale,
		position;
	float rotation;

	int addToSprites(sf::Sprite&);
	int addToTexts(sf::Text&);
	int addToShapes(Shape&);

	// Handles all the drawing
	void draw();

};

#endif /* DRAWMANAGER_H */
