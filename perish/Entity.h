#ifndef ENTITY_H
#define ENTITY_H

#include "Location.h"
#include <string>

class Entity {

private:

	// private data for the entity class
	Location _loc;
	std::string _name;
	unsigned int id;
	bool _movable;

public:
	Entity(Location &loc, std::string &name, bool movable);
	// Class constructor

};

#endif /* ENTITY_H */	