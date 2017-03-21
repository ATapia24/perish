#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "WindowManager.h"
#include "Timer.h"
#include "Miscellaneous.h"

class Debug {
private:
	WindowManager* window;
	sf::Font font;
	Timer updateTimer;
	const int UPDATE_RATE = 250;

	//fps
	sf::Text fpsText;
	Timer fpsTimer;
	float fps;
	void updateFps();
public:
	Debug();
	Debug(WindowManager* _window);
	~Debug();
	void input();
	void update();
	void draw();
};

#endif