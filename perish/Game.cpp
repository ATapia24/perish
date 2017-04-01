#include "Game.h"

// Constructor
Game::Game(sf::RenderWindow *_window) :
	window(_window) {}

// Deconstructor
Game::~Game() {}

// Main loop
void Game::start() {

	// Load the texture here
	// TODO (Time for class!)

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
	
	const int MAX_X = 50,
		MAX_Y = 50,
		MAX_FLOATS = 50,
		TILE_HEIGHT = 32,
		TILE_WIDTH = 32;

	// Build a cheap world real quick
	World testWorld("Test", MAX_X, MAX_Y, MAX_FLOATS, TILE_HEIGHT, TILE_WIDTH);



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