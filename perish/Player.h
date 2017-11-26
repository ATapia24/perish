#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
class Player :
	public Entity
{
public:
	Player();
	~Player();
	void load(sf::View* _view, b2World* _physWorld, DrawLayer& _layer);
	void update();
	void unload();
	virtual bool beginContact(Entity* entity, b2Contact* contact);
	virtual bool endContact(Entity* entity, b2Contact* contact);
	virtual bool preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold);
	virtual bool postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse);
private:
	float speed = 5.f;
	float rotationSpeed = 0.1f;
	sf::View* view;
	const int VIEW_OFFSET = 200;
	sf::Sprite circleHitbox;
	UserController controller;
	void _spawn();
};

#endif