#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Location.h"

class WorldTile : public Entity {

private:

	// All stuff that is needed is contained
	// in the entity class

	// -- polymorphism YEAH!

public:

	// Constructors etc
	WorldTile();
	WorldTile(const float, const float, const sf::Texture&, const sf::Vector2f&);
	~WorldTile();

	sf::Sprite * getTile();

};

