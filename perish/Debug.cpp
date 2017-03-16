#include "Debug.h"

//CONSTRUCTOR
Debug::Debug() {
	//blank
}

//CONSTRUCTOR W/ WINDOW MGR
Debug::Debug(WindowManager * _window) {
	window = _window;
	font.loadFromFile("font.ttf");
	fpsText.setPosition(5.0f, 5.0f);
	fpsText.setCharacterSize(25);
	fpsText.setFillColor(sf::Color::Yellow);
	fpsText.setFont(font);

	updateTimer.start();
}

//DECONSTRUCTOR
Debug::~Debug() {
}

//INPUT
void Debug::input() {
}

//UPDATE
void Debug::update() {
	if (updateTimer.getTimeInt() > UPDATE_RATE) {
		updateFps();
		updateTimer.reset_ms();
	}
}


//DRAW
void Debug::draw() {
	window->addGui(fpsText);
}

void Debug::updateFps()
{
	
	//TODO: need to calculate
	fps = 42;
	fpsText.setString("fps: " + misc::floatToString(fps).substr(0, 4));
}
