#include "WorldNode.h"

//CONSTRUCTOR
WorldNode::WorldNode() {
}

//CONSTRUCTOR W/ X AND Y
WorldNode::WorldNode(WindowManager* _window, int _x, int _y) {
    window = _window;
    x = _x;
    y = _y;
    loaded = 0;
}

//DECONSTRUCTOR
WorldNode::~WorldNode() {
    loaded = 0;
}

//LOAD
void WorldNode::load(WindowManager* _window, int _x, int _y) {
    loaded = 1;
	window = _window;
	x = _x;
	y = _y;
    bg.setFillColor(misc::randomColor());
    bg.setSize(sf::Vector2f(width, height));
	bg.setPosition(sf::Vector2f(width * x, height * y));
}

//UNLOAD UNLOAD
void WorldNode::unload() {
    loaded = 0;
}

//UPDATE
void WorldNode::update() {
    //do stuff here
}

//DRAW
void WorldNode::draw() {
    window->addWorld(bg);
}

