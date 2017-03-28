/* 
 * This class' job is to take change the texture of sprites at a given time..
 * The animation could repeat or just play once. This class uses pointers
 * so make sure you keep your textures and sprites within scope, or use the
 * new operator
 */

#pragma once

#include <SFML/Graphics.hpp>


struct Animation {
	
	// Holds the amount of animations
	int animations;
	// A clock for timing (don't set this!)
	sf::Clock clock;
	// the delay between animations (milliseconds)
	long int delay;
	// the sprite to animate
	sf::Sprite *sprite;
	// The last ran texture
	int lastRan;
	// the textures that are partaking in the animation!
	sf::Texture *textures;

};

class Animator {

private:

	// An array of animations
	Animation *animations;
	uint8_t *openSlots;

	// used to determine delays on animations etc
	long int *lastRan;

	// Should explain itself
	const int MAX_ANIMATIONS;

public:

	Animator(const int);
	~Animator();

	// Plays out the animations registered in the array
	void play();

	// Used to add an animation
	// returns its location in the array for deleting
	int addAnimation(Animation&);

	// Used to delete an animation.. Pass it the number the add
	// animation function returned
	void removeAnimation(const int);

	// Used to build an animation
	Animation & buildAnimation(sf::Sprite*, sf::Texture*, const int, long int);

};