#pragma once
#include "Entity.h"
class Bot : public Entity {
public:
	Bot();
	~Bot();
	void load(b2World* _physWorld, DrawLayer& _layer);
	void update();
	void unload();
	void setTarget(b2Body* _target);
private:
	int size;
	void _spawn();
	b2Body* target;


};

