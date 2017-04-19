/*

The awe-inspiring WorldBuilding class! Here we allow the user
to build their own worlds and save them to a file, so the game
can read the world!

*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cctype>

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


	// used to see if the layer needs to be updated
	bool changesMade = false;

	// displays the setup GUI
	void displaySetup();
	bool setupDisplayed = false;

	// All our text boxes here
	sf::Text *nameInput;
	sf::Text *xInput;
	sf::Text *yInput;
	sf::Text *submit;

	// Used to calculate bounds of a textbox!
	void calculateBounds(const sf::Text&, float&, float&, float&, float&);

	/*
	Okay.. So for the programmer who is wondering what these enums are for,
	let me tell you!

	These enums are to used to distinguish between different items in an array.
	What array, you ask? That would be the 'clickLocations' array. We have this
	array because the ClickParser class returns an int that we use to reference
	an item we have passed to it, so I simply use an array to hold all those
	values, and to reference the items I use enums!
	*/

	enum TextBoxes {
		NAME_INPUT = 0,
		X_INPUT = 1,
		Y_INPUT = 2
	};

	// Array of textbox locations for the ClickParser class
	// change the array count depending on how many text boxes
	// that were implemented
	int clickLocations[3];


public:

	WorldBuilder(Game*, sf::RenderWindow*, DrawManager*);
	~WorldBuilder();

	// the main function of this class.. It should be called
	// repeatedly
	void tick();

	// the basic mouse listener for the class. This should be called
	// everytime the mouse is clicked, and the coords should be passed
	void mouseClicked(float, float);

	// They keyboard tick
	void keyTyped(char);

	// the backspace keyboard tick
	// should be fired when a backspace happens!
	void backspace();

};

