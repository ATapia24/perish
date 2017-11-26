#ifndef TARGET_H
#define TARGET_H

#include "Box2D.h"
#include <iostream>

class Entity;

enum TargetType {
	ENTITY,
	_POINT,
	BODY,
	_STATIC,
	NONE
};

class Waypoint
{
public:
	Waypoint();
	~Waypoint();
	void setTarget(b2Vec2& point);
	void setTarget(b2Vec2* point);
	void setTarget(b2Body& body);
	void setTarget(b2Body* body);
	void setStaticTarget(b2Vec2 point);
	void setStaticTarget(b2Vec2* point);
	void setStaticTarget(b2Body* body);
	void setStaticTarget(b2Body& body);
	b2Vec2 getTargetPoint();
private:
	TargetType type;
	b2Body* bodyTarget;
	b2Vec2* pointTarget;
	b2Vec2 staticPointTarget;
	bool isActive = true;
};

#endif
