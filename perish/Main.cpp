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

	sf::Sprite *dirtSprite = new sf::Sprite();
	sf::Texture *dirtTexture = new sf::Texture();
	dirtTexture->loadFromFile("C:\\Users\\activates\\Downloads\\dirtblock.png");
	dirtSprite->setTexture(*dirtTexture);

	DrawLayer *layer1 = new DrawLayer();

	layer1->add(dirtSprite);

	sf::Sprite *stoneSprite = new sf::Sprite();
	sf::Texture *stoneTexture = new sf::Texture();
	stoneTexture->loadFromFile("C:\\Users\\activates\\Downloads\\stoneblock.jpg");
	stoneSprite->setTexture(*stoneTexture);

	DrawLayer *layer2 = new DrawLayer();

	layer2->add(stoneSprite);

	// you can edit sprites after you have added them.. pointers are rad!
	//stoneSprite->scale(sf::Vector2f(0.1, 0.1));
	stoneSprite->move(173 * 0.1, 0);

	// Which way you add layers depends! The last gets printed first.
	manager->addLayer(layer2);
	manager->addLayer(layer1);

	dirtSprite->scale(sf::Vector2f(0.1, 0.1));
	dirtSprite->move(sf::Vector2f(0, 0));

	// start the thread
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

	delete layer1;
	delete layer2;
	delete stoneSprite;
	delete stoneTexture;
	delete dirtSprite;
	delete dirtTexture;
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