#pragma once

#include<SFML/Graphics.hpp>
#include<list>

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
	sf::Sprite * getSprites() const;
	uint8_t * getSetSprites() const;

	// TEXT
	sf::Text * getTexts() const;
	uint8_t * getSetTexts() const;

	// CIRCLES
	sf::CircleShape * getCircles() const;
	uint8_t * getSetCircles() const;

	// RECTANGLES
	sf::RectangleShape * getRectangles() const;
	uint8_t * getsetRectangles() const;

	// CONVEXES
	sf::ConvexShape * getConvexes() const;
	uint8_t * getSetConvexes() const;

	DrawLayer& operator=(DrawLayer&);

private:

	const int BUFFER_SIZE = 10;

	// Holds the sprites
	sf::Sprite **sprites;
	sf::Text **texts;
	sf::CircleShape **cshapes;
	sf::RectangleShape **rshapes;
	sf::ConvexShape **cnshapes;

	uint8_t *openSprites;
	uint8_t *openTexts;
	uint8_t *openCircs;
	uint8_t *openRects;
	uint8_t *openConvs;

};

