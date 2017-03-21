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

	// TODO
	for (int i = 0; i < layersUsed; i++) {

		for (int cons = 0; cons < layers[i]->getBufferSize(); i++) {

			if (layers[i]->getSetConvexes()[cons] == 0) {

				window->draw(layers[i]->getConvexes()[cons]);

			}

		}

	}

}