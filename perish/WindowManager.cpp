#include "WindowManager.h"

//DEFAULT CONSTRUCTOR
WindowManager::WindowManager() {
	//blank
}

// Main constructor for the class
WindowManager::WindowManager(unsigned int height, unsigned int width, const std::string _name) {

	// Create the dynamic goodness
	window = new sf::RenderWindow(sf::VideoMode(height, width), _name);
	window->setView(worldView);
	name = _name;
	setResolution(height, width, 0, 1);
	fullscreen = 0;
	fps = 60;
	guiQueue = new queueType[MAX_DRAW_SIZE];
	worldQueue = new queueType[MAX_DRAW_SIZE];
	guiSize = 0;
	worldSize = 0;
}

// runs when the class leaves the scope
WindowManager::~WindowManager() {
	delete window;
	delete[] guiQueue;
	delete[] worldQueue;
}

//DRAW
void WindowManager::draw() {
	window->clear();

	//world
	window->setView(worldView);
	for (unsigned int i = 0; i < worldSize; i++) {
		switch (worldQueue[i].type) {
		case 1:
			window->draw(worldQueue[i].sprite, worldQueue[i].blendMode);
			break;
		case 2:
			window->draw(worldQueue[i].text, worldQueue[i].blendMode);
			break;
		case 3:
			window->draw(worldQueue[i].rectangle, worldQueue[i].blendMode);
			break;
		case 4:
			window->draw(worldQueue[i].circle, worldQueue[i].blendMode);
			break;
		case 5:
			window->draw(worldQueue[i].convex, worldQueue[i].blendMode);
			break;
		case 6:
			window->draw(worldQueue[i].vertexArray, worldQueue[i].blendMode);
			break;
		}
	}

	//gui
	window->setView(guiView);
	for (unsigned int i = 0; i < guiSize; i++) {
		switch (guiQueue[i].type) {
		case 1:
			window->draw(guiQueue[i].sprite, guiQueue[i].blendMode);
			break;
		case 2:
			window->draw(guiQueue[i].text, guiQueue[i].blendMode);
			break;
		case 3:
			window->draw(guiQueue[i].rectangle, guiQueue[i].blendMode);
			break;
		case 4:
			window->draw(guiQueue[i].circle, guiQueue[i].blendMode);
			break;
		case 5:
			window->draw(guiQueue[i].convex, guiQueue[i].blendMode);
			break;
		}
	}

	window->display();

	//clear queue
	guiSize = 0;
	worldSize = 0;
}

//GUI - ADD SPRITE
void WindowManager::addGui(sf::Sprite sprite) {
	guiQueue[guiSize].type = 1;
	guiQueue[guiSize].sprite = sprite;
	guiQueue[guiSize].sprite.setScale(guiQueue[guiSize].sprite.getScale().x, guiQueue[guiSize].sprite.getScale().y);
	guiQueue[guiSize].sprite.setPosition(guiQueue[guiSize].sprite.getPosition().x * widthScale, guiQueue[guiSize].sprite.getPosition().y * heightScale);
	guiQueue[worldSize].blendMode = sf::BlendAlpha;
	guiSize++;
}

//GUI - ADD TEXT
void WindowManager::addGui(sf::Text text) {
	guiQueue[guiSize].type = 2;
	guiQueue[guiSize].text = text;
	guiQueue[guiSize].text.setScale(widthScale, heightScale);
	guiQueue[guiSize].text.setPosition(guiQueue[guiSize].text.getPosition().x * widthScale, guiQueue[guiSize].text.getPosition().y * heightScale);
	guiQueue[worldSize].blendMode = sf::BlendAlpha;
	guiSize++;
}

//GUI - ADD RECTANGLE
void WindowManager::addGui(sf::RectangleShape rectangle) {
	guiQueue[guiSize].type = 3;
	guiQueue[guiSize].rectangle = rectangle;
	guiQueue[guiSize].rectangle.setScale(widthScale, heightScale);
	guiQueue[guiSize].rectangle.setPosition(widthScale * guiQueue[guiSize].rectangle.getPosition().x, heightScale * guiQueue[guiSize].rectangle.getPosition().y);
	guiQueue[worldSize].blendMode = sf::BlendAlpha;
	guiSize++;
}

//GUI - ADD CIRCLE
void WindowManager::addGui(sf::CircleShape circle) {
	guiQueue[guiSize].type = 4;
	guiQueue[guiSize].circle = circle;
	guiQueue[guiSize].circle.setScale(widthScale, heightScale);
	guiQueue[guiSize].circle.setPosition(widthScale * guiQueue[guiSize].circle.getPosition().x, heightScale * guiQueue[guiSize].circle.getPosition().y);
	guiQueue[worldSize].blendMode = sf::BlendAlpha;
	guiSize++;
}

//GUI - ADD CONVEX
void WindowManager::addGui(sf::ConvexShape convex) {
	guiQueue[guiSize].type = 5;
	guiQueue[guiSize].convex = convex;
	guiQueue[guiSize].convex.setScale(widthScale, heightScale);
	guiQueue[guiSize].convex.setPosition(widthScale * guiQueue[guiSize].convex.getPosition().x, heightScale * guiQueue[guiSize].convex.getPosition().y);
	guiQueue[worldSize].blendMode = sf::BlendAlpha;
	guiSize++;
}

