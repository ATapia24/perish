/*

An extention of the WorldObject type. This object type must snap
to a location on the grid whilst the WorldFloat can go anywhere it
wants.

*/

#pragma once

#include "WorldObject.h"

class WorldTile : public WorldObject {

private:

	// stores the coordinates of this tile within the world
	int x, y;

public:

	WorldTile();
	WorldTile(sf::Sprite&, const int, const int);
	~WorldTile();

	// getters for the coordinates within the world array
	int getX() const;
	int getY() const;

};

