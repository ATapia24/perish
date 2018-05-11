#include "DrawBuffer.h"



DrawBuffer::DrawBuffer()
{
	init();
}

DrawBuffer::DrawBuffer(sf::View& _view) {
	view = &_view;
	init();
}


DrawBuffer::~DrawBuffer()
{
	delete buffer;
}

void DrawBuffer::init()
{
	size = 0;
	buffer = new DrawObject[BUFFER_SIZE];

	for (int i = 0; i < BUFFER_SIZE; i++) {
		buffer[i].type = DrawType::EMPTY;
	}
}

int DrawBuffer::add(sf::Sprite &obj) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (buffer[i].type == DrawType::EMPTY) {
			buffer[i].type = DrawType::SPRITE;
			buffer[i].sprite = &obj;
			size++;
			return i;
		}
	}
}




int DrawBuffer::add(sf::Text &obj) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (buffer[i].type == DrawType::EMPTY) {
			buffer[i].type = DrawType::TEXT;
			buffer[i].text = &obj;
			size++;
			return i;
		}
	}
}

int DrawBuffer::add(sf::RectangleShape &obj) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (buffer[i].type == DrawType::EMPTY) {
			buffer[i].type = DrawType::RECTANGLE;
			buffer[i].rectangle = &obj;
			size++;
			return i;
		}
	}
}

int DrawBuffer::add(sf::CircleShape &obj) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (buffer[i].type == DrawType::EMPTY) {
			buffer[i].type = DrawType::CIRCLE;
			buffer[i].circle = &obj;
			size++;
			return i;
		}
	}
}

int DrawBuffer::add(sf::ConvexShape &obj) {
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (buffer[i].type == DrawType::EMPTY) {
			buffer[i].type = DrawType::CONVEX;
			buffer[i].convex = &obj;
			size++;
			return i;
		}
	}
}

void DrawBuffer::remove(int i) {
	buffer[i].type = DrawType::EMPTY;
}