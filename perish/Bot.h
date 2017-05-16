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
	virtual bool beginContact(Entity* entity, b2Contact* contact);
	virtual bool endContact(Entity* entity, b2Contact* contact);
	virtual bool preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold);
	virtual bool postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse);
private:
	float width, height;
	void _spawn();
	b2Body* target;
	b2Vec2 targetLastPosition;
	Controller controller;
	sf::RectangleShape rect;


};

