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
#include "DrawLayer.h"

#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

// For compiler stuff..
class DrawObject;
class Shape;
class DrawLayer;

class DrawManager {
public:

	// construction etc
	DrawManager(sf::RenderWindow*, const int);
	~DrawManager();

	// Getters and setters
	sf::RenderWindow * getWindow();

	// Layer management
	void addLayer(DrawLayer*);
	void setLayer(int, DrawLayer&);
	DrawLayer * getLayers() const;

	// view management
	void setView(sf::View*);
	sf::View * getView();

	// to be called by the thread
	void threadHandler();

	// Handles all the drawing
	// -- Should be private, but needed for testing
	void draw();

private:

	sf::Clock clock;

	sf::View *view;

	// Holds the drawable layers
	DrawLayer **layers;
	int layersUsed = 0;
	int MAX_LAYERS;

	// The window object
	sf::RenderWindow *window;

	// Settings
	sf::Vector2f scale,
		position;
	float rotation;

};

#endif /* DRAWMANAGER_H */
