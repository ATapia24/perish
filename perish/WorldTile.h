/*
 * This class is just for holding world tiles.. It gains most of its
 * functionality from the Entity class, so check that class to learn
 * this class' inner workings!
 */

#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class WorldTile : public Entity {

public:

	// A default constructor for the instances when we don't know
	// what sprite will be used as the tile!
	WorldTile();

	// Just some good ol' construction
	WorldTile(sf::Sprite&);
	~WorldTile();

};

