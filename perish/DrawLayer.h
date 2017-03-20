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
	int addConvex(sf::ConvexShape*);

	// Delete convexs via there index in the array
	void deleteConvex(int);

	// get the various lists

	// For buffer size
	int getBufferSize();

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

