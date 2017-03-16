#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {
	delete windowManager;
	delete eventHandler;
}

void GameManager::start() {
	windowManager = new WindowManager(1280, 720, "Game");
	window = windowManager->getWindow();
	eventHandler = new WindowEventHandler(window);
	debug = new Debug(windowManager);
	world = new World(windowManager);
	world->load();
	gameLoop();
}

sf::Font font;
//GAME LOOP
//main loop for the game. handle events, then go game logic, then draw
void GameManager::gameLoop() {
	sf::Event event;
	font.loadFromFile("font.ttf");
	while (window->isOpen()) {

		//handle events
		while (window->pollEvent(event)) {
			eventHandler->handleEvent(event);
		}

		//happens every tick
		if (gameTick())
		{
			//do game logic here
			debug->update();
			world->update();

			//draw methods here
			debug->draw();
			world->draw();

			//real draw
			windowManager->draw();
		}

	}
}

//GAME TICK
bool GameManager::gameTick() {
	//TODO: I need to add your tick code
	return true;
}


