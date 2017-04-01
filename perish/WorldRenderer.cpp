#include "WorldRenderer.h"

// Default constructor
WorldRenderer::WorldRenderer() : world(World("Default", 1, 1, 1)) {}

// Better constructor
WorldRenderer::WorldRenderer(World &_world) :
	world(_world) {}

WorldRenderer::~WorldRenderer() {}

// setters
void WorldRenderer::setWorld(World &_world) {
	world = _world;
}

// getters
World & WorldRenderer::getWorld() {
	return world;
}

// Used for building a layer to display the world
DrawLayer WorldRenderer::buildLayer() {

	DrawLayer temp;

	// add all the floats first.. because those are easy
	for (int i = 0; i < world.getMaxFloats(); i++) {
		if (world.getOpenFloats()[i] == 0) {
			temp.add(&world.getWorldFloats()[i].getSprite());
		}
	}

	// now for the tiles..
	for (int x = 0; x < world.getMaxX(); x++) {

		for (int y = 0; y < world.getMaxY(); y++) {

			world.getWorldTiles()[x][y].getSprite().setPosition(x * world.getDimX(), y * world.getDimY());

			temp.add(&world.getWorldTiles()[x][y].getSprite());

		}

	}

	return temp;

}