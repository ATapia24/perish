/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   Shape.h
* Author: activates
*
* Created on March 15, 2017, 6:56 PM
*/

#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

enum class ShapeType { CIRCLE, RECTANGLE, CONVEX };

class Shape {

public:

	Shape(sf::CircleShape&);
	Shape(sf::RectangleShape&);
	Shape(sf::ConvexShape&);
	Shape(const Shape& orig);
	virtual ~Shape();

	ShapeType getType() const;

	sf::CircleShape getCircle() const;
	sf::RectangleShape getRectangle() const;
	sf::ConvexShape getConvex() const;

private:

	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::ConvexShape conv;

	ShapeType type;

};

#endif /* SHAPE_H */
