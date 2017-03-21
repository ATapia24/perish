#include "Location.h"

// default constructor
Location::Location() {

	x = 0.0;
	y = 0.0;

}

// Location for setting whatever
Location::Location(float _x, float _y) : 
	x(_x), y(_y) {}

float Location::getX() const {

	return x;

}

float Location::getY() const {

	return y;

}

void Location::setLocation(float _x, float _y) {

	x = _x;
	y = _y;

}

Location::~Location()
{
}

Location & Location::operator=(Location &location) {

	x = location.x;
	y = location.y;

	return *this;

}
