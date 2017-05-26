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

	//temp
	sf::View camera, gui;
	DrawLayer layer(camera), guiLayer(gui), floor(camera);
	
	sf::RenderTexture nightText;
	nightText.create(1920, 1080, true);
	nightText.clear(sf::Color(0, 0, 0, 255));
	nightText.display();
	sf::Sprite night;
	night.setTexture(nightText.getTexture());

	LightManager lm;

	Player player;
	lm.set(&layer, &player);
	player.load(&camera, physWorld, layer);
	player.spawn();

	const int b = 100000;
	Bot* boxes = new Bot[b];

	for (int i = 0; i < b; i++) {
	//	boxes[i].load(physWorld, layer);
	}

	Key spawn (sf::Keyboard::Num1, KeyType::REPEATED);
	Key kill(sf::Keyboard::Num2, KeyType::REPEATED);
	Menu menu(guiLayer, 10, 10, 0);
	menu.setSelectedFontColot(sf::Color::White);
	upsString = "UPS: 00";
	fpsString = "FPS: 00";
	playerCoords = "Player x: 0000 y: 00000";
	playerRot = "Player angle: 00.0";
	countStr = "count: 00000";
	menu.add(upsString);
	menu.add(fpsString);
	menu.add(playerCoords);
	menu.add(playerRot);
	menu.addLiteral("hit \'tab\' to spawn a box");
	menu.add(countStr);
	menu.reshape();
	menu.setUpdateRate(50);

	Key up(sf::Keyboard::Up, KeyType::SINGLE), down(sf::Keyboard::Down, KeyType::SINGLE);
	Key zoomIn(sf::Keyboard::Dash, KeyType::REPEATED), zoomOut(sf::Keyboard::Equal, KeyType::REPEATED);
	sf::Texture texture;
	texture.loadFromFile("assets/dirty_grass.png");

	const int x = 10;
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
	}

	drawManager->addLayer(floor);
	drawManager->addLayer(layer);
	drawManager->addLayer(guiLayer);

	gameTickTimer.start();
	int count = 0;
	int sOffset = 0;

	CollisionHandler collisionHandler;
	physWorld->SetContactListener(&collisionHandler);
	Key button(XboxButton::A, KeyType::REPEATED);
	Key quit(XboxButton::BACK, KeyType::REPEATED);
	Key quit1(sf::Keyboard::Escape, KeyType::REPEATED);
	Joystick lStick(0);

	Timer clk;
	clk.start();

	PerfArray<Bot*> arr;
	for (int i = 0; i < 10; i++) {
		arr.add(new Bot());

		arr[i]->load(physWorld, layer);
		arr[i]->getTarget().setTarget(player.getBody());
		if(i % 2)
			arr[i]->setSpawnPoint(b2Vec2(i, 6), 0);
		else
			arr[i]->setSpawnPoint(b2Vec2(i-1, 5), 0);

		arr[i]->spawn();
		lm.addObject(arr[i]);
	}

	//layer.add(night, sf::BlendAdd);

	while (drawManager->isWindowOpen()) {
		if (quit1.getValue())
			drawManager->close();

		if (gameTick()) {
			//update active controller
			if (sf::Joystick::isConnected(0))
				sf::Joystick::update();


			arr.update();
			lm.update();


			if (kill.getValue())
				arr.killAll();
			else if (spawn.getValue())
				arr.spawnAll();

			menu.update();
			player.update();
			playerCoords = "Player x: " + misc::intToString((int)player.getPosition().x) + " y: " + misc::intToString((int)player.getPosition().y);
			playerRot = "Player rot: " + misc::intToString((int)player.getBody()->GetAngle() * misc::RAD2DEG);
			countStr = "count: " + misc::intToString(count);
			physWorld->Step(1.0f / 60.f, 8, 3);
			collisionHandler.update(); //always call after a physics step

			if (zoomIn.getValue())
				camera.zoom(1.1f);
			else if (zoomOut.getValue())
				camera.zoom(0.9f);
		
		
		}
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


