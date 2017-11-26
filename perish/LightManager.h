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
	unsigned int index;
};

class LightManager : public Entity
{
public:
	LightManager();
	~LightManager();
	void set(Entity* _entity, DrawLayer& layer, b2World* _physWorld);
	void addObject(Entity* entity);
	void removeObject(int index);
	void update();
	bool beginContact(Entity* entity, b2Contact* contact);
	bool endContact(Entity* entity, b2Contact* contact);
	bool preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold);
	bool postSolve(b2Contact* contact, const b2ContactImpulse* impulse);

private:
	DrawLayer *layer;
	Entity* player;
	b2Vec2 center;
	float rotation;
	b2Vec2 lastCenter;
	float lastRotation;

	Blocker* blockers;
	int n_blockers;
	const int max_blockers = 10000;
	const float PL_DISTANCE = FLT_MAX_EXP;

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
	float widthOrginOffset, heightOrginOffset;

	b2World* physWorld;
	b2Body* body;
	b2CircleShape* circleShape;
	b2FixtureDef* fixtureDef;
	b2BodyDef* bodyDef;
	sf::CircleShape circle;

};

