/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: activates
*
* Created on March 13, 2017, 4:45 PM
*/

#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <string>

#include "DrawManager.h"
#include "Shape.h"

int main() {

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 500), "Perish");
	DrawManager *manager = new DrawManager(window, 90, sf::Vector2f(0, 0), sf::Vector2f(0, 0));

	window->setActive(false);

	sf::Thread thread(&DrawManager::threadHandler, manager);

	thread.launch();

	// create an empty shape
	sf::ConvexShape convex;

	// resize it to 5 points
	convex.setPointCount(5);

	// define the points
	convex.setPoint(0, sf::Vector2f(0, 0));
	convex.setPoint(1, sf::Vector2f(150, 10));
	convex.setPoint(2, sf::Vector2f(120, 90));
	convex.setPoint(3, sf::Vector2f(30, 100));
	convex.setPoint(4, sf::Vector2f(0, 50));

	convex.setFillColor(sf::Color(150, 50, 250));

	Shape shape(convex);

	DrawObject shapeObject = manager->addShape(shape);

	shapeObject.getConvex().move(5, 5);

	// event handler on this end
	while (window->isOpen()) {

		sf::Event event;
		while (window->pollEvent(event)) {


			if (event.type == sf::Event::Closed) {

				window->close();

			}

		}

	}

	delete manager;
	delete window;

	return 0;
}