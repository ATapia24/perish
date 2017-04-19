#include "Game.h"

// Constructor
Game::Game(sf::RenderWindow *_window, int sprites) :
	
	window(_window), MAX_SPRITES(sprites) {

	spriteLocations = new sf::IntRect[sprites];
	manager = new DrawManager(window, 5);

	worldBuilder = new WorldBuilder(this, window, manager);

}

// Deconstructor
Game::~Game() {

	delete[] spriteLocations;
	delete manager;
	delete worldBuilder;

}

// Main loop
void Game::start() {

	// other than the main file of this game.. This is the
	// largest scope!

	// Load the texture here
	loadTexture("C:\\Users\\activates\\Downloads\\assembled1.png");

	// load the default cont
	loadFont("C:\\Users\\chris\\Downloads\\MorrisRomanBlack.ttf");

	// instructions!
	sf::Text instructions;
	instructions.setFont(defaultFont);
	instructions.scale(sf::Vector2f(1.5, 1.5));
	instructions.move(5, 5);
	instructions.setFillColor(sf::Color::White);
	instructions.setString("Press E to go into World-Building mode");

	defaultLayer.add(&instructions);

	// setup the default layer
	implementDefaultLayer();

	while (window->isOpen()) {

		// Window events are handles here, and will always run, not matter
		// what state the game is in
		handleEvents();

		// Same as the window!
		handleKeyboard();

		// Handle mouse input
		handleMouse();

		// strategically placed etcTick!
		etcTick();

		// Handle animation
		animate();

		// Hanlding printing
		render();

	}

}

// Private function for rendering
void Game::render() {

	// Draw everything here
	window->clear();
	manager->draw();
	window->display();

}

// Private function for events
void Game::handleEvents() {

	sf::Event e;
	while (window->pollEvent(e)) {

		if (e.type == sf::Event::Closed) {

			window->close();

		} else if (e.type == sf::Event::MouseButtonPressed) {

			if (e.mouseButton.button == sf::Mouse::Left) {

				/*
				For the world builder's needed clicking!
				*/
				if (state == GameMode::WORLD_BUILDER) {
					worldBuilder->mouseClicked(e.mouseButton.x, e.mouseButton.y);
				}

			}

		} else if (e.type == sf::Event::TextEntered) {

			if (e.text.unicode < 128 && e.text.unicode != 8 && e.text.unicode != 13) {

				/*
				For the world builder's needed typing
				*/
				if (state == GameMode::WORLD_BUILDER) {
					worldBuilder->keyTyped(static_cast<char>(e.text.unicode));
				}

			} else if (e.text.unicode == 8) {

				// BACKSPACE EVENT

				/*
				For the world builder's needed backspace
				*/
				if (state == GameMode::WORLD_BUILDER) {
					worldBuilder->backspace();
				}

			}

		}

	}

}

// Private function for keyboard input
void Game::handleKeyboard() {
	
	// If the game is at IDLE, then we can check
	// to see if they want to enter edit mode
	if (state == GameMode::IDLE) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			removeDefaultLayer();
			state = GameMode::WORLD_BUILDER;
		}
	}

}

// Private function for animation
void Game::animate() {
	// TODO
}

// Private function for handling mouse input
void Game::handleMouse() {

}

// Private function for loading the default font
void Game::loadFont(const std::string &loc) {

	defaultFont.loadFromFile(loc);

}

// Private function for loading the main texture
void Game::loadTexture(const std::string &loc) {

	mainTexture.loadFromFile(loc);

}

// assembles all of the sprites into intrect array
void Game::buildSprites() {

	// world tiles must be square!
	const int SPRITE_DIM = 100;

	for (int i = 0; i < MAX_SPRITES; i++) {

		// This is only a 1 row sprite sheet currently, so that is why
		// the second argument is 0
		spriteLocations[i] = sf::IntRect(i * SPRITE_DIM, 0, SPRITE_DIM, SPRITE_DIM);

	}

}

// implements the default layer
void Game::implementDefaultLayer() {

	// make sure the layer hasn't already been implemented
	if (defaultLayerLoc > -1)
		return;

	defaultLayerLoc = manager->addLayer(&defaultLayer);

}

// Used to remove the default layer
void Game::removeDefaultLayer() {

	defaultLayer.flush();

}

// Used to edit the default layer
DrawLayer & Game::getDefaultLayer() {

	return defaultLayer;

}

// Used to get the default font
sf::Font & Game::getDefaultFont() {

	return defaultFont;

}

// Etc things that need a tick of their own
void Game::etcTick() {

	if (state == GameMode::WORLD_BUILDER) {
		// Tick the world builder
		worldBuilder->tick();

	}

}