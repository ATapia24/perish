#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum DrawType {
	EMPTY,
	SPRITE,
	RECTANGLE,
	TEXT,
	CIRCLE,
	CONVEX,
	VERTEX_ARRAY
};

struct DrawObject {
	DrawType type;
	sf::Sprite* sprite;
	sf::RectangleShape* rectangle;
	sf::Text *text;
	sf::CircleShape *circle;
	sf::ConvexShape* convex;
	sf::VertexArray* vertexArray;
	sf::Shader*  shader;
	sf::BlendMode blend;
};

class DrawLayer {
public:
	DrawLayer();
	DrawLayer(sf::View& _view);
	~DrawLayer();

	//the return int is the position of the DrawObject in the array, keep track of it
	int add(sf::Sprite* sprite);
	int add(sf::Sprite& sprite);
	int add(sf::Sprite* sprite, sf::Shader* shader);
	int add(sf::Sprite& sprite, sf::Shader* shader);
	int add(sf::Text* text);
	int add(sf::Text& text);
	int add(sf::Text* text, sf::Shader* shader);
	int add(sf::Text& text, sf::Shader* shader);
	int add(sf::CircleShape* circle);
	int add(sf::CircleShape& circle);
	int add(sf::CircleShape* circle, sf::Shader* shader);
	int add(sf::CircleShape& circle, sf::Shader* shader);
	int add(sf::RectangleShape* rectangle);
	int add(sf::RectangleShape& rectangle);
	int add(sf::RectangleShape* rectangle, sf::Shader* shader);
	int add(sf::RectangleShape& rectangle, sf::Shader* shader);
	int add(sf::ConvexShape* convex);
	int add(sf::ConvexShape& convex);
	int add(sf::ConvexShape* convex, sf::Shader* shader);
	int add(sf::ConvexShape& convex, sf::Shader* shader);
	int add(sf::VertexArray* vertexArray);
	int add(sf::VertexArray& vertexArray);
	int add(sf::VertexArray* vertexArray, sf::Shader* shader);
	int add(sf::VertexArray& vertexArray, sf::Shader* shader);
	
	int add(sf::Sprite& sprite, sf::BlendMode blendMode);

	sf::View* getView();
	void remove(int index);
	unsigned int getSize() { return size; };
	void cleanup();

	int getBufferSize() const { return BUFFER_SIZE; };
	DrawObject** getDrawObjects() const { return drawObjects; };
	DrawLayer& operator=(DrawLayer&);
	std::vector<DrawObject*> removeVect;

private:

	const int BUFFER_SIZE = 10000;
	DrawObject **drawObjects;
	unsigned int size;
	sf::View* view;
	bool createdNewView;
};

