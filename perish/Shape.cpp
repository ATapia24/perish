/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   Shape.cpp
* Author: activates
*
* Created on March 15, 2017, 6:56 PM
*/

#include <iostream>
#include "Shape.h"

Shape::Shape(sf::CircleShape &_circle) :
	circle(_circle), type(ShapeType::CIRCLE) {}

Shape::Shape(sf::RectangleShape &_rect) :
	rect(_rect), type(ShapeType::RECTANGLE) {}

Shape::Shape(sf::ConvexShape &_conv) :
	conv(_conv), type(ShapeType::CONVEX) {}

Shape::Shape(const Shape& orig) {
}

Shape::~Shape() {
}

ShapeType Shape::getType() const {

	return type;

}

sf::CircleShape Shape::getCircle() const {

	return circle;

}

sf::RectangleShape Shape::getRectangle() const {

	return rect;

}

sf::ConvexShape Shape::getConvex() const {

	return conv;

}