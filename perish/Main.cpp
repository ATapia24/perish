#include "GameManager.h"
#include <ctime>

int main() {
	GameManager game;
	srand((unsigned )time(NULL));
	game.start();
	return 0;
}