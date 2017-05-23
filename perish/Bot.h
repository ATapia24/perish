#pragma once
#include "Entity.h"
#include "Target.h"

class Bot : public Entity {
public:
	Bot();
	~Bot();
	void load(b2World* _physWorld, DrawLayer& _layer);
	void update();
	void unload();
	void kill();
	virtual bool beginContact(Entity* entity, b2Contact* contact);
	virtual bool endContact(Entity* entity, b2Contact* contact);
	virtual bool preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold);
	virtual bool postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse);

	//target
	Waypoint& getTarget() { return target; };

private:
	float width, height;
	void _spawn();

	//target
	Waypoint target;
	
	Controller controller;
	sf::RectangleShape rect;


};

