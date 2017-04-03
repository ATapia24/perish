/*

This class handles the game loop and all the things that pertain to the game.
Here we can easily set the state of the game, and keep all the important
variables in scope.

*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "World.h"
#include "WorldRenderer.h"
#include "DrawManager.h"
#include "WorldBuilder.h"

/*
These are in the order that the sprites are build from the sprite sheet.
For now, these are hard-coded values that represent indexes beneath!
*/
enum class SpriteType {

	DIRT,
	DIRT2,
	DIRT2GRASS,
	DIRTY_GRASS,
	DIRT2DESERT,
	DIRTY_DESERT,
	DIRT2ROCKY,
	ROCKY

};

/*
These represent what mode the game is currently in. This is used to decide
what processes to run, and what to display!
*/
enum class GameMode {

	IDLE,			// The game has been started and is not doing anything, yet
	WORLD_BUILDER,	// The world builder is active
	PLAY,			// The game is actually in motion, and being played
	PAUSED			// The game is being played, but is paused

};

class WorldBuilder;

class Game {

private:

	// keeps track of the current state of the game
	GameMode state = GameMode::IDLE;

	// Pointer to the RenderWindow
	sf::RenderWindow *window;

	// The draw manager!
	DrawManager *manager;

	// For the world builder!
	WorldBuilder *worldBuilder;

	// The default layer of the entire game. This layer is always on the bottom,
	// so be weary of that
	DrawLayer defaultLayer;
	int defaultLayerLoc = -1;

	// A nice world renderer for whatever I need it for.. Which is
	// obviously rendering a world! ;)
	WorldRenderer wRenderer;

	// For the game loop (keep it nice and private!)
	// Simulates a game "tick"
	void render();

	// for animation via textures
	void animate();

	// For handling basic window events
	void handleEvents();

	// For handling keyboard input
	void handleKeyboard();

	// For handling mouse input
	void handleMouse();

	// Main texture file to grab from
	sf::Texture mainTexture;

	// Loads the mainTexture from the file location it is given
	void loadTexture(const std::string&);

	// the default font of the whole game
	sf::Font defaultFont;

	// used to load font!
	void loadFont(const std::string&);

	// an array of IntRects which stand for the location where a sprite is
	sf::IntRect *spriteLocations;

	// holds the max amount of sprites in the currently array
	const int MAX_SPRITES;

	// Fills up the spriteLocations array with the correct information to the
	// corresponding sprites
	void buildSprites();

	// Just a code space where extra items can be 'ticked' such as the world builder
	void etcTick();

public:

	Game(sf::RenderWindow*, int);
	~Game();

	// used to start the game loop
	void start();

	// adds the default layer to the DrawManager
	void implementDefaultLayer();

	// removes the default layer
	void removeDefaultLayer();

	// Retrieves the default layer for managing
	DrawLayer & getDefaultLayer();

	// gets the default font
	sf::Font & getDefaultFont();

};

