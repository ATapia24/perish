/*

This class handles the game loop and all the things that pertain to the game.
Here we can easily set the state of the game, and keep all the important
variables in scope.

*/

#pragma once

#include <SFML/Graphics.hpp>

class Game {

private:

	// Pointer to the RenderWindow
	sf::RenderWindow *window;

	// Used to store if the game is paused or not
	bool paused = false;

	// For the game loop (keep it nice and private!)
	// Simulates a game "tick"
	void render();

	// for animation via textures
	void animate();

	// For handling keyboard input
	void handleKeyboard();

	// For handling mouse input
	void handleMouse();

public:

	Game(sf::RenderWindow*);
	~Game();

	// used to start the game loop
	void start();

};

