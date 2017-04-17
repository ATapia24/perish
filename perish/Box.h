#pragma once
#include "Entity.h"
class Box :
	public Entity
{
public:
	Box();
	~Box();
	void load(b2World* _physWorld, DrawLayer& _layer);
	void update();
	void unload();
private:
	void _spawn();
	sf::Sprite sprite;
	sf::Texture texture;
	float size;
};

