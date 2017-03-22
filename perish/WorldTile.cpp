#include "WorldTile.h"

// construction!
WorldTile::WorldTile() : Entity(Location(0,0), false, sf::Sprite()) {

	// All the default settings in case it wasn't set

	sprite = sf::Sprite();

	sprite.setPosition(sf::Vector2f(0, 0));

}

WorldTile::WorldTile(const float height, const float width, const sf::Texture &texture, const sf::Vector2f &location) {

	sprite = sf::Sprite();

	sprite.setScale(sf::Vector2f(height, width));

	sprite.setPosition(location);
	sprite.setTexture(texture);

	// call the superclass' constructor
	Entity(Location(location.x, location.y), false, sprite);

}

WorldTile::~WorldTile() {}

// GET TILE
sf::Sprite * WorldTile::getTile() {

	return &sprite;

}