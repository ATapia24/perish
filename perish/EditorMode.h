#ifndef EDITORMODE_H
#define EDITORMODE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Renderer.h"
#include "InputManager.h"
#include "Timer.h"
#include "DrawBuffer.h"
#include <vector>
#include <mutex>

class EditorMode
{
public:
	EditorMode();
	EditorMode(Renderer *_renderer);
	~EditorMode();
	void load();
	void update();
private:
	bool loaded;
	Renderer *renderer;

	DrawBuffer *floor;
	sf::Sprite grid;
	sf::Texture gridTexture;
	int gridIndex;
	const int GRID_SIZE = 200000.f;

	//input
	Key_M leftClick, rightClick;
	Key up, down, left, right, rotateLeft, rotateRight;

	//camera
	sf::View camera;
	float moveSpeed = 0.000001f;
	float rotateSpeed = 0.0000000035f;
	float angle;
	Timer dtTimer;
	float dt;

	std::vector<sf::RectangleShape*> cubes;
};

#endif