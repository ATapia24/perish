#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Box2D.h"
#include "Entities.h"
#include "PerfArray.h"

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
	PerfArray<Entity*> removalArr;
	void addRemoval(Entity* entity);
};

#endif