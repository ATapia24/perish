#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include "WindowManager.h"
#include "Debug.h"
#include "WindowEventHandler.h"
#include "InputManager.h"
#include "World.h"

class GameManager {
public:
	GameManager();
	~GameManager();
	void start();

private:
	WindowManager* windowManager;
	sf::RenderWindow* window;
	WindowEventHandler* eventHandler;
	Debug* debug;
	World* world;
	void gameLoop();
	bool gameTick();

};

#endif /* GAMEMANAGER_H */