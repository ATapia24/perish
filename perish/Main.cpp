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
#include "Animator.h"

// handles window events
void eventHandler(sf::RenderWindow*, sf::Event);
// handles keyboard stuff
void keyboardHandler(sf::View*, sf::Clock&);

int main() {

	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 500), "Perish");
	DrawManager *manager = new DrawManager(window, 5);

	// for the animator setup to have a max of 10 animations
	Animator animator(10);

	window->setActive(false);

	// sf::Thread thread(&DrawManager::threadHandler, manager);

	DrawLayer *myLayer = new DrawLayer();

	// Create a nice view to see in our world!
	sf::View *view = new sf::View(sf::FloatRect(0, 0, 200, 200));
	view->setSize(80, 50);

	manager->setView(view);

	// BEGIN WORLD BUILDING

	// Load up the texture
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile("C:\\Users\\activates\\Downloads\\terrain.png");
	texture->setSmooth(false);

	// Create the sprites and assign their textures
	sf::Sprite *water = new sf::Sprite();
	water->setTexture(*texture);
	water->setTextureRect(sf::IntRect(416, 384, 32, 32));

	DrawLayer *dud = new DrawLayer();

	World myWorld("World Name", 2, 2);

	myWorld.setTile(0, 0, *water);
	myWorld.setTile(0, 1, *water);

	myWorld.buildLayer(dud, 32, 32);

	manager->addLayer(dud);

	// END WORLD BUILDING

	// BEGIN animation

	// make array of textures

	sf::Texture grassTexture;
	grassTexture.loadFromFile("C:\\Users\\activates\\Downloads\\terrain.png", sf::IntRect(0, 0, 32, 32));

	sf::Texture stoneTexture;
	grassTexture.loadFromFile("C:\\Users\\activates\\Downloads\\terrain.png", sf::IntRect(32, 0, 32, 32));

	sf::Texture woodTexture;
	grassTexture.loadFromFile("C:\\Users\\activates\\Downloads\\terrain.png", sf::IntRect(128, 0, 32, 32));

	sf::IntRect textureSizes[8];

	textureSizes[0] = sf::IntRect(256, 160, 32, 32);
	textureSizes[1] = sf::IntRect(288, 160, 32, 32);
	textureSizes[2] = sf::IntRect(320, 160, 32, 32);
	textureSizes[3] = sf::IntRect(352, 160, 32, 32);
	textureSizes[4] = sf::IntRect(384, 160, 32, 32);
	textureSizes[5] = sf::IntRect(416, 160, 32, 32);
	textureSizes[6] = sf::IntRect(448, 160, 32, 32);
	textureSizes[7] = sf::IntRect(480, 160, 32, 32);

	Animation testAnimation;

	testAnimation.delay = 500;
	testAnimation.lastRan = 0;
	testAnimation.texture = texture;
	testAnimation.rects = textureSizes;
	testAnimation.sprite = &myWorld.getTile(0, 0);
	testAnimation.animations = 8;

	animator.addAnimation(testAnimation);

	Animation testAnimation2;

	testAnimation2.delay = 500;
	testAnimation2.lastRan = 0;
	testAnimation2.texture = texture;
	testAnimation2.rects = textureSizes;
	testAnimation2.sprite = &myWorld.getTile(0, 1);
	testAnimation2.animations = 8;

	animator.addAnimation(testAnimation2);

	// END animation

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

		animator.play();

		manager->draw();

		window->display();

	}

	delete view;
	delete dud;
	delete water;
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

	const int OFFSET = 5;

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