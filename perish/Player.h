#pragma once
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
private:
	float speed = 5.f;
	float rotationSpeed = 0.1f;
	sf::View* view;
	const int VIEW_OFFSET = 200;
	sf::CircleShape circleHitbox;
	UserController controller;
	void _spawn();
};