//World - ADD SPRITE
void WindowManager::addWorld(sf::Sprite sprite) {
	worldQueue[worldSize].type = 1;
	worldQueue[worldSize].sprite = sprite;
	worldQueue[worldSize].sprite.setScale(widthScale * worldQueue[worldSize].sprite.getScale().x, heightScale * worldQueue[worldSize].sprite.getScale().y);
	worldQueue[worldSize].sprite.setPosition(worldQueue[worldSize].sprite.getPosition().x * widthScale, worldQueue[worldSize].sprite.getPosition().y * heightScale);
	worldQueue[worldSize].blendMode = sf::BlendAlpha;
	worldSize++;
}

//World - ADD TEXT
void WindowManager::addWorld(sf::Text text) {
	worldQueue[worldSize].type = 2;
	worldQueue[worldSize].text = text;
	worldQueue[worldSize].text.setScale(widthScale, heightScale);
	worldQueue[worldSize].text.setPosition(widthScale * worldQueue[worldSize].text.getPosition().x, heightScale * worldQueue[worldSize].text.getPosition().y);
	worldQueue[worldSize].blendMode = sf::BlendAlpha;
	worldSize++;
}

//World - ADD RECTANGLE
void WindowManager::addWorld(sf::RectangleShape rectangle) {
	worldQueue[worldSize].type = 3;
	worldQueue[worldSize].rectangle = rectangle;
	worldQueue[worldSize].rectangle.setScale(widthScale, heightScale);
	worldQueue[worldSize].rectangle.setPosition(widthScale * worldQueue[worldSize].rectangle.getPosition().x, heightScale * worldQueue[worldSize].rectangle.getPosition().y);
	worldQueue[worldSize].blendMode = sf::BlendAlpha;
	worldSize++;
}

//World - ADD CIRCLE
void WindowManager::addWorld(sf::CircleShape circle) {
	worldQueue[worldSize].type = 4;
	worldQueue[worldSize].circle = circle;
	worldQueue[worldSize].circle.setScale(widthScale, heightScale);
	worldQueue[worldSize].circle.setPosition(widthScale * worldQueue[worldSize].circle.getPosition().x, heightScale * worldQueue[worldSize].circle.getPosition().y);
	worldQueue[worldSize].blendMode = sf::BlendAlpha;
	worldSize++;
}

//World - ADD CONVEX
void WindowManager::addWorld(sf::ConvexShape convex) {
	worldQueue[worldSize].type = 5;
	worldQueue[worldSize].convex = convex;
	worldQueue[worldSize].convex.setScale(widthScale, heightScale);
	worldQueue[worldSize].convex.setPosition(widthScale * worldQueue[worldSize].convex.getPosition().x, heightScale * worldQueue[worldSize].convex.getPosition().y);
	worldQueue[worldSize].blendMode = sf::BlendAlpha;
	worldSize++;
}

//World - ADD VERTEX ARRAY
void WindowManager::addWorld(sf::VertexArray vertexArray) {
	worldQueue[worldSize].type = 6;
	worldQueue[worldSize].vertexArray = vertexArray;
	worldSize++;
}

//World - ADD SPRITE w/ blend mode
void WindowManager::addWorld(sf::Sprite sprite, const sf::BlendMode blendMode) {
	worldQueue[worldSize].type = 1;
	worldQueue[worldSize].sprite = sprite;
	worldQueue[worldSize].sprite.setScale(widthScale * worldQueue[worldSize].sprite.getScale().x, heightScale * worldQueue[worldSize].sprite.getScale().y);
	worldQueue[worldSize].sprite.setPosition(worldQueue[worldSize].sprite.getPosition().x * widthScale, worldQueue[worldSize].sprite.getPosition().y * heightScale);
	worldQueue[worldSize].blendMode = blendMode;
	worldSize++;
}

// Allows you to manually set the frame rate
void WindowManager::setFramerate(unsigned int _fps) {
	window->setFramerateLimit(_fps);
	fps = _fps;
}

void WindowManager::setRepeatingKeysEnabled(bool enabled) {
	window->setKeyRepeatEnabled(enabled);
}

//SET RESOLUTION
void WindowManager::setResolution(int width, int height, bool _fullscreen, bool border) {
	//calculate new scales
	widthScale = (float)width / misc::NATIVE_WIDTH;
	heightScale = (float)height / misc::NATIVE_HEIGHT;

	//set resolution
	window->create(sf::VideoMode(width, height), name, (_fullscreen ? sf::Style::Fullscreen : (border ? sf::Style::Titlebar : sf::Style::None)));
	window->setPosition(sf::Vector2i(0, 0));
	window->setFramerateLimit(fps);
	fullscreen = _fullscreen;
	guiView.reset((sf::FloatRect(0, 0, (float)width, (float)height)));
	worldView.reset((sf::FloatRect(0, 0, (float)width, (float)height)));

}