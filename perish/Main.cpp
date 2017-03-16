#include "GameManager.h"
#include <ctime>

int main() {
	GameManager game;
	srand(time(NULL));
	game.start();
	return 0;
}