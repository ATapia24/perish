#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <cstdlib>

class DrawLayer {
public:

	// Construction
	DrawLayer();
	~DrawLayer();

	// Add convex via pointer.. You must keep track
	// Of the sprite yourself so it can modify it
	int add(sf::Sprite*);
	int add(sf::Text*);
	int add(sf::CircleShape*);
	int add(sf::RectangleShape*);
	int add(sf::ConvexShape*);

	// Delete items via there index in the array
	void deleteSprite(int);
	void deleteText(int);
	void deleteCircle(int);
	void deleteRectangle(int);
	void deleteConvex(int);

	// get the various lists

	// For buffer size
	int getBufferSize() const;
	
	// SPRITES
	sf::Sprite ** getSprites() const;

	// TEXT
	sf::Text ** getTexts() const;

	// CIRCLES
	sf::CircleShape ** getCircles() const;

	// RECTANGLES
	sf::RectangleShape ** getRectangles() const;

	// CONVEXES
	sf::ConvexShape ** getConvexes() const;

	DrawLayer& operator=(DrawLayer&);

private:

	const int BUFFER_SIZE = 50;

	// Holds the sprites
	sf::Sprite **sprites;
	sf::Text **texts;
	sf::CircleShape **cshapes;
	sf::RectangleShape **rshapes;
	sf::ConvexShape **cnshapes;

};

