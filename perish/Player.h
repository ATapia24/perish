#pragma once

#include "Entity.h"
#include <string>

class Player : public Entity {

private:

	std::string name;


public:
	Player();
	~Player();

};

