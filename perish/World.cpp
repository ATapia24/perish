#include "World.h"

World::World() {
;
}

World::World(WindowManager * _window) {
	window = _window;
	worldView = _window->getWorldView();
	up.set(sf::Keyboard::Key::W, KeyType::REPEATED);
	down.set(sf::Keyboard::Key::S, KeyType::REPEATED);
	left.set(sf::Keyboard::Key::A, KeyType::REPEATED);
	right.set(sf::Keyboard::Key::D, KeyType::REPEATED);

}

World::~World() {
}


void World::load() {
	node1.setSize(sf::Vector2f(1920, 1080));
	node2.setSize(sf::Vector2f(1920, 1080));
	node3.setSize(sf::Vector2f(1920, 1080));
	node4.setSize(sf::Vector2f(1920, 1080));
	node1.setFillColor(sf::Color::Red);
	node2.setFillColor(sf::Color::Green);
	node3.setFillColor(sf::Color::Blue);
	node4.setFillColor(sf::Color::Yellow);
	node1.setPosition(sf::Vector2f(-nodeWidth / 2, -nodeHeight / 2));
	node2.setPosition(sf::Vector2f(nodeWidth / 2, -nodeHeight / 2));
	node3.setPosition(sf::Vector2f(-nodeWidth / 2, nodeHeight / 2));
	node4.setPosition(sf::Vector2f(nodeWidth / 2, nodeHeight / 2));
	topLeftNode = &node1;
	topRightNode = &node2;
	bottomLeftNode = &node3;
	bottomRightNode = &node4;
	nodeX = 0;
	nodeY = 0;
}

void World::update() {

	//temp
	float m_speed = 1.f;
	if (up.getValue())
		worldView->move(sf::Vector2f(0, -m_speed));
	else if (down.getValue())
		worldView->move(sf::Vector2f(0, m_speed));
	if (left.getValue())
		worldView->move(sf::Vector2f(-m_speed, 0));
	else if (right.getValue())
		worldView->move(sf::Vector2f(m_speed, 0));

	calculateNodes();
}

void World::draw() {
	window->addWorld(node1);
	window->addWorld(node2);
	window->addWorld(node3);
	window->addWorld(node4);
}


void World::calculateNodes()
{
	sf::Vector2f center = sf::Vector2f(worldView->getCenter().x * ( 1 / window->getScale().x), worldView->getCenter().y * (1 / window->getScale().y));

	//left and right
	if (center.x > topRightNode->getPosition().x + (nodeWidth / 2)) {
		topLeftNode->move(nodeWidth*2, 0);
		bottomLeftNode->move(nodeWidth * 2, 0);
		topLeftNode->setFillColor(misc::randomColor());
		bottomLeftNode->setFillColor(misc::randomColor());
		misc::swap(topLeftNode, topRightNode);
		misc::swap(bottomLeftNode, bottomRightNode);
		nodeX++;
	} else if (center.x < topLeftNode->getPosition().x + (nodeWidth / 2)) {
		topRightNode->move(-nodeWidth*2, 0);
		bottomRightNode->move(-nodeWidth * 2, 0);
		topRightNode->setFillColor(misc::randomColor());
		bottomRightNode->setFillColor(misc::randomColor());
		misc::swap(topLeftNode, topRightNode);
		misc::swap(bottomLeftNode, bottomRightNode);
		nodeX--;
	}

	//up and down
	if (center.y < topLeftNode->getPosition().y + (nodeHeight / 2)) {
		bottomLeftNode->move(0, -nodeHeight * 2);
		bottomRightNode->move(0, -nodeHeight * 2);
		bottomLeftNode->setFillColor(misc::randomColor());
		bottomRightNode->setFillColor(misc::randomColor());
		misc::swap(topLeftNode, bottomLeftNode);
		misc::swap(topRightNode, bottomRightNode);
		nodeY--;
	}
	else if (center.y > bottomLeftNode->getPosition().y + (nodeHeight / 2)) {
		topLeftNode->move(0, nodeHeight * 2);
		topRightNode->move(0, nodeHeight * 2);
		topLeftNode->setFillColor(misc::randomColor());
		topRightNode->setFillColor(misc::randomColor());
		misc::swap(topLeftNode, bottomLeftNode);
		misc::swap(topRightNode, bottomRightNode);
		nodeY++;
	}
}
