#include "Renderer.h"



Renderer::Renderer()
{
	drawMutex = new std::mutex();
}

Renderer::~Renderer()
{
	delete drawMutex;
}

void Renderer::close() {
	windowOpen = false;
}

void Renderer::init() {
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), misc::GAME_NAME ,sf::Style::Titlebar);
	window->setFramerateLimit(200);
	window->setVerticalSyncEnabled(false);
	fps = 0.0f;
	fpsTimer.start();
	windowOpen = true;
	std::cout << "draw mutex: " << drawMutex << '\n';
}

void Renderer::threadHandler() {

	init();

	while (windowOpen) {
		if (pollEvents()) {
			draw();
			calcFps();
		}
	}

	window->close();
}

void Renderer::draw() {

	window->clear(sf::Color::Black);

	drawMutex->lock();
	for (int i = 0; i < buffers.size(); i++) {
		window->setView(*buffers[i]->getView());
		for (int j = 0; j < buffers[i]->getMaxSize(); j++) {
			switch (buffers[i]->getBuffer()[j].type)
			{
			case DrawType::EMPTY:
				//do nothing
				break;
			case DrawType::SPRITE:
				window->draw(*buffers[i]->getBuffer()[j].sprite);
				break;
			case DrawType::TEXT:
				window->draw(*buffers[i]->getBuffer()[j].text);
				break;
			case DrawType::RECTANGLE:
				window->draw(*buffers[i]->getBuffer()[j].rectangle);
				break;
			case DrawType::CIRCLE:
				window->draw(*buffers[i]->getBuffer()[j].circle);
				break;
			case DrawType::CONVEX:
				window->draw(*buffers[i]->getBuffer()[j].sprite);
				break;
			}
		}
	}
	drawMutex->unlock();

	window->display();
}

bool Renderer::pollEvents() {
	//handle window events
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			return false;
			break;
		default: //do nothing
			break;
		}
	}

	return true;
}

void Renderer::addBuffer(DrawBuffer& db) {
	db.getView()->reset((sf::FloatRect(0, 0, (float)window->getSize().x, (float)window->getSize().y)));
	buffers.push_back(&db);
}

void Renderer::calcFps() {
	fps = (1000000000.0f / (float)fpsTimer.getNanoseconds());
	fpsTimer.reset();
}

