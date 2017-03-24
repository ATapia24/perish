#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include "WindowManager.h"
#include "Debug.h"
#include "DrawManager.h"
#include "DrawLayer.h"
#include "WindowEventHandler.h"
#include "DrawManager.h"
#include "InputManager.h"
#include "World.h"

class GameManager {
public:
	GameManager();
	GameManager(DrawManager& _drawManager);
	~GameManager();
	void initGame();

private:
	DrawManager* drawManager;
	sf::RenderWindow* window;
	
	Debug* debug;
	World* world;
	void gameLoop();

	const unsigned TICK_RATE = 8;
	Timer gameTickTimer;
	bool gameTick();

};

#endif /* GAMEMANAGER_H */