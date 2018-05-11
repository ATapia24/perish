#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <mutex>

enum DrawType {
	EMPTY,
	SPRITE,
	TEXT,
	RECTANGLE,
	CIRCLE,
	CONVEX
};

struct DrawObject {
	DrawType type;
	sf::Sprite *sprite;
	sf::Text *text;
	sf::RectangleShape *rectangle;
	sf::CircleShape *circle;
	sf::ConvexShape *convex;
};

class DrawBuffer
{
public:
	DrawBuffer();
	DrawBuffer(sf::View &_view);
	~DrawBuffer();

	int add(sf::Sprite &obj);
	int add(sf::Text &obj);
	int add(sf::RectangleShape &obj);
	int add(sf::CircleShape &obj);
	int add(sf::ConvexShape &obj);
	void remove(int i);

	inline unsigned int getSize() { return size; };
	inline unsigned const int getMaxSize() { return size; };
	inline DrawObject* getBuffer() { return buffer; };
	inline sf::View* getView() { return view; };

private:
	DrawObject *buffer;
	sf::View* view;
	const unsigned int BUFFER_SIZE = 10000;
	unsigned int size;

	void init();
};

