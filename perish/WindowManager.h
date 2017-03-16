#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <string>
#include <SFML/Graphics.hpp>
#include "WindowEventHandler.h"
#include "Miscellaneous.h"



struct queueType {
	short int type;
	sf::Sprite sprite;
	sf::Text text;
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::ConvexShape convex;
	sf::VertexArray vertexArray;
	sf::BlendMode blendMode;
};

class WindowManager {

private:
	sf::RenderWindow *window;
	std::string name;
	float widthScale, heightScale;
	bool fullscreen;
	unsigned int fps;


	//sfml views and queues
	sf::View guiView;
	sf::View worldView;
	unsigned int guiSize, worldSize;
	queueType *guiQueue, *worldQueue;
	const long int MAX_DRAW_SIZE = 10000;

public:
	WindowManager();
	WindowManager(unsigned int height, unsigned int width, const std::string name);
	~WindowManager();

	void addGui(sf::Sprite sprite);
	void addGui(sf::Text text);
	void addGui(sf::RectangleShape rectangle);
	void addGui(sf::CircleShape circle);
	void addGui(sf::ConvexShape convex);
	void addWorld(sf::Sprite sprite);
	void addWorld(sf::Text text);
	void addWorld(sf::RectangleShape rectangle);
	void addWorld(sf::CircleShape circle);
	void addWorld(sf::ConvexShape convex);
	void addWorld(sf::VertexArray vertexArray);
	void addWorld(sf::Sprite sprite, const sf::BlendMode blendMode);
	void setResolution(int width, int height, bool _fullscreen, bool border);
	void setFramerate(unsigned int fps);
	void setRepeatingKeysEnabled(bool enabled);
	void draw();

	inline sf::RenderWindow* getWindow() { return window; };
	inline sf::View* getWorldView() { return &worldView; };
	inline sf::View* getGuiView() { return &guiView; };
	inline sf::Vector2f getScale() { return sf::Vector2f(widthScale, heightScale); };
};

#endif /* WINDOWMANAGER_H */