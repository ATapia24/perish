#include "GameManager.h"

//CONSTRUCTOR
GameManager::GameManager() {
}

//CONSTRUCTOR W/ DRAW MANAGER
GameManager::GameManager(Renderer& _Renderer) {
	renderer = &_Renderer;
	window = renderer->getWindow();
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
	Key quit(XboxButton::BACK, KeyType::REPEATED);
	Key quit1(sf::Keyboard::Escape, KeyType::REPEATED);
	
	sf::View gui;
	DrawBuffer guiLayer(gui);
	Menu menu(guiLayer, 10, 10, 0);
	menu.setSelectedFontColot(sf::Color::White);
	upsString = "UPS : 00";
	fpsString = "FPS : 00";
	menu.add(upsString);
	menu.add(fpsString);
	menu.reshape();
	menu.setUpdateRate(50);

	/*drawMutex->lock();
	//temp
	sf::View camera;
	DrawBuffer layer(camera);
	DrawBuffer floor(camera);

	Player player;
	player.load(&camera, physWorld, layer);
	player.spawn();


	//key binds
	Key up(sf::Keyboard::Up, KeyType::SINGLE), down(sf::Keyboard::Down, KeyType::SINGLE);
	Key zoomIn(sf::Keyboard::Dash, KeyType::REPEATED), zoomOut(sf::Keyboard::Equal, KeyType::REPEATED);
	Key button(XboxButton::A, KeyType::REPEATED);
	Key spawn(sf::Keyboard::Num1, KeyType::REPEATED);
	Key kill(sf::Keyboard::Num2, KeyType::REPEATED);
	Joystick lStick(0);


	renderer->addBuffer(floor);
	renderer->addBuffer(layer);
	renderer->addBuffer(guiLayer);

	gameTickTimer.start();

	physWorld->SetContactListener(&collisionHandler);


	PerfArray<Bot*> arr;
	for (int i = 0; i < 520; i++) {
		arr.add(new Bot());
		arr[i]->load(physWorld, layer);
		arr[i]->getTarget().setTarget(player.getBody());
		arr[i]->setSpawnPoint(b2Vec2((float)misc::random(0, 150), misc::random(0, 150)), 0);
		arr[i]->getTarget().setTarget(player.getBody());
	}

	arr.spawnAll();

	physTimer.start();

	Static w;
	w.load(physWorld, layer);
	w.spawn();

	Timer t;

	drawMutex->unlock();
	*/

	editor = new EditorMode(renderer);
	editor->load();

	renderer->addBuffer(guiLayer);

	//game loop
	gameTickTimer.start();
	while (true) {
		if (quit1.getValue()) {
			renderer->close();
			break;
		}

		//TICK
		if (gameTick()) {
			//drawMutex->lock();
			editor->update();
			menu.update();
			sf::Joystick::update();

			/*
			arr.update();		
			menu.update();
			player.update();
			updatePhysics();

			if (zoomIn.getValue())
				camera.zoom(1.1f);
			else if (zoomOut.getValue())
				camera.zoom(0.9f);

			drawMutex->unlock();*/
		}

	}
	
}

//GAME TICK
bool GameManager::gameTick() {

	upsString = "UPS : " + misc::intToString((int)(1.f / (float)(gameTickTimer.getMilliseconds() / 1000.f)));
	fpsString = "FPS : " + misc::intToString((int)renderer->getFps());

	if (gameTickTimer.getMilliseconds() > TICK_RATE) {
		gameTickTimer.reset();
		return true;
	}

	return false;
}

//UPDATE PHYSICS
void GameManager::updatePhysics() {
	physCalcTimer.start();
	phys_delta = physTimer.getNanoseconds() / 1000000000.f; //nanoseconds to seconds
	physTimer.start();
	physWorld->Step(phys_delta, 8, 3);
	physCalcTimer.stop();
	collisionHandler.update(); //always call after a physics step
	physString = "PCT : " + misc::floatToString(physCalcTimer.getMilliseconds());
	physCalcTimer.reset();
}


