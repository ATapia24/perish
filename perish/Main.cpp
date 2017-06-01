#include "GameManager.h"
#include "DrawManager.h"
#include "Miscellaneous.h"
#include <thread>
#include <ctime>
#include <windows.h>

int main() {
	//seed for random numbers
	srand((unsigned)time(NULL));

	//initilize window, drawManager, and gameManager
	DrawManager drawManager;
	GameManager gameManager(drawManager);

	//create and launch drawThread
	std::thread drawThread(&DrawManager::ThreadHandler, &drawManager);
	Sleep(200);//wait for window to be created

	//initialize game
	gameManager.initGame();
	
	return 0;
}