#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include <string>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include "Box2D.h"

namespace misc {
	const std::string GAME_NAME = "Perish";
	const int NATIVE_WIDTH = 1600;
	const int NATIVE_HEIGHT = 900;
	const float PI = 3.14159265359f;
	const float PI2 = 6.28318530718f;
	const float PIh = 1.57079632679f;
	const float PId4 = 0.78539816339f;
	const float PI3d4 = 2.35619449019f;
	const float PI5d4 = 3.92699081699f;
	const float PI7d4 = 5.49778714378f;
	const float RAD2DEG = 57.2957795131f;
	const float DEG2RAD = 0.0174532925f;
	const float PHYSICS_SCALE = 64.0f;

	std::string floatToString(float num);
	std::string intToString(int num);
	std::string doubleToString(double num);
	std::string extractBetween(std::string string, char token);
	std::string extractBetween(std::string& string, char token, char replace);
	bool isLetter(const char c);
	float distance(const sf::Vector2f a, const sf::Vector2f b);
	float distance(const b2Vec2 a, const b2Vec2 b);
	float lineAngle(const sf::Vector2f centerpoint, const sf::Vector2f endpoint);
	float lineAngle(const b2Vec2 centerpoint, const b2Vec2 endpoint);
	sf::Vector2f midpoint(const sf::Vector2f a, const sf::Vector2f b);
	sf::Vector2f pointLocation(const sf::Vector2f point, const float angle, const float distance);
	b2Vec2 pointLocation(const b2Vec2 point, const float angle, const float distance);
	bool intersects(const sf::Vector2f a, const sf::Vector2f b, const sf::Vector2f c, const sf::Vector2f d);
	bool intersects(const b2Vec2 a, const b2Vec2 b, b2Vec2 c, b2Vec2 d);
	int random(int min, int max);
	sf::Color randomColor();
	std::vector<sf::Vector2f> getAreaPoints(const sf::RectangleShape shape, const float resolustion, const bool sides);
	
	//TEMPLATES ------------------------------------------------------------------------------------------------------------------------------

	//SWAP
	template<typename T>
	inline void swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	};

	//PTR SWAP
	template<typename T>
	inline void swap(T*&a, T*&b) {
		T* tmp = a;
		a = b;
		b = tmp;
	};
}

#endif /* MISCELLANEOUS_H */