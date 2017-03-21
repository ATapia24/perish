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
	MAX_LAYERS = maxLayers;

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
		window->clear(sf::Color::White);

		draw();

		window->display();

	}

}

// Layer management
void DrawManager::addLayer(DrawLayer *layer) {

	if (layersUsed < MAX_LAYERS) {

		layers[layersUsed] = layer;
		layersUsed++;

	} else {

		// start overwriting layers since they went over
		layers[0] = layer;
		layersUsed = 1;

	}
}

void DrawManager::setLayer(int loc, DrawLayer &layer) {

	layers[loc] = &layer;

}

DrawLayer * DrawManager::getLayers() const {

	return *layers;

}

// Private!
void DrawManager::draw() {

	int bufferSize;

	// TODO
	for (int i = 0; i < layersUsed; i++) {
		
		bufferSize = layers[i]->getBufferSize();

		// SPRITES
		for (int sprite = 0; sprite < bufferSize; sprite++) {

			if (layers[i]->getSetSprites()[sprite] == 0) {

				window->draw(layers[i]->getSprites()[sprite]);

			}

		}

		// TEXT
		for (int text = 0; text < bufferSize; text++) {

			if (layers[i]->getSetTexts()[text] == 0) {

				window->draw(layers[i]->getTexts()[text]);

			}

		}

		// CIRCLES
		for (int circle = 0; circle < bufferSize; circle++) {

			if (layers[i]->getSetCircles()[circle] == 0) {

				window->draw(layers[i]->getCircles()[circle]);

			}

		}

		// RECTANGLES
		for (int rectangle = 0; rectangle < bufferSize; rectangle++) {

			if (layers[i]->getsetRectangles()[rectangle] == 0) {

				window->draw(layers[i]->getRectangles()[rectangle]);

			}

		}

		// CONVEXES
		for (int cons = 0; cons < bufferSize; cons++) {

			if (layers[i]->getSetConvexes()[cons] == 0) {

				window->draw(layers[i]->getConvexes()[cons]);

			}

		}

	}
	
}