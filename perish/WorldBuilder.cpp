#include "WorldBuilder.h"

WorldBuilder::WorldBuilder(Game *_game, sf::RenderWindow *_window, DrawManager *_manager) :
	clickHandler(ClickParser(50)) {

	window = _window;
	manager = _manager;

	state = BuilderState::SETUP;

	game = _game;

	manager->addLayer(&baseLayer);

}


WorldBuilder::~WorldBuilder() {
	
	// delete some basic stuff
	delete nameInput;
	delete xInput;
	delete yInput;

}

// main function
void WorldBuilder::tick() {

	// check to see our current state
	if (state == BuilderState::SETUP) {

		// init. setup
		displaySetup();

	}

}

void WorldBuilder::calculateBounds(const sf::Text &txt, float &x1, float &y1, float &x2, float &y2) {

	// edit the bounds, so it can be easily clicked on
	sf::FloatRect txtInputBounds = txt.getLocalBounds();

	x1 = txt.getPosition().x - (txtInputBounds.width / 2.0f);
	y1 = txt.getPosition().y - (txtInputBounds.height / 2.0f);

	x2 = txt.getPosition().x + (txtInputBounds.width / 2.0f);
	y2 = txt.getPosition().y + (txtInputBounds.height / 2.0f);

}

void WorldBuilder::keyTyped(char c) {

	// check to see if a certain item is currently clicked, and
	// then edit the typing there

	// check to see if we are in the setup stage
	if (state == BuilderState::SETUP) {

		// World name input check
		if (clickHandler.wasClicked(clickLocations[TextBoxes::NAME_INPUT])) {
			// make sure it's not already too big
			if (nameInput->getString().getSize() < 25) {
				nameInput->setString(nameInput->getString() + c);

				// edit the bounds, so it can be easily clicked on
				float x1, y1, x2, y2;
				calculateBounds(*nameInput, x1, y1, x2, y2);

				clickHandler.editClick(clickLocations[TextBoxes::NAME_INPUT], x1, y1, x2, y2);

			}
		}

		// X size input check
		if (clickHandler.wasClicked(clickLocations[TextBoxes::X_INPUT])) {

			// make sure it's not already too big and that a digit was passed
			if (xInput->getString().getSize() < 4 && isdigit(c)) {
				xInput->setString(xInput->getString() + c);

				// edit the bounds, so it can be easily clicked on
				float x1, y1, x2, y2;
				calculateBounds(*xInput, x1, y1, x2, y2);

				clickHandler.editClick(clickLocations[TextBoxes::X_INPUT], x1, y1, x2, y2);
			}

		}

		// Y size input check
		if (clickHandler.wasClicked(clickLocations[TextBoxes::Y_INPUT])) {

			// make sure it's not already too big and that a digit was passed
			if (yInput->getString().getSize() < 4 && isdigit(c)) {
				yInput->setString(yInput->getString() + c);

				// edit the bounds, so it can be easily clicked on
				float x1, y1, x2, y2;
				calculateBounds(*yInput, x1, y1, x2, y2);

				clickHandler.editClick(clickLocations[TextBoxes::Y_INPUT], x1, y1, x2, y2);
			}

		}

	}
}

void WorldBuilder::backspace() {

	// check to see if we are in the setup stage
	if (state == BuilderState::SETUP) {

		// World name input check
		if (clickHandler.wasClicked(clickLocations[TextBoxes::NAME_INPUT])) {

			int size = nameInput->getString().getSize();

			// prevening errors!
			if (size < 1)
				return;

			std::string modified = nameInput->getString();
			modified.erase(modified.end() - 1, modified.end());

			nameInput->setString(modified);

			float x1, y1, x2, y2;
			calculateBounds(*nameInput, x1, y1, x2, y2);

			clickHandler.editClick(clickLocations[TextBoxes::X_INPUT], x1, y1, x2, y2);

		}

		if (clickHandler.wasClicked(clickLocations[TextBoxes::X_INPUT])) {

			int size = xInput->getString().getSize();

			// prevening errors!
			if (size < 1)
				return;

			std::string modified = xInput->getString();
			modified.erase(modified.end() - 1, modified.end());

			xInput->setString(modified);

			float x1, y1, x2, y2;
			calculateBounds(*xInput, x1, y1, x2, y2);

			clickHandler.editClick(clickLocations[TextBoxes::X_INPUT], x1, y1, x2, y2);

		}
	
		if (clickHandler.wasClicked(clickLocations[TextBoxes::Y_INPUT])) {

			int size = yInput->getString().getSize();

			// prevening errors!
			if (size < 1)
				return;

			std::string modified = yInput->getString();
			modified.erase(modified.end() - 1, modified.end());

			yInput->setString(modified);

			float x1, y1, x2, y2;
			calculateBounds(*yInput, x1, y1, x2, y2);

			clickHandler.editClick(clickLocations[TextBoxes::Y_INPUT], x1, y1, x2, y2);

		}

	}

}

