#include "GameManager.h"
#include "DrawManager.h"
#include "Miscellaneous.h"
#include <ctime>

int main() {
	//seed for random numbers
	srand((unsigned)time(NULL));

	//initilize window, drawManager, and gameManager
	sf::RenderWindow window(sf::VideoMode(misc::NATIVE_WIDTH/2, misc::NATIVE_HEIGHT/2), misc::GAME_NAME, sf::Style::Titlebar);
	DrawManager drawManager(&window, 500);
	GameManager gameManager(drawManager);

	//create and launch drawThread
	window.setActive(false);
	sf::Thread drawThread(&DrawManager::ThreadHandler, &drawManager);
	drawThread.launch();

	//initialize game
	gameManager.initGame();

	return 0;
}