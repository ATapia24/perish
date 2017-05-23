#include "DrawLayer.h"

//CONSTRUCTOR
DrawLayer::DrawLayer() {

	drawObjects = new DrawObject*[BUFFER_SIZE];
	
	for (int i = 0; i < BUFFER_SIZE; i++) {
		drawObjects[i] = new DrawObject;
		drawObjects[i]->type = DrawType::EMPTY;
	}

	size = 0;

	view = new sf::View;
	createdNewView = true;
}

//CONSTRUCTOR w/ view
DrawLayer::DrawLayer(sf::View& _view) {
	view = &_view;
	createdNewView = false;
	drawObjects = new DrawObject*[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++) {
		drawObjects[i] = new DrawObject;
		drawObjects[i]->type = DrawType::EMPTY;
	}

	size = 0;
}

//DECONSTRUCTOR
DrawLayer::~DrawLayer() {
	delete[] drawObjects;
	
	if(createdNewView)
		delete view;
}

//ADD SPRITE BY POINTER
int DrawLayer::add(sf::Sprite *sprite) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = sprite;
			drawObjects[i]->shader = NULL;
			drawObjects[i]->blend = sf::BlendAlpha;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD SPRITE BY REFERENCE
int DrawLayer::add(sf::Sprite &sprite) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = &sprite;
			drawObjects[i]->shader = NULL;
			drawObjects[i]->blend = sf::BlendAlpha;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD SPRITE BY POINTER w/ shader
int DrawLayer::add(sf::Sprite* sprite, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = sprite;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD SPRITE BY REFERENCE w/ shader
int DrawLayer::add(sf::Sprite& sprite, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = &sprite;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD RECTANGLE BY POINTER
int DrawLayer::add(sf::RectangleShape *rectangle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::RECTANGLE;
			drawObjects[i]->rectangle = rectangle;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD RECTANGLE BY REFERENCE
int DrawLayer::add(sf::RectangleShape &rectangle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::RECTANGLE;
			drawObjects[i]->rectangle = &rectangle;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD RECTANGLE BY POINTER w/ shader
int DrawLayer::add(sf::RectangleShape* rectangle, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::RECTANGLE;
			drawObjects[i]->rectangle = rectangle;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD RECTANGLE BY REFERENCE w/ shader
int DrawLayer::add(sf::RectangleShape& rectangle, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::RECTANGLE;
			drawObjects[i]->rectangle = &rectangle;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD TEXT BY POINTER
int DrawLayer::add(sf::Text *text) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::TEXT;
			drawObjects[i]->text = text;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD TEXT BY REFERENCE
int DrawLayer::add(sf::Text& text) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::TEXT;
			drawObjects[i]->text = &text;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD TEXT BY POINTER w/ shader
int DrawLayer::add(sf::Text* text, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::TEXT;
			drawObjects[i]->text = text;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD TEXT BY REFERENCE w/ shader
int DrawLayer::add(sf::Text& text, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::TEXT;
			drawObjects[i]->text = &text;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CIRCLE BY POINTER
int DrawLayer::add(sf::CircleShape *circle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CIRCLE;
			drawObjects[i]->circle = circle;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CIRCLE BY REFERENCE
int DrawLayer::add(sf::CircleShape &circle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CIRCLE;
			drawObjects[i]->circle = &circle;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CIRCLE BY POINTER w/ shader
int DrawLayer::add(sf::CircleShape* circle, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CIRCLE;
			drawObjects[i]->circle = circle;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CIRCLE BY REFERENCE w/ shader
int DrawLayer::add(sf::CircleShape& circle, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CIRCLE;
			drawObjects[i]->circle = &circle;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CONVEX BY POINTER
int DrawLayer::add(sf::ConvexShape *convex)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CONVEX;
			drawObjects[i]->convex = convex;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CONVEX BY REFERENCE
int DrawLayer::add(sf::ConvexShape& convex)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CONVEX;
			drawObjects[i]->convex = &convex;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CONVEX BY POINTER w/ shader
int DrawLayer::add(sf::ConvexShape* convex, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CONVEX;
			drawObjects[i]->convex = convex;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CONVEX BY REFERENCE w/ shader
int DrawLayer::add(sf::ConvexShape& convex, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CONVEX;
			drawObjects[i]->convex = &convex;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD VERTEX ARRAY BY POINTER
int DrawLayer::add(sf::VertexArray* vertexArray) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::VERTEX_ARRAY;
			drawObjects[i]->vertexArray = vertexArray;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD VERTEX ARRAY BY REFERENCE
int DrawLayer::add(sf::VertexArray& vertexArray) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::VERTEX_ARRAY;
			drawObjects[i]->vertexArray = &vertexArray;
			drawObjects[i]->shader = NULL;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD VERTEX ARRAY BY POINTER w/ shader
int DrawLayer::add(sf::VertexArray* vertexArray, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::VERTEX_ARRAY;
			drawObjects[i]->vertexArray = vertexArray;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD VERTEX ARRAY BY REFERENCE w/ shader
int DrawLayer::add(sf::VertexArray& vertexArray, sf::Shader* shader) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::VERTEX_ARRAY;
			drawObjects[i]->vertexArray = &vertexArray;
			drawObjects[i]->shader = shader;
			size++;
			return i;
		}
	}

	return -1;
}

//REMOVE
void DrawLayer::remove(int index)
{
	drawObjects[index]->type = DrawType::EMPTY;
	size--;
}

//CLEANUP 
//Desc. removes gaps in drawObjects array for faster drawing
//TODO: CAN BE FASTER
void DrawLayer::cleanup()
{
	//tmp
	/*
	std::cout << "b: ";
	for (int i = 0; i < 25; i++)
		std::cout << drawObjects[i]->type;
	std::cout << '\n';*/

	int emptyIndex=1, n_empty = 0, efound = 0;
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (drawObjects[i]->type == DrawType::EMPTY) {
			emptyIndex = i;
			

			for (int j = i + 1; j < BUFFER_SIZE; j++)
			{
				if (drawObjects[j]->type != DrawType::EMPTY)
				{
					drawObjects[emptyIndex]->type = drawObjects[j]->type;
					drawObjects[emptyIndex]->rectangle = drawObjects[j]->rectangle;
					drawObjects[emptyIndex]->circle = drawObjects[j]->circle;
					drawObjects[emptyIndex]->convex = drawObjects[j]->convex;
					drawObjects[emptyIndex]->sprite = drawObjects[j]->sprite;
					drawObjects[emptyIndex]->text = drawObjects[j]->text;
					drawObjects[emptyIndex]->vertexArray = drawObjects[j]->vertexArray;
					drawObjects[j]->type = DrawType::EMPTY;
					j = BUFFER_SIZE;
				}
			}

		}
	}

	/*
	std::cout << "a : ";
	for (int i = 0; i < 25; i++)
		std::cout << drawObjects[i]->type;
	std::cout << '\n';*/
}

// OPERATOR =
DrawLayer& DrawLayer::operator=(DrawLayer &layer) {

	for (int i = 0; i < BUFFER_SIZE; i++) {
		drawObjects[i] = layer.drawObjects[i];
	}

	return *this;
}

//GET VIEW
sf::View* DrawLayer::getView() {
	return view;
}

//ADD SPRITE BY REFERENCE
int DrawLayer::add(sf::Sprite &sprite, sf::BlendMode blendMode) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = &sprite;
			drawObjects[i]->shader = NULL;
			drawObjects[i]->blend = blendMode;
			size++;
			return i;
		}
	}
	return -1;
}