void WorldBuilder::mouseClicked(float x, float y) {

	// parse any and all clicks!
	clickHandler.parseClick(x, y);

	// check to see if we are in setup
	if (state == BuilderState::SETUP) {

		if (clickHandler.wasClicked(clickLocations[TextBoxes::NAME_INPUT])) {
			std::cout << "Default was clicked!\n";
		}

	}

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
	nameInput = new sf::Text;
	xInput = new sf::Text;
	yInput = new sf::Text;

	// name input
	nameInput->setString("Default");
	nameInput->setCharacterSize(20);
	nameInput->setFont(game->getDefaultFont());
	sf::FloatRect nameInputBounds = nameInput->getLocalBounds();
	nameInput->setOrigin(nameInputBounds.left + nameInputBounds.width / 2.0f, nameInputBounds.top + nameInputBounds.height / 2.0f);
	nameInput->setPosition(sf::Vector2f(nameLabel->getPosition().x + nameInputBounds.width + X_OFFSET, nameLabel->getPosition().y));

	// used to store the coordinate ranges for the clickable lables
	float x1, y1, x2, y2;

	x1 = nameInput->getPosition().x - (nameInputBounds.width / 2.0f);
	y1 = nameInput->getPosition().y - (nameInputBounds.height / 2.0f);

	x2 = nameInput->getPosition().x + (nameInputBounds.width / 2.0f);
	y2 = nameInput->getPosition().y + (nameInputBounds.height / 2.0f);

	// add it to the click listener
	clickLocations[TextBoxes::NAME_INPUT] = clickHandler.addClick(x1, y1, x2, y2);

	// x input
	xInput->setString("50");
	xInput->setCharacterSize(20);
	xInput->setFont(game->getDefaultFont());
	sf::FloatRect xInputBounds = xInput->getLocalBounds();
	xInput->setOrigin(xInputBounds.left + xInputBounds.width / 2.0f, xInputBounds.top + xInputBounds.height / 2.0f);
	xInput->setPosition(sf::Vector2f(xLabel->getPosition().x + xInputBounds.width + X_OFFSET, xLabel->getPosition().y));

	// calculate all the bounds
	x1 = xInput->getPosition().x - (xInputBounds.width / 2.0f);
	y1 = xInput->getPosition().y - (xInputBounds.height / 2.0f);

	x2 = xInput->getPosition().x + (xInputBounds.width / 2.0f);
	y2 = xInput->getPosition().y + (xInputBounds.height / 2.0f);

	// add it to the click listener
	clickLocations[TextBoxes::X_INPUT] = clickHandler.addClick(x1, y1, x2, y2);

	// y input
	yInput->setString("50");
	yInput->setCharacterSize(20);
	yInput->setFont(game->getDefaultFont());
	sf::FloatRect yInputBounds = yInput->getLocalBounds();
	yInput->setOrigin(yInputBounds.left + yInputBounds.width / 2.0f, yInputBounds.top + yInputBounds.height / 2.0f);
	yInput->setPosition(sf::Vector2f(yLabel->getPosition().x + yInputBounds.width + X_OFFSET, yLabel->getPosition().y));

	// last calculation of the bounds
	x1 = yInput->getPosition().x - (yInputBounds.width / 2.0f);
	y1 = yInput->getPosition().y - (yInputBounds.height / 2.0f);

	x2 = yInput->getPosition().x + (yInputBounds.width / 2.0f);
	y2 = yInput->getPosition().y + (yInputBounds.height / 2.0f);

	// add it to the click listener
	clickLocations[TextBoxes::Y_INPUT] = clickHandler.addClick(x1, y1, x2, y2);

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