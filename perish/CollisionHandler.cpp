#include "CollisionHandler.h"


//CONSTRUCTOR
CollisionHandler::CollisionHandler()
{
}

//DECONSTRUCTOR
CollisionHandler::~CollisionHandler()
{
}

//START CONTACT
//desc. called when two objects collide
void CollisionHandler::BeginContact(b2Contact* contact) {
	Entity* a = static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Entity* b = static_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData());


	if (a->getType() == EntityType::ENEMY) {
	//	static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData())->kill();
	}

//	std::cout << "collision begin: " << a->getType() << ' ' << b->getType() << '\n';
}

//END CONTACT
void CollisionHandler::EndContact(b2Contact* contact) {
	Entity* a = static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Entity* b = static_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData());

}

//PRE SOLVE
//desc. function called right before a collision
void CollisionHandler::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {

}

//POST SOLVE
//desc. function called after collision *recommend to do collision based logic here
void CollisionHandler::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {

}