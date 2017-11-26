#ifndef STATIC_H
#define STATIC_H

#include "Entity.h"
#include <iostream>

class Static :
	public Entity
{
public:
	Static();
	~Static();
	void load(b2World* _physWorld, DrawLayer& _layer);

private:
	void physicsBodySetup();
	void _spawn();
	sf::RectangleShape hitbox;
	int height, width;
};

#endif