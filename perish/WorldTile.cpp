#include "WorldTile.h"

WorldTile::WorldTile() : 
	Entity(new sf::Sprite(), true) {}

WorldTile::WorldTile(sf::Sprite *_sprite) :
	Entity(_sprite, false) {}

WorldTile::~WorldTile() {}
