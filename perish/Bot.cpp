#include "Bot.h"



Bot::Bot()
{
}


Bot::~Bot()
{
}

void Bot::load(b2World* _physWorld, DrawLayer& _layer) {

	if (!loaded) {
		loaded = true;
		physWorld = _physWorld;
		layer = &_layer;
		type = ENEMY;
		loadDefaults();

		width = 20;
		height = 20;
		density = 0.001f;
		physicsBodySetup();
		physicsBoxSetup(width, height);
		controller.load(body, 1.f, 5.f);

		texture.loadFromFile("assets/topdown.png");
		sprite.setTexture(texture);
		sprite.setColor(misc::randomColor());
		sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2.f, texture.getSize().y / 2.f));
		sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
		rect.setSize(sf::Vector2f(width, height));
		rect.setOrigin(sf::Vector2f(width / 2, height / 2));
	}
}

//UPDATE
void Bot::update() {

//	controller.update();

	if (spawned) {
		//look at target
		if (target != NULL) {
			float targetAngle = -misc::lineAngle(body->GetPosition(), target->GetPosition()) + misc::PIh;
		//	std::cout << targetAngle * misc::RAD2DEG << '\n';
			body->SetTransform(body->GetPosition(), targetAngle);
			targetLastPosition = target->GetPosition();
		}

		if (true) {
			float32 angle = body->GetAngle() + misc::PI;
			body->ApplyLinearImpulseToCenter(0.0000053f * b2Vec2(-sin(angle), cos(angle)), true);
			angle += misc::PIh;
			//body->ApplyLinearImpulseToCenter(0.000033f * b2Vec2(-sin(angle), cos(angle)), true);
		}

		sprite.setPosition(sf::Vector2f(body->GetPosition().x * misc::PHYSICS_SCALE, body->GetPosition().y * misc::PHYSICS_SCALE));
		sprite.setRotation(body->GetAngle() * misc::RAD2DEG + 180.f);
	}
}

//UNLOAD
void Bot::unload() {

}

//SET TARGET
void Bot::setTarget(b2Body* _target) {
	if (_target != NULL) {
		target = _target;
	}
}

//SPAWN
void Bot::_spawn() {
	body->SetTransform(spawnPoint, spawnRotation);
	update();
	layerIndex = layer->add(sprite);
	spawned = true;
}

//KILL
void Bot::kill() {
	if (spawned) {
		spawned = false;
		layer->remove(layerIndex);
		body->SetActive(false);
	}
}

//START CONTACT
/*void Bot::beginContact(Entity* entity) {
	std::cout << "entity start contact\n";
}

//END CONTACT
void Bot::endContact(Entity* entity) {
	std::cout << "entity end contact\n";
}*/