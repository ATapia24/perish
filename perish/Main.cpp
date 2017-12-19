#include "GameManager.h"
#include "DrawManager.h"
#include "Miscellaneous.h"
#include <thread>
#include <ctime>
#include <windows.h>
#include <mutex>

int main() {
	//seed for random numbers
	srand((unsigned)time(NULL));

	//initilize window, drawManager, and gameManager
	std::mutex mutex;
	DrawManager drawManager(mutex);
	GameManager gameManager(drawManager, mutex);

	//create and launch drawThread
	std::thread drawThread(&DrawManager::ThreadHandler, &drawManager);
	
	//wait for window to be created
	while(drawManager.getWindow() == NULL){
		Sleep(0);
	}

	//initialize game
	gameManager.initGame();
	drawThread.join();
	
	return 0;
}