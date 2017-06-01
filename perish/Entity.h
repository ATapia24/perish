#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Miscellaneous.h"
#include "Box2D.h"
#include "DrawLayer.h"
#include "UserController.h"

enum EntityType {
	PLAYER,
	ENEMY,
	ITEM,
	STATIC,
	LIGHT,
	OTHER
};

class Entity {
public:

	Entity();
	virtual ~Entity();
	virtual void load(b2World* _physWorld, DrawLayer& _layer);
	virtual void update();
	virtual void unload();
	virtual void kill();
	b2Body* getBody();
	void setPosition(float x, float y);
	b2Vec2 getPosition();
	bool isSpawned();
	void spawn();
	void setSpawnPoint(float x, float y, float rotation);
	void setSpawnPoint(b2Vec2 _spawnPoint, float roatation);
	void physicsParameters(float _density, float _friction, float _angularDamping, float _linearDamping);
	virtual bool beginContact(Entity* entity, b2Contact* contact);
	virtual bool endContact(Entity* entity, b2Contact* contact);
	virtual bool preSolve(Entity* entity, b2Contact* contact, const b2Manifold* oldManifold);
	virtual bool postSolve(Entity* entity, b2Contact* contact, const b2ContactImpulse* impulse);
	b2Vec2 getSpawnPoint();
	float getSpawnRotation();
	EntityType getType() { return type; };
	b2PolygonShape* getPolyShape() { return polyShape; };
protected:
	DrawLayer* layer;
	b2World* physWorld;
	unsigned int layerIndex;
	EntityType type;
	virtual void loadDefaults();
	bool loaded;
	
	//physics
	b2Body* body;
	b2BodyDef* bodyDef;
	b2PolygonShape* polyShape;
	b2CircleShape* circleShape;
	b2FixtureDef* fixtureDef;
	virtual void physicsBodySetup();
	virtual void physicsCircleSetup(float radius);
	virtual void physicsBoxSetup(float width, float height);
	virtual void physicsDelete();
	float density;
	float friction;
	float angularDamping;
	float linearDamping;
	
	//spawn
	b2Vec2 spawnPoint;
	float spawnRotation;
	bool spawned = false;
	virtual void _spawn();

	//sprite and texture
	sf::Sprite sprite;
	sf::Texture texture;
};

class Target;
