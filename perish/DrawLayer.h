#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum DrawType {
	EMPTY,
	SPRITE,
	RECTANGLE,
	TEXT,
	CIRCLE,
	CONVEX,
	VERTEX_ARRAY
};

struct DrawObject {
	DrawType type;
	sf::Sprite* sprite;
	sf::RectangleShape* rectangle;
	sf::Text *text;
	sf::CircleShape *circle;
	sf::ConvexShape* convex;
	sf::VertexArray* vertexArray;
};

class DrawLayer {
public:

	DrawLayer();
	~DrawLayer();

	//int is the position of the DrawObject in the array, keep track of it
	int add(sf::Sprite* sprite);
	int add(sf::Text* text );
	int add(sf::CircleShape* circle );
	int add(sf::RectangleShape* rectangle);
	int add(sf::ConvexShape* convex);
	void remove(int index);
	unsigned int getSize() { return size; };
	void cleanup();

	int getBufferSize() const { return BUFFER_SIZE; };
	DrawObject** getDrawObjects() const { return drawObjects; };
	DrawLayer& operator=(DrawLayer&);

private:

	const unsigned int BUFFER_SIZE = 5000;
	DrawObject **drawObjects;
	unsigned int size;
};

