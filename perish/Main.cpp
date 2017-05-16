#include "GameManager.h"
#include "DrawManager.h"
#include "Miscellaneous.h"
#include <thread>
#include <ctime>

int main() {
	//seed for random numbers
	srand((unsigned)time(NULL));

	//initilize window, drawManager, and gameManager
	DrawManager drawManager;
	GameManager gameManager(drawManager);

	//create and launch drawThread
	std::thread drawThread(&DrawManager::ThreadHandler, &drawManager);

	//initialize game
	gameManager.initGame();
	
	return 0;
}