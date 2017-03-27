#include "GameManager.h"

//CONSTRUCTOR
GameManager::GameManager() {
}

//CONSTRUCTOR W/ DRAW MANAGER
GameManager::GameManager(DrawManager& _drawManager) {
	drawManager = &_drawManager;
	window = drawManager->getWindow();
}

//DECONSTRUCTOR
GameManager::~GameManager() {
}

//INTIALIZE GAME
void GameManager::initGame() {
	//do loading stuff here


	//start game loop
	gameLoop();
}

//GAME LOOP
void GameManager::gameLoop() {

	//temp
	DrawLayer layer;
	const int n = 3500;
	sf::RectangleShape s[n];
	for (int i = 0; i < n; i++)
	{
		s[i].setFillColor(misc::randomColor());
		s[i].setPosition(misc::random(0, 1280), misc::random(0, 720));
		int size = misc::random(0, 10);
		s[i].setSize(sf::Vector2f(20, 20));
		layer.add(&s[i]);
	}

	/*
	for (int i = 0; i < n; i++)
	{
		if (i % misc::random(1, 3) == -3)
			layer.remove(i);
	}

	layer.cleanup();*/


	drawManager->addLayer(&layer);

	//start game tick timer
	gameTickTimer.start();

	while (window->isOpen()) { 
		if (gameTick()) {
		//DO GAME LOGIC HERE

		}
	}
}

//GAME TICK
bool GameManager::gameTick() {
	if (gameTickTimer.getMilliseconds() > TICK_RATE) {
		gameTickTimer.reset();
		return true;
	}

	return false;
}


