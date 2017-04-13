#include "DrawLayer.h"

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

DrawLayer::~DrawLayer() {
	delete[] drawObjects;
	
	if(createdNewView)
		delete view;
}

//ADD SPRITE
int DrawLayer::add(sf::Sprite *sprite) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = sprite;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD SPRITE
int DrawLayer::add(sf::Sprite &sprite) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::SPRITE;
			drawObjects[i]->sprite = &sprite;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD RECTANGLE
int DrawLayer::add(sf::RectangleShape *rectangle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::RECTANGLE;
			drawObjects[i]->rectangle = rectangle;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD RECTANGLE
int DrawLayer::add(sf::RectangleShape &rectangle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::RECTANGLE;
			drawObjects[i]->rectangle = &rectangle;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD TEXT
int DrawLayer::add(sf::Text *text) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::TEXT;
			drawObjects[i]->text = text;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD TEXT
int DrawLayer::add(sf::Text& text) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::TEXT;
			drawObjects[i]->text = &text;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CIRCLE
int DrawLayer::add(sf::CircleShape *circle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CIRCLE;
			drawObjects[i]->circle = circle;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CIRCLE
int DrawLayer::add(sf::CircleShape &circle) {
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CIRCLE;
			drawObjects[i]->circle = &circle;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CONVEX
int DrawLayer::add(sf::ConvexShape *convex)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CONVEX;
			drawObjects[i]->convex = convex;
			size++;
			return i;
		}
	}
	return -1;
}

//ADD CONVEX
int DrawLayer::add(sf::ConvexShape& convex)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (drawObjects[i]->type == DrawType::EMPTY) {
			drawObjects[i]->type = DrawType::CONVEX;
			drawObjects[i]->convex = &convex;
			size++;
			return i;
		}
	}
	return -1;
}

//REMOVE
void DrawLayer::remove(int index)
{
	if (index < BUFFER_SIZE)
	{
		drawObjects[index]->type = DrawType::EMPTY;
		size--;
	}
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