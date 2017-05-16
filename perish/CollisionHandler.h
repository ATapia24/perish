#pragma once

#include "Box2D.h"
#include "Entities.h"

class CollisionHandler : public b2ContactListener
{
public:
	CollisionHandler();
	~CollisionHandler();
	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact);
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void update();
private:
	const int MAX_REMOVES = 10000;
	Entity** removalArr;
	unsigned int n_removes;
	void addRemoval(Entity* entity);
};

