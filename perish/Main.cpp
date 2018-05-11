#include "GameManager.h"
#include "Renderer.h"
#include "Miscellaneous.h"
#include <thread>
#include <ctime>
#include <windows.h>
#include <mutex>

int main() {
	//seed for random numbers
	srand((unsigned)time(NULL));
	drawMutex = new std::mutex();

	//initilize window, Renderer, and gameManager
	Renderer renderer;
	GameManager gameManager(renderer);

	//create and launch drawThread
	std::thread drawThread(&Renderer::threadHandler, std::ref(renderer));
	
	//wait for window to be created
	while(renderer.getWindow() == NULL){
		Sleep(0);
	}

	//initialize game
	gameManager.initGame();
	drawThread.join();
	
	return 0;
}