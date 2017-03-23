/*
 * This class holds one tile for world building. There is not much
 * different about this compared to the Entity class. This class
 * doesn't delete anything, so you must delete it yourself
 */

#pragma once

#include "Entity.h"

class WorldTile : public Entity {

public:
	
	WorldTile(sf::Sprite*);
	~WorldTile();

};

