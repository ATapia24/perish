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
	long count=0;
	unsigned long sum=0;
	float avg=0;

	//draw loop
	fpsTimer.start();
	while (window->isOpen()) {

		draw();

		//limit fps
		while (fpsTimer.getMilliseconds() <= 15) {}
	//	std::cout << "ms: " << fpsTimer.getMilliseconds() << '\n';
		fpsTimer.reset();


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

	//draw objects in layer
	for (int i = 0; i < layersUsed; i++) {
		
		
		//stops looping when every DrawObject has been drawn
		int drawCount = 0;
		window->setView(*layers[i]->getView());

		for (int j = 0; layers[i]->getSize() != drawCount; j++) {
			//draw based on type
			switch (layers[i]->getDrawObjects()[j]->type) {
			case DrawType::EMPTY: break; // do nothing
			case DrawType::SPRITE:
				window->draw(*layers[i]->getDrawObjects()[j]->sprite);
				drawCount++;
				break;
			case DrawType::VERTEX_ARRAY:
				window->draw(*layers[i]->getDrawObjects()[j]->vertexArray);
				drawCount++;
				break;
			case DrawType::TEXT:
				window->draw(*layers[i]->getDrawObjects()[j]->text);
				drawCount++;
				break;
			case DrawType::RECTANGLE:
				window->draw(*layers[i]->getDrawObjects()[j]->rectangle);
				drawCount++;
				break;
			case DrawType::CIRCLE:
				window->draw(*layers[i]->getDrawObjects()[j]->circle);
				drawCount++;
				break;
			case DrawType::CONVEX:
				window->draw(*layers[i]->getDrawObjects()[j]->convex);
				drawCount++;
				break;
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


//ADD LAYER - by pointer
void DrawManager::addLayer(DrawLayer *layer) {

	if (layersUsed < MAX_LAYERS) {

		layers[layersUsed] = layer;
		layers[layersUsed]->getView()->reset((sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
		layersUsed++;

	}
	else {

		//layer overflow
		std::cout << "Layer overlow, see DrawManager.cpp - addLayer\n";
		layers[0] = layer;
		layersUsed = 1;

	}
}

//ADD LAYER - by reference
void DrawManager::addLayer(DrawLayer& layer) {

	if (layersUsed < MAX_LAYERS) {

		layers[layersUsed] = &layer;
		layers[layersUsed]->getView()->reset((sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));
		layersUsed++;

	}
	else {

		//layer overflow
		std::cout << "Layer overlow, see DrawManager.cpp - addLayer\n";
		layers[0] = &layer;
		layersUsed = 1;

	}
}

//SET LAYER
void DrawManager::setLayer(int loc, DrawLayer &layer) {
	layers[loc] = &layer;
}