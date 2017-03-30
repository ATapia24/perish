/*

An extention of the WorldObject type. This object type must snap
to a location on the grid whilst the WorldFloat can go anywhere it
wants.

*/

#pragma once

#include "WorldObject.h"

class WorldTile : public WorldObject {

public:

	WorldTile();
	WorldTile(sf::Sprite&, const int, const int);
	~WorldTile();

};

