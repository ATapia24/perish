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
#include "Entity.h"
#include "World.h"

// handles window events
void eventHandler(sf::RenderWindow*, sf::Event);
// handles keyboard stuff
void keyboardHandler(sf::View*, sf::Clock&);

int main() {

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 500), "Perish");
	DrawManager *manager = new DrawManager(window, 5);

	window->setActive(false);

	// sf::Thread thread(&DrawManager::threadHandler, manager);

	DrawLayer *myLayer = new DrawLayer();

	// Create a nice view to see in our world!
	sf::View *view = new sf::View(sf::FloatRect(200, 200, 300, 200));
	view->setSize(800, 600);

	manager->setView(view);

	// BEGIN WORLD BUILDING

	// Load up the texture
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("C:\\Users\\activates\\Downloads\\terrain.png");
	texture->setSmooth(true);

	// Create the sprites and assign their textures
	sf::Sprite *grass = new sf::Sprite();
	grass->setTexture(*texture);
	grass->setTextureRect(sf::IntRect(0, 0, 32, 32));

	sf::Sprite *stone = new sf::Sprite();
	stone->setTexture(*texture);
	stone->setTextureRect(sf::IntRect(80, 0, 32, 32));

	sf::Sprite *wood = new sf::Sprite();
	wood->setTexture(*texture);
	wood->setTextureRect(sf::IntRect(320, 0, 32, 32));

	DrawLayer *dud = new DrawLayer();

	World myWorld("World Name", 100, 100);

	int rand;
	std::srand(NULL);

	for (int h = 0; h < myWorld.getMaxHeight(); h++) {

		for (int w = 0; w < myWorld.getMaxWidth(); w++) {

			std::cout << "h: " << h << " w: " << w << '\n';

			rand = std::rand() % 3 + 1;

			switch (rand) {

			case 1:

				myWorld.setTile(h, w, *grass);

				break;
			case 2:

				myWorld.setTile(h, w, *stone);

				break;
			case 3:

				myWorld.setTile(h, w, *wood);

				break;

			}

		}

	}

	myWorld.buildLayer(dud, 32, 32);

	manager->addLayer(dud);

	// END WORLD BUILDING

	// start the thread
	// thread.launch();

	// Clock for fps timing!
	sf::Clock clock;

	// event handler on this end
	while (window->isOpen()) {

		// Event handling
		sf::Event event;
		while (window->pollEvent(event))
			eventHandler(window, event);

		// handle the keyboard
		keyboardHandler(view, clock);

		manager->setView(view);

		window->clear(sf::Color::Black);

		manager->draw();

		window->display();

	}

	delete view;
	delete dud;
	delete grass;
	delete stone;
	delete wood;
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

void keyboardHandler(sf::View *view, sf::Clock &clock) {

	sf::Time elapsed = clock.getElapsedTime();

	const int OFFSET = 10;

	if (elapsed.asMicroseconds() >= 16666) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			
			view->move(0, -OFFSET);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			view->move(-OFFSET, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			view->move(OFFSET, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			view->move(0, OFFSET);
		}

		clock.restart();

	}

}