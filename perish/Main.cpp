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

// handles window events
void eventHandler(sf::RenderWindow*, sf::Event);
// handles keyboard stuff
void keyboardHandler();

int main() {

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 500), "Perish");
	DrawManager *manager = new DrawManager(window, 5);

	window->setActive(false);

	sf::Thread thread(&DrawManager::threadHandler, manager);

	// create an empty shape
	sf::ConvexShape *convex = new sf::ConvexShape();

	// resize it to 5 points
	convex->setPointCount(5);

	// define the points
	convex->setPoint(0, sf::Vector2f(0, 0));
	convex->setPoint(1, sf::Vector2f(150, 10));
	convex->setPoint(2, sf::Vector2f(120, 90));
	convex->setPoint(3, sf::Vector2f(30, 100));
	convex->setPoint(4, sf::Vector2f(0, 50));

	convex->setFillColor(sf::Color(150, 50, 250));

	DrawLayer *layer = new DrawLayer();

	int loc = layer->addConvex(convex);

	manager->addLayer(layer);

	thread.launch();

	// event handler on this end
	while (window->isOpen()) {

		// Event handling
		sf::Event event;
		while (window->pollEvent(event))
			eventHandler(window, event);

		// handle the keyboard
		keyboardHandler();

	}

	delete layer;
	delete convex;
	delete manager;
	delete window;

	return 0;
}

void eventHandler(sf::RenderWindow *window, sf::Event event) {

	if (event.type == sf::Event::Closed) {

		window->close();

	}
	else if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::A) {


		}
		else if (event.key.code == sf::Keyboard::D) {

		}

	}

}

void keyboardHandler() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		std::cout << "A has been pressed!\n";

	}

}