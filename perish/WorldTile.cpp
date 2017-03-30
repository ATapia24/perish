#include "WorldTile.h"

WorldTile::WorldTile() :
	WorldObject(sf::Sprite(), WorldObjectType::TILE) {}

WorldTile::WorldTile(sf::Sprite &_sprite, const int _x, const int _y) :
	WorldObject(_sprite, WorldObjectType::TILE), x(_x), y(_y) {}

WorldTile::~WorldTile() {}

int WorldTile::getX() const {
	return x;
}

int WorldTile::getY() const {
	return y;
}