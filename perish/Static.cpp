#include "Static.h"

//CONSTRUCTOR
Static::Static()
{
	hitbox.setSize(sf::Vector2f(100, 1000));
	height = 10;
	width = 20;
	hitbox.setFillColor(sf::Color::White);
}

//DECONSTRUCTOR
Static::~Static()
{
}

//LOAD
void Static::load(b2World* _physWorld, DrawBuffer& _layer) {
	if (!loaded) {
		loaded = true;
		physWorld = _physWorld;
		layer = &_layer;
		type = STATIC;
		loadDefaults();

		width = 200;
		height = 20;
		density = 0.001f;
		physicsBodySetup();
		physicsBoxSetup(width, height);
		hitbox.setSize(sf::Vector2f(width, height));
		hitbox.setOrigin(sf::Vector2f(width / 2, height / 2));
		hitbox.setFillColor(sf::Color::White);
	}
}

//PHYSICS BODY SETUP
void Static::physicsBodySetup() {
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_staticBody;
	bodyDef->position = b2Vec2(spawnPoint.x, spawnPoint.y);
	bodyDef->angle = 0;

	body = physWorld->CreateBody(bodyDef);
	body->SetActive(false);
	body->SetUserData(this);

	fixtureDef = new b2FixtureDef();
	fixtureDef->density = density;
	fixtureDef->friction = friction;
}

//SPAWN
void Static::_spawn() {
	std::cout << spawnPoint.x << ' ' << spawnPoint.y << '\n';
	body->SetTransform(spawnPoint, 0);
	hitbox.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));
	layer->add(hitbox);
}