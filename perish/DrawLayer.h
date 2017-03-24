#pragma once

#include <SFML/Graphics.hpp>

class DrawLayer {
public:

	DrawLayer();
	~DrawLayer();

	// Add convex via pointer.. You must keep track
	// Of the sprite yourself so it can modify it
	int add(sf::Sprite* sprite);
	int add(sf::Text* text );
	int add(sf::CircleShape* circle );
	int add(sf::RectangleShape* rectangle);
	int add(sf::ConvexShape* convex);

	// Delete convexs via there index in the array
	void deleteConvex(int);

	// For buffer size
	int getBufferSize() const { return BUFFER_SIZE; };

	//get drawables
	sf::Sprite* getSprites() const { return *spriteArr; };
	sf::Text* getTexts() const { return *textArr; };
	sf::RectangleShape* getRectangles() const { return *rectangleArr; };
	sf::CircleShape* getCircles() const { return *circleArr; };
	sf::ConvexShape* getConvexes() const { return *convexArr; };

	//get set drawables
	uint8_t* getOpenSprites() const { return openSpriteArr; };
	uint8_t* getOpenTexts() const { return openTextArr; };
	uint8_t* getOpenRectangles() const { return openRectangleArr; };
	uint8_t* getOpenCircles() const { return openCircleArr; };
	uint8_t* getOpenConvexes() const { return openConvexArr; };

	DrawLayer& operator=(DrawLayer&);

private:

	const unsigned int BUFFER_SIZE = 1000;

	//drawable arrays
	sf::Sprite **spriteArr;
	sf::Text **textArr;
	sf::CircleShape **circleArr;
	sf::RectangleShape **rectangleArr;
	sf::ConvexShape **convexArr;
	
	//drawable open arrays
	uint8_t *openSpriteArr;
	uint8_t *openTextArr;
	uint8_t *openCircleArr;
	uint8_t *openRectangleArr;
	uint8_t *openConvexArr;
};

