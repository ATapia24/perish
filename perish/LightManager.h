#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Miscellaneous.h"
#include "DrawLayer.h"
#include "Box2D.h"
#include "Entities.h"
#include "Timer.h"

struct  Blocker
{
	Entity* entity;
	sf::Vector2f points[4];
	b2Vec2 lastPosition;
};

class LightManager
{
public:
	LightManager();
	~LightManager();
	void set(DrawLayer* _layer, Entity* _entity);
	void addObject(Entity* entity);
	void update();

private:
	DrawLayer *layer;
	Entity* player;
	b2Vec2 center;
	float rotation;
	b2Vec2 lastCenter;
	float lastRotation;

	Blocker* blockers;
	int n_blockers;
	const int max_blockers = 100000;
	const int PL_DISTANCE = 1000000;

	bool containsMovables;
	void calculateBlocker(Blocker& blocker);
	sf::VertexArray points;
	int pcount;
	sf::Color blockerColor;


	sf::RenderTexture renderTexture;
	sf::View view;
	sf::Texture lightTexture;
	sf::Sprite light, lightMap;
	float renderScale;
	sf::RectangleShape lightHitbox;
	float width, height;
};

