#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Miscellaneous.h"
#include "DrawBuffer.h"
#include "Timer.h"
#include <mutex>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void threadHandler();
	void init();
	void close();
	void addBuffer(DrawBuffer& db);
	inline sf::RenderWindow* getWindow() { return window; };
	inline float getFps() { return fps; };

private:
	sf::RenderWindow *window;
	sf::Event event;
	std::vector<DrawBuffer*> buffers;
	void draw();
	bool pollEvents();
	bool windowOpen;

	//fps
	float fps;
	Timer fpsTimer;
	void calcFps();
};

