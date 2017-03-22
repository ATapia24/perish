#pragma once

#include "Entity.h"
#include <string>
#include <SFML/Graphics.hpp>

class Player : public Entity {

private:

	std::string name;

public:

	Player(std::string&);
	~Player();

	std::string getName() const;

};

