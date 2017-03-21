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
#include "DrawLayer.h"

int main() {

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 500), "Perish");
	DrawManager *manager = new DrawManager(window, 5);

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

	DrawLayer layer;

	int loc = layer.addConvex(&convex);

	manager->addLayer(&layer);

	// layer.deleteConvex(loc);

	// event handler on this end
	while (window->isOpen()) {

		sf::Event event;
		while (window->pollEvent(event)) {


			if (event.type == sf::Event::Closed) {

				window->close();

			}
			else if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::A) {
					
					convex.move(convex.getPosition().x + 1, convex.getPosition().y + 1);

				} else if (event.key.code == sf::Keyboard::D) {

					

				}

			}

		}

	}

	delete manager;
	delete window;

	return 0;
}