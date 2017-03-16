#include "Entity.h"

// Initializing values with the constructor
Entity::Entity(Location &loc, std::string &name, bool movable) :
	_loc(loc), _name(name), _movable(movable) {}