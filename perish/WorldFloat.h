/*

A WorldFloat is an object that can be anywhere in the particular world,
and it doesn't have to snap to a grid. You can use this object if you
want to place an object that is larger than the grid (like a house, or
a big tree)

*/

#pragma once

#include "WorldObject.h"

class WorldFloat : public WorldObject {

private:

public:

	WorldFloat();
	~WorldFloat();

};

