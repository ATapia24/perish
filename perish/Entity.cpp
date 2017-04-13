#include "Entity.h"

//CONSTRUCTOR
Entity::Entity() {
	//empty
}

//DECONSTRUCTOR
Entity::~Entity() {
	//empty
}

//LOAD
void Entity::load(b2World* _physWorld, DrawLayer& _layer) {
	physWorld = _physWorld;
	layer = &_layer;
}

//UNLOAD
void Entity::unload() {
	//empty
}

//UPDATE
void Entity::update() {
	//empty
}

//LOAD DEFAULTS
//Desc. initialize entity stuff with generic values
void Entity::loadDefaults() {
	layerIndex = -1;
	physicsParameters(0.1f, 1.0f, 4.0f, 4.0f);
	spawned = false;
	spawnPoint.SetZero();
	spawnRotation = 0.0f;
}

//PHYSICS SETUP
//Desc. setup physic basics for entity *note does not create a shape fixture
void Entity::physicsBodySetup() {
	//body definition
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->position = spawnPoint;
	
	//body
	body = physWorld->CreateBody(bodyDef);
	body->SetActive(false);
	body->SetUserData(this);
	body->SetLinearDamping(linearDamping);
	body->SetAngularDamping(angularDamping);
	
	//fixture
	fixtureDef = new b2FixtureDef();
	fixtureDef->density = density;
	fixtureDef->friction = friction;
}

//BOX SHAPE SETUP
//Desc. create and set fixture definition for a box
void Entity::physicsBoxSetup(float width, float height) {
	polyShape = new b2PolygonShape();
	polyShape->SetAsBox((width / 2) / misc::PHYSICS_SCALE, (height / 2) / misc::PHYSICS_SCALE);
	fixtureDef->shape = polyShape;
	body->CreateFixture(fixtureDef);
}

//CIRCLE SHAPE SETUP
//Desc. create and set fixture definition for a circle
void Entity::physicsCircleSetup(float radius) {
	circleShape = new b2CircleShape();
	circleShape->m_radius = radius / misc::PHYSICS_SCALE;
	fixtureDef->shape = circleShape;
	body->CreateFixture(fixtureDef);
}

//UNLOAD PHYSICS
//Desc. delete all new allocations related to box2d physics
void Entity::physicsDelete() {
	physWorld->DestroyBody(body);
	delete bodyDef;
	delete fixtureDef;
	if (polyShape != NULL)
		delete polyShape;
	if (circleShape != NULL)
		delete circleShape;
}

//PHYSICS PARAMTERS
//Desc. set physics parameters
void Entity::physicsParameters(float _density, float _friction, float _angularDamping, float _linearDamping) {
	density = _density;
	friction = _friction;
	angularDamping = _angularDamping;
	linearDamping = _linearDamping;
}

//SET POSITION
void Entity::setPosition(float x, float y) {
	body->SetTransform(b2Vec2(x, y), body->GetAngle());
}

//GET POSITION
b2Vec2 Entity::getPosition() {
	return body->GetPosition();
}

//SPAWN
void Entity::spawn() {
	spawned = true;
	body->SetActive(true);
	body->SetTransform(spawnPoint, spawnRotation);
	_spawn(); //call entity specific spawns function
}

//_SPAWN
//desc. do things that need to be done when entity is spawned that are entity specific *meant to be overridden
void Entity::_spawn() {
	//empty
}

//IS SPAWNED
bool Entity::isSpawned() {
	return spawned;
}

//SET SPAWN POINT w/ x and y
void Entity::setSpawnPoint(float x, float y, float rotation) {
	spawnPoint = b2Vec2(x, y);
	spawnRotation = rotation;
}

//SET SPAWN POINT w/ b2vec2
void Entity::setSpawnPoint(b2Vec2 _spawnPoint, float roatation) {
	spawnPoint = _spawnPoint; 
	spawnRotation = roatation;
	roatation;
}

//GET SPAWN POINT
b2Vec2 Entity::getSpawnPoint() {
	return spawnPoint;
}

//GET SPAWN ROTATION
float Entity::getSpawnRotation() {
	return spawnRotation;
}

//GET BODY
b2Body* Entity::getBody() {
	return body;
}