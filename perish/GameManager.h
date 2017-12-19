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
#include "LightManager.h"
#include "PerfArray.h"
#include <windows.h>
#include <mutex>

class GameManager {
public:
	GameManager();
	GameManager(DrawManager& _drawManager, std::mutex &_mutex);
	~GameManager();
	void initGame();
	void gameLoop();

private:
	DrawManager* drawManager;
	sf::RenderWindow* window;
	
	Debug* debug;
	b2World* physWorld;
	CollisionHandler collisionHandler;
	void updatePhysics();

	const unsigned TICK_RATE = 8;
	float tick_delta, phys_delta;
	Timer gameTickTimer, physTimer;
	bool gameTick();
	std::string upsString, fpsString;
	std::string playerCoords, playerRot;
	std::string countStr;
	std::mutex* mutex;

};

#endif /* GAMEMANAGER_H */