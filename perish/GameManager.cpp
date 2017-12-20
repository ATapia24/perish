#include "GameManager.h"

//CONSTRUCTOR
GameManager::GameManager() {
}

//CONSTRUCTOR W/ DRAW MANAGER
GameManager::GameManager(DrawManager& _drawManager) {
	drawManager = &_drawManager;
	window = drawManager->getWindow();
}

//DECONSTRUCTOR
GameManager::~GameManager() {
}

//INTIALIZE GAME
void GameManager::initGame() {
	//do loading stuff here
	physWorld = new b2World(b2Vec2(0, 0));

	//start game loop
	gameLoop();
}


//GAME LOOP
void GameManager::gameLoop() {

	//****ALL CODE IN HERE TO TEMPORARY AND USED FOR TESTING****

	//temp
	sf::View camera, gui;
	DrawLayer layer(camera);
	DrawLayer guiLayer(gui);
	//DrawLayer floor(camera);

	Player player;
	player.load(&camera, physWorld, layer);
	player.spawn();

	Menu menu(guiLayer, 10, 10, 0);
	menu.setSelectedFontColot(sf::Color::White);
	upsString = "UPS: 00";
	fpsString = "FPS: 00";
	menu.add(upsString);
	menu.add(fpsString);
	menu.reshape();
	menu.setUpdateRate(50);

	//key binds
	Key up(sf::Keyboard::Up, KeyType::SINGLE), down(sf::Keyboard::Down, KeyType::SINGLE);
	Key zoomIn(sf::Keyboard::Dash, KeyType::REPEATED), zoomOut(sf::Keyboard::Equal, KeyType::REPEATED);
	Key button(XboxButton::A, KeyType::REPEATED);
	Key quit(XboxButton::BACK, KeyType::REPEATED);
	Key quit1(sf::Keyboard::Escape, KeyType::REPEATED);
	Key spawn(sf::Keyboard::Num1, KeyType::REPEATED);
	Key kill(sf::Keyboard::Num2, KeyType::REPEATED);
	Joystick lStick(0);

	//sf::Texture texture;
	//texture.loadFromFile("assets/dirty_grass.png");

	//floor
	/*const int x = 3000;
	sf::Sprite** sprite = new sf::Sprite*[x];
	for (int i = 0; i < x; i++) {
		sprite[i] = new sf::Sprite[x];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			sprite[i][j].setPosition(i * 100.f , j * 100.f);
			sprite[i][j].setTexture(texture);
			floor.add(sprite[i][j]);
		}
	}*/

	//drawManager->addLayer(floor);
	drawManager->addLayer(layer);
	drawManager->addLayer(guiLayer);

	gameTickTimer.start();

	physWorld->SetContactListener(&collisionHandler);

	
	PerfArray<Bot*> arr;
	for (int i = 0; i < 3000; i++) {
		arr.add(new Bot());

		arr[i]->load(physWorld, layer);
		arr[i]->getTarget().setTarget(player.getBody());
		arr[i]->setSpawnPoint(b2Vec2((float)misc::random(0, 150), misc::random(0, 150)), 0);
		arr[i]->getTarget().setTarget(player.getBody());
	}
	
	arr.spawnAll();
	physTimer.start();

	//game loop
	while (drawManager->isWindowOpen()) {
		if (quit1.getValue())
			drawManager->close();
		 

		if (gameTick()) {
			//update controller
			if (sf::Joystick::isConnected(0))
				sf::Joystick::update();

			arr.update();		
			menu.update();
			player.update();

			updatePhysics();

			if (zoomIn.getValue())
				camera.zoom(1.1f);
			else if (zoomOut.getValue())
				camera.zoom(0.9f);
		}
	}

	while (!drawManager->isWindowReadyToClose()) {
		Sleep(0);
	}
	
}

//GAME TICK
bool GameManager::gameTick() {

	upsString = "UPS: " + misc::intToString((int)(1.f / (float)(gameTickTimer.getMilliseconds() / 1000.f)));
	fpsString = "FPS: " + misc::intToString((int)drawManager->getFps());

	if (gameTickTimer.getMilliseconds() > TICK_RATE) {
		gameTickTimer.reset();
		return true;
	}

	return false;
}

//UPDATE PHYSICS
void GameManager::updatePhysics() {
	phys_delta = physTimer.getNanoseconds() / 1000000000.f; //nanoseconds to seconds
	physTimer.reset();
	physWorld->Step(phys_delta, 8, 3);
	collisionHandler.update(); //always call after a physics step
}


