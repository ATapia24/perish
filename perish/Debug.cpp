#include "Debug.h"

//CONSTRUCTOR
Debug::Debug() {
	//blank
}

//CONSTRUCTOR W/ WINDOW MGR
/*Debug::Debug(WindowManager * _window) {
	window = _window;
	font.loadFromFile("./assets/font.ttf");
	fpsText.setPosition(5.0f, 5.0f);
	fpsText.setCharacterSize(25);
	fpsText.setFillColor(sf::Color::Yellow);
	fpsText.setFont(font);

	updateTimer.start();
	fpsTimer.start();
}*/

//DECONSTRUCTOR
Debug::~Debug() {
}

//INPUT
void Debug::input() {
}

//UPDATE
void Debug::update() {
	
	updateFps();

	if (updateTimer.getMilliseconds() > UPDATE_RATE) {
		fpsText.setString("fps: " + misc::floatToString(fps).substr(0, 4));
		updateTimer.reset();
	}
}


//DRAW
void Debug::draw() {
	//window->addGui(fpsText);
}

void Debug::updateFps()
{
	fps = 1000.0f  / (float)fpsTimer.getMilliseconds();
	fpsTimer.reset();
}
