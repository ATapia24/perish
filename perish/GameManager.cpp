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

	Player player;
	player.load(&camera, physWorld, layer);
	player.spawn();

	const int b = 100;
	Box* boxes = new Box[b];

	for (int i = 0; i < b; i++) {
		//boxes[i].load(physWorld, layer);
	}

	Key spawn;
	spawn.set(sf::Keyboard::Tab, KeyType::SINGLE);

	Menu menu(guiLayer, 10, 10, 500);
	menu.add(fpsString);
	menu.addLiteral("press \"tab\"");
	menu.reshape();

	Key up(sf::Keyboard::Up, KeyType::SINGLE), down(sf::Keyboard::Down, KeyType::SINGLE);

	sf::Texture texture;
	texture.loadFromFile("assets/dirty_grass.png");

	const int x = 10;
	sf::Sprite** sprite = new sf::Sprite*[x];
	for (int i = 0; i < x; i++) {
		sprite[i] = new sf::Sprite[x];
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			sprite[i][j].setPosition(i * 100 - (x*100/2), j * 100 - (x*100/2));
			sprite[i][j].setTexture(texture);
			floor.add(sprite[i][j]);
		}
	}

	drawManager->addLayer(floor);
	drawManager->addLayer(layer);
	drawManager->addLayer(guiLayer);

	//start game tick timer
	gameTickTimer.start();
	int count = 0;
	int sOffset = 0;

	Timer clk;
	clk.start();
	while (window->isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { 
		if (gameTick()) {

			menu.update();
			player.update();

			for (int i = 0; i < b; i++)
				boxes[i].update();

			physWorld->Step(1.0f/60.f, 8, 3);


			if (spawn.getValue() && count < b) {
				boxes[count].setSpawnPoint(misc::pointLocation(player.getPosition(), player.getBody()->GetAngle(), 0.5f), player.getBody()->GetAngle());
				boxes[count].spawn();
				count++;
			}
		
		
		}
	}
}

//GAME TICK
bool GameManager::gameTick() {

	fpsString = "logic fps: " + misc::floatToString(1.f / ((float)gameTickTimer.getMilliseconds() / 1000.f));

	if (gameTickTimer.getMilliseconds() > TICK_RATE) {
		gameTickTimer.reset();
		return true;
	}

	return false;
}


