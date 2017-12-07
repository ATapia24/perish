#include "DrawManager.h"

//CONSTRUCTOR
DrawManager::DrawManager() {
	windowOpen = false;
	windowCloseReady = false;
	layers = new DrawLayer*[MAX_LAYERS];
	layersUsed = 0;
}

//DECONSTRUCTOR
DrawManager::~DrawManager() {
	delete[] layers;
}

//THREAD HANDLER - DRAW THREAD LOOP
void DrawManager::ThreadHandler() {

	//initialize window
	initWindow();

	fpsTimer.start();

	//draw loop
	while (windowOpen) {

		//draw if polls events doesnt return false
		if (pollEvents()) {
			draw();
			calculateFps();
		}
	}

	windowCloseReady = true;
	window->close();
}

//INITIALIZE WINDOW
void DrawManager::initWindow() { 

	//console window
	consoleWindow = GetConsoleWindow();
	std::string consoleTitle = misc::GAME_NAME + " - Console";
	SetConsoleTitle(TEXT(consoleTitle.c_str()));

	//render window TODO: read video settings from file
	//window = new sf::RenderWindow(sf::VideoMode(misc::NATIVE_WIDTH / 2 , misc::NATIVE_HEIGHT / 2), misc::GAME_NAME, sf::Style::Titlebar);
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), misc::GAME_NAME, sf::Style::Titlebar);
	window->setFramerateLimit(100);
	windowOpen = true;
}

//DRAW
void DrawManager::draw() {

	//clear window
	window->clear(sf::Color::Black);
	//draw objects in layer
	for (unsigned int i = 0; i < layersUsed; i++) {
		//stops looping when every DrawObject has been drawn
		int drawCount = 0;
		window->setView(*layers[i]->getView());
		std::cout << i << ' ' <<layers[i]->getSize() << '\n';
		for (unsigned int j = 0; drawCount < layers[i]->getSize(); j++) {
			switch (layers[i]->getDrawObjects()[j]->type) {
			case DrawType::EMPTY: break; //do nothing
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
				window->draw(*layers[i]->getDrawObjects()[j]->rectangle, layers[i]->getDrawObjects()[j]->shader);
				drawCount++;
				break;
			case DrawType::CIRCLE:
				window->draw(*layers[i]->getDrawObjects()[j]->circle, layers[i]->getDrawObjects()[j]->shader);
				drawCount++;
				break;
			case DrawType::CONVEX:
				window->draw(*layers[i]->getDrawObjects()[j]->convex, layers[i]->getDrawObjects()[j]->shader);
				drawCount++;
				break;
			}
		}

		//std::cout << "test\n";
	}

	//display
	window->display();
}

//POLL EVENTS
//Desc. handles window events and returns false if window was closed
bool DrawManager::pollEvents() {
	
	//handle window events
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			return false;
			break;
		default: //do nothing
			break;
		}
	}

	return true;
}

//RESIZE WINDOW
void DrawManager::resizeWindow(unsigned int width, unsigned int height, bool _fullscreen, bool border) {
	window->setSize(sf::Vector2u(width, height));
	window->setPosition(sf::Vector2i(0, 0));
	MoveWindow(consoleWindow, width + 15, 0, 300, height, true);
}


//ADD LAYER - by pointer
void DrawManager::addLayer(DrawLayer *layer) {

	if (layersUsed < MAX_LAYERS) {

		layers[layersUsed] = layer;
		layers[layersUsed]->getView()->reset((sf::FloatRect(0, 0, (float)window->getSize().x, (float)window->getSize().y)));
		layersUsed++;

	}
	else {

		//layer overflow
		std::cout << "Layer overlow, see DrawManager.cpp - addLayer\n";
		layersUsed = 1;

	}
}

//ADD LAYER - by reference
void DrawManager::addLayer(DrawLayer& layer) {

	if (layersUsed < MAX_LAYERS) {

		layers[layersUsed] = &layer;
		layers[layersUsed]->getView()->reset((sf::FloatRect(0, 0, (float)window->getSize().x, (float)window->getSize().y)));
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

//CALCULATE FPS 
void DrawManager::calculateFps() {
	//calculate fps
	fps = (1000000000.0f / (float)fpsTimer.getNanoseconds());
	fpsTimer.reset();
}

//GET FPS
float DrawManager::getFps() {
	return fps;
}

//CLOSE
void DrawManager::close() {
	windowOpen = false;
}