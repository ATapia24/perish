#include "Game.h"

// Constructor
Game::Game(sf::RenderWindow *_window) :
	window(_window) {}

// Deconstructor
Game::~Game() {}

// Main loop
void Game::start() {

	while (window->isOpen()) {

		// Handle key input
		handleKeyboard();

		// Handle mouse input
		handleMouse();

		// Handle animation
		animate();

		// Hanlding printing
		render();

	}

}

// Private function for rendering
void Game::render() {
	//  TODO
}

// Private function for keyboard input
void Game::handleKeyboard() {
	// TODO
}

// Private function for animation
void Game::animate() {
	// TODO
}

// Private function for handling mouse input
void Game::handleMouse() {
	// TODO
}