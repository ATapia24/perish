#include "WorldTile.h"

WorldTile::WorldTile() :
	Entity(sf::Sprite(), false) {}

WorldTile::WorldTile(sf::Sprite &_sprite) :
	Entity(_sprite, false) {}

WorldTile::~WorldTile() {}
