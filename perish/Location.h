#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {

private:

	// Holds the data on where the user actually stands in the world
	double _x, _y;
	std::string _world;

public:

	Location();
	// default constructor
	Location(double x, double y, std::string &world);
	// Constructor just for defining all of the class data members
	double getX() const;
	// Retrieves the x coordinate
	double getY() const;
	// Retrieves the y coordinate
	std::string getWorld() const;
	// Retrieves the world name
	void move(double x, double y);
	// Used to update a location easily
	void setX(double x);
	// Used to set the x coordinate
	void setY(double y);
	// used to set the y coordinate
};

#endif /* LOCATION_H */