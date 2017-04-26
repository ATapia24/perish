#include "GameManager.h"
#include "DrawManager.h"
#include "Miscellaneous.h"
#include <thread>
#include <ctime>

int main() {
	//seed for random numbers
	srand((unsigned)time(NULL));

	//initilize window, drawManager, and gameManager
	sf::RenderWindow window(sf::VideoMode(misc::NATIVE_WIDTH/2, misc::NATIVE_HEIGHT/2), misc::GAME_NAME, sf::Style::Titlebar);
	DrawManager drawManager(&window, 20);
	GameManager gameManager(drawManager);

	//create and launch drawThread
	window.setActive(false);
	std::thread drawThread(&DrawManager::ThreadHandler, &drawManager);

	//initialize game
	gameManager.initGame();
	
	return 0;
}