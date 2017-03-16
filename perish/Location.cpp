#include "Location.h"

// Default constructor
Location::Location() : _x(0.0), _y(0.0), _world(NULL) {}

// Constructor to set more data..
Location::Location(double x, double y, std::string &world) : _x(x),
_y(y), _world(world) {}

// Used to retrieve the x coordinate
double Location::getX() const {
	return _x;
}

// used to retrieve the y coordinate
double Location::getY() const {
	return _y;
}

// Retrieves the world name
std::string Location::getWorld() const {
	return _world;
}

// Used to update a location easily
void Location::move(double x, double y) {
	_x += x;
	_y += y;
}

// Used to set the x coordinate
void Location::setX(double x) {
	_x = x;
}

// Used to set the y coordinate
void Location::setY(double y) {
	_y = y;
}