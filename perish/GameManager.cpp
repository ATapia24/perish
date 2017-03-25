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
	sf::RectangleShape r;
	r.setFillColor(misc::randomColor());
	r.setPosition(0, 0);
	r.setSize(sf::Vector2f(10, misc::NATIVE_HEIGHT/2));
	layer.add(&r);

	sf::RectangleShape r1;
	r1.setFillColor(misc::randomColor());
	r1.setPosition(10, 10);
	r1.setSize(sf::Vector2f(100, 100));

	layer.add(&r1);
	drawManager->addLayer(&layer);

	//start game tick timer
	gameTickTimer.start();

	while (window->isOpen()) { 
		if (gameTick()) {
		//DO GAME LOGIC HERE

			//temp
			r.move(10.f, 5.0f);
			if (r.getPosition().x > window->getSize().x + r.getSize().x) {
				r.setFillColor(misc::randomColor());
				r.setPosition(0, 0);
			}

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


