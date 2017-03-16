#ifndef WINDOWEVENTHANDLER_H
#define WINDOWEVENTHANDLER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class WindowEventHandler {

private:

	// A nice window pointer that we will need! :D
	sf::Window *window;

	// Fired when the window is being closed
	void windowCloseEvent();
	// Fired when window loses focus
	void lostFocus();
	// Fired when window gains focus
	void gainedFocus();
	// Fired when a text character is entered
	void textEntered(const char c);
	// Fired when any key is pressed
	void keyPressed(const sf::Keyboard::Key &key);
	// Fired when any key is released
	void keyReleased(const sf::Keyboard::Key &key);
	// Fired when the mouse wheel is scrolled
	void mouseWheelScrolled(const sf::Event::MouseWheelScrollEvent &mouse);
	// Fired when a mouse button is pressed
	void mouseButtonPressed(const sf::Event::MouseButtonEvent &mouse);
	// Fired when a mouse button is released
	void mouseButtonReleased(const sf::Event::MouseButtonEvent &mouse);
	// Fired when the mouse is moved.. event when unfocused
	void mouseMoved(const sf::Event::MouseMoveEvent &mouse);
	// Fires when the mouse enters the screen // Don't you like my awesome
	void mouseArrived();                      // function names? So
											  // Fires when the mouse leaves the screen // official...
	void mouseDeparted();

public:
	// both constructor and de constructor
	WindowEventHandler(sf::Window *window);
	virtual ~WindowEventHandler();

	// Fires different events depending on what type it is
	void handleEvent(sf::Event event);

};

#endif /* WINDOWEVENTHANDLER_H */