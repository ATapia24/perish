#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "InputManager.h"
#include "WorldNode.h"

class World {
private:
	WindowManager* window;
	sf::View* worldView;
	Key up, down, left, right;

	//world nodes - TODO: make a WorldNodes class
	void calculateNodes();
	sf::RectangleShape node1, node2, node3, node4;
	sf::RectangleShape *trn, *tln, *bln, *brn;
	WorldNode* topLeftNode, *topRightNode, *bottomLeftNode, *bottomRightNode;
	WorldNode worldMesh[100][100];
	int nodeX, nodeY;
	float nodeWidth = 1920.f;
	float nodeHeight = 1080.f;

	
public:
	World();
	World(WindowManager* _window);
	~World();
	void load();
	void update();
	void draw();
private:
};

#endif
