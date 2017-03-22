#pragma once

#include "Entity.h"
#include "Location.h"
#include <string>
#include <SFML/Graphics.hpp>

class Player : public Entity {

private:

	std::string name;

public:

	Player(std::string&, Location&, sf::Sprite&);
	~Player();

	std::string getName() const;

};

