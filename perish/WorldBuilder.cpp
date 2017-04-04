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

	// always call the keyboard handler
	handleKeyboard();

}

void WorldBuilder::handleKeyboard() {

	// TODO

}

// Used for displaying the setup 
void WorldBuilder::displaySetup() {

	// keep from printing twice
	if (setupDisplayed)
		return;
	
	// BEGIN header
	sf::Text *header = new sf::Text;
	
	header->setString("World Builder");
	header->setFont(game->getDefaultFont());
	header->setCharacterSize(40);

	sf::FloatRect headerRect = header->getLocalBounds();
	header->setOrigin(headerRect.left + headerRect.width / 2.0f, headerRect.top + headerRect.height / 2.0f);
	header->setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 4.0f));

	// END header

	// BEGIN input labels
	const double FIRST_OFFSET = headerRect.width / 3.0f,
		X_OFFSET = 20,
		Y_OFFSET = 10;

	sf::Text *nameLabel = new sf::Text;
	sf::Text *xLabel = new sf::Text;
	sf::Text *yLabel = new sf::Text;
	
	// name label
	nameLabel->setString("Lvl Name:");
	nameLabel->setCharacterSize(20);
	nameLabel->setFont(game->getDefaultFont());
	sf::FloatRect nameBounds = nameLabel->getLocalBounds();
	nameLabel->setOrigin(nameBounds.left + nameBounds.width / 2.0f, nameBounds.top + nameBounds.height / 2.0f);
	nameLabel->setPosition(sf::Vector2f(header->getPosition().x - FIRST_OFFSET, header->getPosition().y + headerRect.height + Y_OFFSET));

	// x label
	xLabel->setString("Max x: ");
	xLabel->setCharacterSize(20);
	xLabel->setFont(game->getDefaultFont());
	sf::FloatRect xLabelBounds = xLabel->getLocalBounds();
	xLabel->setOrigin(xLabelBounds.left + xLabelBounds.width / 2.0f, xLabelBounds.top + xLabelBounds.height / 2.0f);
	xLabel->setPosition(sf::Vector2f(nameLabel->getPosition().x, nameLabel->getPosition().y + nameBounds.height + Y_OFFSET));

	// y label
	yLabel->setString("Max y: ");
	yLabel->setCharacterSize(20);
	yLabel->setFont(game->getDefaultFont());
	sf::FloatRect yLabelBounds = yLabel->getLocalBounds();
	yLabel->setOrigin(yLabelBounds.left + yLabelBounds.width / 2.0f, yLabelBounds.top + yLabelBounds.height / 2.0f);
	yLabel->setPosition(sf::Vector2f(xLabel->getPosition().x, xLabel->getPosition().y + xLabelBounds.height + Y_OFFSET));

	// END input labels

	// Beging input sections
	sf::Text *nameInput = new sf::Text;
	sf::Text *xInput = new sf::Text;
	sf::Text *yInput = new sf::Text;

	// name input
	nameInput->setString("Default");
	nameInput->setCharacterSize(20);
	nameInput->setFont(game->getDefaultFont());
	sf::FloatRect nameInputBounds = nameInput->getLocalBounds();
	nameInput->setOrigin(nameInputBounds.left + nameInputBounds.width / 2.0f, nameInputBounds.top + nameInputBounds.height / 2.0f);
	nameInput->setPosition(sf::Vector2f(nameLabel->getPosition().x + nameInputBounds.width + X_OFFSET, nameLabel->getPosition().y));

	// x input
	xInput->setString("50");
	xInput->setCharacterSize(20);
	xInput->setFont(game->getDefaultFont());
	sf::FloatRect xInputBounds = xInput->getLocalBounds();
	xInput->setOrigin(xInputBounds.left + xInputBounds.width / 2.0f, xInputBounds.top + xInputBounds.height / 2.0f);
	xInput->setPosition(sf::Vector2f(xLabel->getPosition().x + xInputBounds.width + X_OFFSET, xLabel->getPosition().y));

	// y label
	yInput->setString("50");
	yInput->setCharacterSize(20);
	yInput->setFont(game->getDefaultFont());
	sf::FloatRect yInputBounds = yInput->getLocalBounds();
	yInput->setOrigin(yInputBounds.left + yInputBounds.width / 2.0f, yInputBounds.top + yInputBounds.height / 2.0f);
	yInput->setPosition(sf::Vector2f(yLabel->getPosition().x + yInputBounds.width + X_OFFSET, yLabel->getPosition().y));

	// END input sections

	// add all the items
	baseLayer.add(header);
	baseLayer.add(nameLabel);
	baseLayer.add(xLabel);
	baseLayer.add(yLabel);
	baseLayer.add(nameInput);
	baseLayer.add(xInput);
	baseLayer.add(yInput);

	setupDisplayed = true;

}