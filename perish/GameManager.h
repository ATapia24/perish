#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <thread>
#include "Debug.h"
#include "DrawManager.h"
#include "DrawLayer.h"
#include "InputManager.h"
#include "Menu.h"
#include "Entity.h"
#include "Box2D.h"
#include "Player.h"
#include "Bot.h"
#include "CollisionHandler.h"
#include "Box.h"

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
	b2World* physWorld;
	void gameLoop();

	const unsigned TICK_RATE = 16;
	float tick_delta;
	Timer gameTickTimer;
	bool gameTick();
	std::string upsString, fpsString;
	std::string playerCoords, playerRot;
	std::string countStr;

};

#endif /* GAMEMANAGER_H */