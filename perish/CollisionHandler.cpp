#include "CollisionHandler.h"


//CONSTRUCTOR
CollisionHandler::CollisionHandler()
{
	removalArr = new Entity*[MAX_REMOVES];
	n_removes = 0;
}

//DECONSTRUCTOR
CollisionHandler::~CollisionHandler()
{
	delete[] removalArr;
}

//UPDATE
//desc. kill all entities that need to be deleted
void CollisionHandler::update() {
	for (unsigned int i = 0; i < n_removes; i++) {
		removalArr[i]->kill();
	}

	n_removes = 0;
}

//START CONTACT
//desc. called when two objects collide
void CollisionHandler::BeginContact(b2Contact* contact) {
	
	//get entities from contact user data
	Entity* a = static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Entity* b = static_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	//a
	if (a->beginContact(b, contact)) {
		addRemoval(a);
	}

	//b
	if (b->beginContact(a, contact)) {
		addRemoval(b);
	}
}

//END CONTACT
void CollisionHandler::EndContact(b2Contact* contact) {
	//get entities from contact user data
	Entity* a = static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Entity* b = static_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	//a
	if (a->endContact(b, contact)) {
		addRemoval(a);
	}

	//b
	if (b->endContact(a, contact)) {
		addRemoval(b);
	}
}

//PRE SOLVE
//desc. function called right before a collision
void CollisionHandler::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
	//get entities from contact user data
	Entity* a = static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Entity* b = static_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	//a
	if (a->preSolve(b, contact, oldManifold)) {
		addRemoval(a);
	}

	//b
	if (b->preSolve(a, contact, oldManifold)) {
		addRemoval(b);
	}
}

//POST SOLVE
//desc. function called after collision *recommend to do collision based logic here
void CollisionHandler::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
	//get entities from contact user data
	Entity* a = static_cast<Entity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	Entity* b = static_cast<Entity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	//a
	if (a->postSolve(b, contact, impulse)) {
		addRemoval(a);
	}

	//b
	if (b->postSolve(a, contact, impulse)) {
		addRemoval(b);
	}
}

//ADD TO BE REMOVED
//desc. add body to be removed after physics step
void CollisionHandler::addRemoval(Entity* e) {
	removalArr[n_removes] = e;
	n_removes++;
}