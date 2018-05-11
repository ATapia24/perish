#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <thread>
#include "Debug.h"
#include "Renderer.h"
#include "DrawBuffer.h"
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
#include "EditorMode.h"

class GameManager {
public:
	GameManager();
	GameManager(Renderer& _renderer);
	~GameManager();
	void initGame();
	void gameLoop();

private:
	Renderer* renderer;
	sf::RenderWindow* window;
	EditorMode* editor;
	std::mutex *drawMutex;

	Debug* debug;
	b2World* physWorld;
	CollisionHandler collisionHandler;
	void updatePhysics();

	const unsigned TICK_RATE = 5;
	float tick_delta, phys_delta;
	Timer gameTickTimer, physTimer, physCalcTimer;
	bool gameTick();
	std::string upsString, fpsString, physString;
	std::string playerCoords, playerRot;
	std::string countStr;

};

#endif /* GAMEMANAGER_H */