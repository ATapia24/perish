#include "Target.h"


//CONSTRUCTOR
Waypoint::Waypoint(){
	type = TargetType::NONE;
}

//DECONSTRUCTOR
Waypoint::~Waypoint(){

}

//GET TARGET POINT
b2Vec2 Waypoint::getTargetPoint() {
	switch (type)
	{
	case _POINT:
		return *pointTarget;
	case BODY:
		return bodyTarget->GetPosition();
	case _STATIC:
		return staticPointTarget;
	default:
		return b2Vec2(0, 0);
	}
}

//SET TARGET W/ POINT PTR
void Waypoint::setTarget(b2Vec2* point) {
	pointTarget = point;
	type = TargetType::_POINT;
}

//SET TARGET W/ POINT BY REF
void Waypoint::setTarget(b2Vec2& point) {
	pointTarget = &point;
	type = TargetType::_POINT;
}

//SET TARGET W/ BODY BY REF
void Waypoint::setTarget(b2Body& body) {
	bodyTarget = &body;
	type = TargetType::BODY;
}

//SET TARGET W/ BODY PTR
void Waypoint::setTarget(b2Body* body) {
	bodyTarget = body;
	type = TargetType::BODY;
}

//SET STATIC TARGET W/ POINT
void Waypoint::setStaticTarget(b2Vec2 point) {
	staticPointTarget = point;
	type = TargetType::_STATIC;
}

//SET STATIC TARGET W/ POINT PTR
void Waypoint::setStaticTarget(b2Vec2* point) {
	staticPointTarget = *point;
	type = TargetType::_STATIC;
}

//SET STATIC TARGET W/ BODY PTR
void Waypoint::setStaticTarget(b2Body* body) {
	staticPointTarget = body->GetPosition();
	type = TargetType::_STATIC;
}


//SET STATIC TARGET W/ BODY
void Waypoint::setStaticTarget(b2Body& body) {
	staticPointTarget = body.GetPosition();
	type = TargetType::_STATIC;
}
