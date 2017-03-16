#include "WindowEventHandler.h"

WindowEventHandler::WindowEventHandler(sf::Window *_window) {

	// Copying the address from one pointer to another!
	window = _window;

}

WindowEventHandler::~WindowEventHandler() {

	/*
	* We don't want to delete the window object here.. that would
	* be gruesome!
	*/

}

// Fires different events depending on what type it is
void WindowEventHandler::handleEvent(sf::Event event) {

	/*
	* Selects the type by number and sends it off to where
	* it is needed
	*/
	switch (event.type) {

	case sf::Event::Closed:

		// Close the window here
		windowCloseEvent();

		break;
	case sf::Event::LostFocus:

		// lost focus
		lostFocus();

		break;
	case sf::Event::GainedFocus:

		// gained focus
		gainedFocus();

		break;
	case sf::Event::TextEntered:

		// Check to make sure text was entered
		if (event.text.unicode < 128) {
			// Pass the character typed to the function
			textEntered(static_cast<char>(event.text.unicode));
		}

		break;

	case sf::Event::KeyPressed:

		// Key pressed! :D
		keyPressed(event.key.code);
		break;

	case sf::Event::KeyReleased:

		// Key pressed! :D
		keyReleased(event.key.code);

		break;

	case sf::Event::MouseWheelScrolled:

		// pass the mouse data, yo!
		mouseWheelScrolled(event.mouseWheelScroll);

		break;

	case sf::Event::MouseButtonPressed:

		// Some mouse button pressed!
		mouseButtonPressed(event.mouseButton);

		break;

	case sf::Event::MouseButtonReleased:

		// some mouse button released!
		mouseButtonReleased(event.mouseButton);

		break;

	case sf::Event::MouseMoved:

		// Fires when the mouse is moved over the window.. even if it
		// isn't focused
		mouseMoved(event.mouseMove);

		break;

	case sf::Event::MouseEntered:

		// Fires when the mouse enters the screen
		mouseArrived();

		break;

	case sf::Event::MouseLeft:

		// Fires when the mouse leaves the screen
		mouseDeparted();

		break;
	}

}

// Runs when the window is closed.. these are all private
// functions
void WindowEventHandler::windowCloseEvent() {

	std::cout << "Window close event detected.. Closing the window\n";
	// Close the window.. Simple as that
	window->close();

}

// Runs when the window loses focus
void WindowEventHandler::lostFocus() {

	// Banana!

}

// Runs when the window gains focus
void WindowEventHandler::gainedFocus() {

	// I shouldn't have to tell you what this does!

}

// Runs when text is entered
void WindowEventHandler::textEntered(const char c) {

}

// Runs when a key is pressed
void WindowEventHandler::keyPressed(const sf::Keyboard::Key &key) {

	if (key == sf::Keyboard::Escape) {

		window->close();

	}

}

// Runs when a key is released
void WindowEventHandler::keyReleased(const sf::Keyboard::Key &key) {

	// TODO!

}

// Runs if the mouse wheel is scrolled
void WindowEventHandler::mouseWheelScrolled(const sf::Event::MouseWheelScrollEvent &mouse) {

	// TODO!

}

// Runs when the mouse wheel is pressed
void WindowEventHandler::mouseButtonPressed(const sf::Event::MouseButtonEvent &mouse) {

	// TODO!
	if (mouse.button == sf::Mouse::Right) {

		window->close();

	}

}

// Runs when the mouse wheel is released
void WindowEventHandler::mouseButtonReleased(const sf::Event::MouseButtonEvent& mouse) {

	// TODO!

}

void WindowEventHandler::mouseMoved(const sf::Event::MouseMoveEvent &mouse) {

	// TODO

}

// Runs when the mouse enters the screen
void WindowEventHandler::mouseArrived() {

	// TODO

}

// Runs when the mouse leaves the screen
void WindowEventHandler::mouseDeparted() {

	// TODO

}
