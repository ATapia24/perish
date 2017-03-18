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
	
	nodeX = 50;
	nodeY = 50;

	topLeftNode = &worldMesh[nodeY][nodeX];
	topRightNode = &worldMesh[nodeY][nodeX+1];
	bottomLeftNode = &worldMesh[nodeY+1][nodeX];
	bottomRightNode = &worldMesh[nodeY+1][nodeX+1];

	tln = &node1;
	trn = &node2;
	bln = &node3;
	brn = &node4;

	topLeftNode->load(window, nodeX, nodeY);
	topRightNode->load(window, nodeX, nodeY+1);
	bottomLeftNode->load(window, nodeX+1, nodeY);
	bottomRightNode->load(window, nodeX+1, nodeY+1);

	window->getWorldView()->setCenter(nodeX * nodeWidth * window->getScale().x, nodeY * nodeHeight * window->getScale().y);
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
	topLeftNode->draw();
	topRightNode->draw();
	bottomLeftNode->draw();
	bottomRightNode->draw();
	
	if (0)
	{
		window->addWorld(*tln);
		window->addWorld(*trn);
		window->addWorld(*bln);
		window->addWorld(*brn);
	}
}


void World::calculateNodes()
{
	sf::Vector2f center = sf::Vector2f(worldView->getCenter().x * ( 1 / window->getScale().x), worldView->getCenter().y * (1 / window->getScale().y));	
	//left and right
	if (center.x > trn->getPosition().x + (nodeWidth / 2)) {
		tln->move(nodeWidth*2, 0);
		bln->move(nodeWidth * 2, 0);
		tln->setFillColor(misc::randomColor());
		bln->setFillColor(misc::randomColor());
		//misc::swap(topLeftNode, topRightNode);
		//misc::swap(bottomLeftNode, bottomRightNode);
		misc::swap(tln, trn);
		misc::swap(bln, brn);
		nodeX++;
	} else if (center.x < tln->getPosition().x + (nodeWidth / 2)) {
		trn->move(-nodeWidth*2, 0);
		brn->move(-nodeWidth * 2, 0);
		trn->setFillColor(misc::randomColor());
		brn->setFillColor(misc::randomColor());
		//misc::swap(topLeftNode, topRightNode);
		//misc::swap(bottomLeftNode, bottomRightNode);
		misc::swap(tln, trn);
		misc::swap(bln, brn);
		nodeX--;
	}

	//up and down
	if (center.y < tln->getPosition().y + (nodeHeight / 2)) {
		bln->move(0, -nodeHeight * 2);
		brn->move(0, -nodeHeight * 2);
		bln->setFillColor(misc::randomColor());
		brn->setFillColor(misc::randomColor());
		//misc::swap(topLeftNode, bottomLeftNode);
		//misc::swap(topRightNode, bottomRightNode);
		misc::swap(tln, bln);
		misc::swap(trn, brn);
		nodeY--;
	}
	else if (center.y > bln->getPosition().y + (nodeHeight / 2)) {
		tln->move(0, nodeHeight * 2);
		trn->move(0, nodeHeight * 2);
		tln->setFillColor(misc::randomColor());
		trn->setFillColor(misc::randomColor());
		//misc::swap(topLeftNode, bottomLeftNode);
		//misc::swap(topRightNode, bottomRightNode);
		misc::swap(tln, bln);
		misc::swap(trn, brn);
		nodeY++;
	}
}
