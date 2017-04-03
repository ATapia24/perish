/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   DrawManager.cpp
* Author: activates
*
* Created on March 13, 2017, 4:47 PM
*/

#include "DrawManager.h"
#include <iostream>

// Construction
DrawManager::DrawManager(sf::RenderWindow *_window, const int maxLayers) {

	window = _window;

	layers = new DrawLayer*[maxLayers];
	
	for (int i = 0; i < maxLayers; i++) {

		layers[i] = new DrawLayer();

	}
	
	MAX_LAYERS = maxLayers;

	// set video options!
	window->setVerticalSyncEnabled(true);


}

DrawManager::~DrawManager() {

	delete[] layers;

}

sf::RenderWindow * DrawManager::getWindow() {

	return window;

}

void DrawManager::threadHandler() {

	while (window->isOpen()) {

		// clear the screen
		window->clear(sf::Color::Black);

		draw();

		window->display();

	}

}

// Layer management
int DrawManager::addLayer(DrawLayer *layer) {

	int usedLayer;

	if (layersUsed < MAX_LAYERS) {

		usedLayer = layersUsed;

		layers[layersUsed] = layer;
		layersUsed++;

	} else {

		usedLayer = 0;

		// start overwriting layers since they went over
		layers[0] = layer;
		layersUsed = 1;

	}

	return usedLayer;

}

void DrawManager::setLayer(int loc, DrawLayer &layer) {

	layers[loc] = &layer;

}

DrawLayer * DrawManager::getLayers() const {

	return *layers;

}

// view
void DrawManager::setView(sf::View *_view) {

	view = _view;

	window->setView(*view);

}

sf::View * DrawManager::getView() {

	return view;

}

// Private!
void DrawManager::draw() {

	// Limit the framerate manually
	sf::Time elapsed = clock.getElapsedTime();

	/*
	if (clock.getElapsedTime().asMicroseconds() >= 16666)
		clock.restart();
	else
		return;
	*/

	int bufferSize;

	// TODO
	for (int i = 0; i < layersUsed; i++) {
		
		bufferSize = layers[i]->getBufferSize();

		// SPRITES
		for (int sprite = 0; sprite < bufferSize; sprite++) {

			if (layers[i]->getSprites()[sprite] != NULL) {

				window->draw(*layers[i]->getSprites()[sprite]);

			}

		}

		// TEXT
		for (int text = 0; text < bufferSize; text++) {

			if (layers[i]->getTexts()[text] != NULL) {

				window->draw(*layers[i]->getTexts()[text]);

			}

		}

		// CIRCLES
		for (int circle = 0; circle < bufferSize; circle++) {

			if (layers[i]->getCircles()[circle] != NULL) {

				window->draw(*layers[i]->getCircles()[circle]);

			}

		}

		// RECTANGLES
		for (int rectangle = 0; rectangle < bufferSize; rectangle++) {

			if (layers[i]->getRectangles()[rectangle] != NULL) {

				window->draw(*layers[i]->getRectangles()[rectangle]);

			}

		}

		// CONVEXES
		for (int cons = 0; cons < bufferSize; cons++) {

			if (layers[i]->getConvexes()[cons] != NULL) {

				window->draw(*layers[i]->getConvexes()[cons]);

			}

		}

	}
	
}