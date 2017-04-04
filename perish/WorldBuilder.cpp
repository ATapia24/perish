#include "WorldBuilder.h"

WorldBuilder::WorldBuilder(Game *_game, sf::RenderWindow *_window, DrawManager *_manager) {

	window = _window;
	manager = _manager;

	state = BuilderState::SETUP;

	game = _game;

	manager->addLayer(&baseLayer);

}


WorldBuilder::~WorldBuilder() {}

// main function
void WorldBuilder::tick() {

	// check to see our current state
	if (state == BuilderState::SETUP) {

		// init. setup
		displaySetup();

	}

}

void WorldBuilder::handleKeyboard() {

	// TODO

}

// Used for displaying the setup 
void WorldBuilder::displaySetup() {

	// keep from printing twice
	if (setupDisplayed)
		return;
	
	sf::Text *header = new sf::Text;

	header->setString("World Builder");
	header->setFont(game->getDefaultFont());
	header->setCharacterSize(20);

	sf::FloatRect textRect = header->getLocalBounds();
	header->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f + 100.0f);
	header->setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));

	baseLayer.add(header);

	sf::Text *worldTag = new sf::Text;
	worldTag.setString("World Size: ");
	world

	setupDisplayed = true;

}