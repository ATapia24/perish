#include "EditorMode.h"


//CONSTRUCTOR
EditorMode::EditorMode()
{
	loaded = false;
	angle = 0.0f;
}

//CONSTRUCTOR W/ RENDERER
EditorMode::EditorMode(Renderer *_renderer)
{
	renderer = _renderer;
	loaded = false; angle = 0.0f;
}

//DECONSTRUCTOR
EditorMode::~EditorMode()
{
	if(floor != NULL)
		delete floor;
}

//LOAD
void EditorMode::load() {
	leftClick.set(sf::Mouse::Button::Left, KeyType::REPEATED);
	rightClick.set(sf::Mouse::Button::Right, KeyType::SINGLE);
	up.set(sf::Keyboard::W, KeyType::REPEATED);
	down.set(sf::Keyboard::S, KeyType::REPEATED);
	left.set(sf::Keyboard::A, KeyType::REPEATED);
	right.set(sf::Keyboard::D, KeyType::REPEATED);
	rotateLeft.set(sf::Keyboard::Left, KeyType::REPEATED);
	rotateRight.set(sf::Keyboard::Right, KeyType::REPEATED);

	floor = new DrawBuffer(camera);
	misc::pwd();
	gridTexture.loadFromFile("./assets/grid.png");
	gridTexture.setRepeated(true);
	grid.setTexture(gridTexture);
	grid.setTextureRect({GRID_SIZE/2, GRID_SIZE/2, GRID_SIZE, GRID_SIZE});
	grid.setPosition(sf::Vector2f(0, 0));
	
	extern std::mutex *drawMutex;
	std::cout << "mutex: " << drawMutex << '\n';
	while (!drawMutex->try_lock()) {
		std::cout << "lock failed\n";
	}

	std::cout << "edit lock\n";
	floor->add(grid);
	renderer->addBuffer(*floor);
	std::cout << "edit unlock\n";
	drawMutex->unlock();
	loaded = true;
}

//UPDATE
void EditorMode::update() {
	dtTimer.stop();
	dt = dtTimer.getNanoseconds();
	dtTimer.reset();

	if (!loaded)
		return;

	drawMutex->lock();

	//up and down
	if (up.getValue()) {
		camera.setCenter(misc::pointLocation(camera.getCenter(), angle, dt*moveSpeed));
	}
	else if (down.getValue()) {
		camera.setCenter(misc::pointLocation(camera.getCenter(), angle+misc::PI, dt*moveSpeed));
	}

	//left and right
	if (left.getValue()) {
		camera.setCenter(misc::pointLocation(camera.getCenter(), angle-misc::PIh, dt*moveSpeed));
	}
	else if (right.getValue()) {
		camera.setCenter(misc::pointLocation(camera.getCenter(), angle+misc::PIh, dt*moveSpeed));
	}


	if (rotateLeft.getValue()) {
		angle -= rotateSpeed * dt;
		camera.setRotation(angle*misc::RAD2DEG);
	}
	else if (rotateRight.getValue()) {
		angle += rotateSpeed * dt;
		camera.setRotation(angle*misc::RAD2DEG);
	}
	if (leftClick.getValue()) {

		int x = sf::Mouse::getPosition(*renderer->getWindow()).x + floor->getView()->getCenter().x - renderer->getWindow()->getSize().x/2;
		int y = sf::Mouse::getPosition(*renderer->getWindow()).y + floor->getView()->getCenter().y - renderer->getWindow()->getSize().y/2;

		cubes.push_back(new sf::RectangleShape);
		cubes[cubes.size() - 1]->setFillColor(misc::randomColor());
		cubes[cubes.size() - 1]->setSize(sf::Vector2f(25, 25));
		cubes[cubes.size() - 1]->setPosition(sf::Vector2f(x, y));

		floor->add(*cubes[cubes.size() - 1]);

	}

	drawMutex->unlock();
	dtTimer.start();
}
