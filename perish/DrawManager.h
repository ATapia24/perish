/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   DrawManager.h
* Author: activates
*
* Created on March 13, 2017, 4:47 PM
*/

#include <SFML/Graphics.hpp>
#include <windows.h>
#include "DrawLayer.h"
#include "Miscellaneous.h"
#include "Timer.h"


#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

class DrawManager {
public:

	DrawManager();
	~DrawManager();
	void ThreadHandler();


	//window management
	void initWindow();
	void resizeWindow(unsigned int width, unsigned int height, bool _fullscreen, bool border);
	bool isWindowReady() const { return windowReady; };
	bool isWindowOpen() const { return windowOpen; };
	void close();

	//layers
	void addLayer(DrawLayer* layer);
	void addLayer(DrawLayer& layer);
	void setLayer(int, DrawLayer& layer);

	//get
	DrawLayer* getLayers() const { return *layers; };
	sf::RenderWindow* getWindow() { return window; };
	float getFps();

private:

	void draw();

	//window management
	HWND consoleWindow;
	sf::RenderWindow *window;
	bool windowReady;
	sf::Event event;
	bool windowOpen;

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
