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

//CONSTRUCTOR
DrawManager::DrawManager(sf::RenderWindow *_window, const int maxLayers) {

	window = _window;
	layers = new DrawLayer*[maxLayers];
	MAX_LAYERS = maxLayers;
}

//DECONSTRUCTOR
DrawManager::~DrawManager() {

	delete[] layers;

}


//THREAD HANDLER - DRAW THREAD LOOP
void DrawManager::ThreadHandler() {

	//initialize window
	initWindow();

	//draw loop
	while (window->isOpen()) {

		draw();

		//while (fpsTimer.getMilliseconds() <= 16) {}
		//fps = 1000.0f / fpsTimer.getMilliseconds();
		//std::cout << "fps: " << fps << '\n';
		//fpsTimer.reset();
	}

}

//INITIALIZE WINDOW
void DrawManager::initWindow() {

	//console window
	consoleWindow = GetConsoleWindow();
	std::string consoleTitle = misc::GAME_NAME + " - Console";
	SetConsoleTitle(TEXT(consoleTitle.c_str()));

	//render window TODO: read video settings from file
	resizeWindow(1280, 720, false, false);
}

//DRAW
void DrawManager::draw() {
	//clear window
	window->clear(sf::Color::Black);

	int bufferSize;

	// TODO
	for (int i = 0; i < layersUsed; i++) {
		
		bufferSize = layers[i]->getBufferSize();

		// SPRITES
		for (int sprite = 0; sprite < bufferSize; sprite++) {

			if (layers[i]->getOpenSprites()[sprite] == 0) {

				window->draw(layers[i]->getSprites()[sprite]);

			}

		}

		// TEXT
		for (int text = 0; text < bufferSize; text++) {

			if (layers[i]->getOpenTexts()[text] == 0) {

				window->draw(layers[i]->getTexts()[text]);

			}

		}

		// CIRCLES
		for (int circle = 0; circle < bufferSize; circle++) {

			if (layers[i]->getOpenCircles()[circle] == 0) {

				window->draw(layers[i]->getCircles()[circle]);

			}

		}

		// RECTANGLES
		for (int rectangle = 0; rectangle < bufferSize; rectangle++) {

			if (layers[i]->getOpenRectangles()[rectangle] == 0) {

				window->draw(layers[i]->getRectangles()[rectangle]);

			}

		}

		// CONVEXES
		for (int cons = 0; cons < bufferSize; cons++) {

			if (layers[i]->getOpenConvexes()[cons] == 0) {

				window->draw(layers[i]->getConvexes()[cons]);

			}

		}
	}

	//display
	window->display();
}

//RESIZE WINDOW
void DrawManager::resizeWindow(unsigned int width, unsigned int height, bool _fullscreen, bool border) {
	//window->setSize(sf::Vector2u(width, height));
	//window->setPosition(sf::Vector2i(0, 0));
	MoveWindow(consoleWindow, width + 15, 0, 300, height, true);
}


//ADD LAYER
void DrawManager::addLayer(DrawLayer *layer) {

	if (layersUsed < MAX_LAYERS) {

		layers[layersUsed] = layer;
		layersUsed++;

	}
	else {

		//layer overflow
		layers[0] = layer;
		layersUsed = 1;

	}
}

//SET LAYER
void DrawManager::setLayer(int loc, DrawLayer &layer) {

	layers[loc] = &layer;

}