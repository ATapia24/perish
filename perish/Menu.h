#ifndef MENU_H
#define MENU_H

#include <SFML\Graphics.hpp>
#include <stdarg.h>
#include <string>
#include <iostream>
#include "Timer.h"
#include "DrawLayer.h"

class Menu
{
public:
	Menu();
	Menu(DrawLayer& _layer, unsigned int _x, unsigned int _y, unsigned int _width);
	~Menu();
	void add(std::string& text);
	void addLiteral(std::string text);
	void next();
	void prev();
	void indexChange(int select);
	unsigned int selected();
	void reshape();
	void update();

	//sets
	void setPosition(float _x, float _y);
	void setSize(float _height, float _width);
	void setPadding(float top, float bottom, float left, float right);
	void setSpacing(float _spacing);
	void setFontColor(sf::Color color);
	void setSelectedFontColot(sf::Color color);
	void setBackgroundColor(sf::Color color);
	void setUpdateRate(unsigned int _updateRate);

private: 
	DrawLayer* layer;
	const int MAX_ITEMS = 32;
	unsigned int size;
	float x, y;
	float height, width, spacing;
	float topPadding, bottomPadding, leftPadding, rightPadding;
	sf::Font font;
	unsigned int fontSize;
	sf::Color fontColor, selectedFontColor, backgroundColor;
	sf::RectangleShape background;

	
	//indexes
	unsigned int index;
	unsigned int lastIndex;


	//arrays
	sf::Text* textArr;
	std::string** stringArr;
	Timer updateTimer;
	unsigned int updateRate;
};

#endif