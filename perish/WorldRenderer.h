/*

This class takes worlds and renders them. Basically it is just something
that builds/managers layers that can be passed to the DrawManager!

*/

#pragma once

#include <SFML/Graphics.hpp>

#include "World.h"
#include "DrawLayer.h"

class WorldRenderer {

private:

	// Holds the world that is being rendered
	World world;

public:

	WorldRenderer();
	WorldRenderer(World&);
	~WorldRenderer();

	// Setters
	void setWorld(World&);

	// getters
	World & getWorld();

	// Builds a layer for the world you currently have
	DrawLayer buildLayer();

};

