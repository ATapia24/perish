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
	//void beginContact(Entity* entity) {};
	//void endContact(Entity* entity) {};
private:
	void _spawn();
	sf::Sprite sprite;
	sf::Texture texture;
	float size;
};

