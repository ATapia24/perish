#pragma once
#include "Entity.h"
class Bot : public Entity {
public:
	Bot();
	~Bot();
	void load(b2World* _physWorld, DrawLayer& _layer);
	void update();
	void unload();
	void kill();
	void setTarget(b2Body* _target);
//	void beginContact(Entity* entity);
//	void endContact(Entity* entity);
private:
	float width, height;
	void _spawn();
	b2Body* target;
	b2Vec2 targetLastPosition;
	Controller controller;
	sf::RectangleShape rect;


};

