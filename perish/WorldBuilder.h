/*

The awe-inspiring WorldBuilding class! Here we allow the user
to build their own worlds and save them to a file, so the game
can read the world!

*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "DrawManager.h"
#include "DrawLayer.h"
#include "ClickParser.h"

/*
Keeps track of the current state of the builder.
Each one helps the builder keep track of what to do
next!
*/
enum class BuilderState {

	SETUP,			// A world needs to be created, or selected
	EDITING			// The world is being edited

};

// for the lame compilers
class Game;

class WorldBuilder {

private:

	// For window access and drawing!
	sf::RenderWindow *window;
	DrawManager *manager;

	// Game object
	Game *game;

	// the layer where all the drawing will take place
	// for now we will put it all on one layer
	DrawLayer baseLayer;

	// Holds the state of the game
	BuilderState state;

	// for handling the clicks etc
	ClickParser clickHandler;

	// for holding the basic menu items that have been clicked
	int labelID, xID, yID;

	// used to see if the layer needs to be updated
	bool changesMade = false;

	// displays the setup GUI
	void displaySetup();
	bool setupDisplayed = false;

	// They keyboard tick
	void handleKeyboard();

public:

	WorldBuilder(Game*, sf::RenderWindow*, DrawManager*);
	~WorldBuilder();

	// the main function of this class.. It should be called
	// repeatedly
	void tick();

	// the basic mouse listener for the class. This should be called
	// everytime the mouse is clicked, and the coords should be passed
	void mouseClicked(float, float);

};

