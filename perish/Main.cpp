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
#include "World.h"

// handles window events
void eventHandler(sf::RenderWindow*, sf::Event);
// handles keyboard stuff
void keyboardHandler();

int main() {

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 500), "Perish");
	DrawManager *manager = new DrawManager(window, 5);

	window->setActive(false);

	sf::Thread thread(&DrawManager::threadHandler, manager);

	DrawLayer *myLayer = new DrawLayer();

	// BEGIN WORLD BUILDING

	// Load up the texture
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("C:\\Users\\activates\\Downloads\\terrain.jpg");

	// Create the sprites and assign their textures
	sf::Sprite *grass = new sf::Sprite();
	grass->setTexture(*texture);
	grass->setTextureRect(sf::IntRect(0, 0, 80, 80));

	sf::Sprite *stone = new sf::Sprite();
	stone->setTexture(*texture);
	stone->setTextureRect(sf::IntRect(80, 0, 80, 80));

	sf::Sprite *wood = new sf::Sprite();
	wood->setTexture(*texture);
	wood->setTextureRect(sf::IntRect(320, 0, 80, 80));

	// build a small 5x5 world
	World *world = new World("Test_World", 2, 2);

	world->setTile(0, 0, wood);
	world->setTile(0, 1, stone);
	world->setTile(1, 0, grass);
	world->setTile(1, 1, wood);

	DrawLayer *dud = new DrawLayer();

	world->buildLayer(dud);

	manager->addLayer(dud);

	// END WORLD BUILDING

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

	delete dud;
	delete grass;
	delete stone;
	delete wood;
	delete world;
	delete myLayer;
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