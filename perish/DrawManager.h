#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "DrawLayer.h"
#include "Miscellaneous.h"
#include "Timer.h"

class DrawManager {
public:

	DrawManager();
	~DrawManager();
	void ThreadHandler();


	//window management
	void initWindow();
	void resizeWindow(unsigned int width, unsigned int height, bool _fullscreen, bool border);
	bool isWindowReadyToClose() const { return windowCloseReady; };
	bool isWindowOpen() const { return windowOpen; };
	void close();
	void draw();

	//layers
	void addLayer(DrawLayer* layer);
	void addLayer(DrawLayer& layer);
	void setLayer(int, DrawLayer& layer);

	//get
	DrawLayer* getLayers() const { return *layers; };
	sf::RenderWindow* getWindow() { return window; };
	float getFps();

private:
	bool pollEvents();
	void calculateFps();

	//window management
	HWND consoleWindow;
	sf::RenderWindow *window;
	sf::Event event;
	bool windowOpen, windowCloseReady;

	// Holds the drawable layers
	DrawLayer **layers;
	const int MAX_LAYERS = 50;
	int layersUsed = 0;

	//temp
	Timer t;
	Timer fpsTimer;
	float fps;
};

#endif /* DRAWMANAGER_H */
