#ifndef BOX_H
#define BOX_H

#include "Entity.h"

class Box :
	public Entity
{
public:
	Box();
	~Box();
	void load(b2World* _physWorld, DrawBuffer& _layer);
	void update();
	void unload();
	//void beginContact(Entity* entity) {};
	//void endContact(Entity* entity) {};
	//bool postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse);
private:
	void _spawn();
	sf::Sprite sprite;
	sf::Texture texture;
	float size;
};

#endif