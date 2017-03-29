/*

This class serves as a base for every single object being displayed
in the world. We just store simple things like type and a location
(different from the Vector2f that SFML uses although we will still
be using their type for screen positioning)

*/

#pragma once

#include <SFML/Graphics.hpp>

enum class WorldObjectType {
	TILE,
	FLOATING
};

class WorldObject {

private:

	// Used for determining the type of world object this is
	WorldObjectType type;

	// The sprite! Represents a lot of things
	sf::Sprite sprite;

public:

	// Constructors n' stuff
	
	// I am using pass by reference, so we can create a copy of the sprite
	// To use for the World Object
	WorldObject(sf::Sprite&, WorldObjectType);
	~WorldObject();

	// A few getters (We don't need any setters because we will be using
	// return by reference)
	virtual sf::Sprite & getSprite();
	virtual WorldObjectType getType() const;

};

