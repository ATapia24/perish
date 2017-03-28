#include "Animator.h"

Animator::Animator(const int size) : 
	MAX_ANIMATIONS(size) {

	animations = new Animation[size];
	openSlots = new uint8_t[size];
	lastRan = new long int[size];

	for (int i = 0; i < size; i++) {

		// Fill up the list so we know that there are no
		// stored animations
		openSlots[i] = 1;
	
		// initalize the delay with -1, so we know later on
		// that the delay has not been initalized
		lastRan[i] = -1;

	}


}


Animator::~Animator() {

	delete[] animations;
	delete[] openSlots;
	delete[] lastRan;

}

void Animator::play() {

	// Loop through the array!
	for (int i = 0; i < MAX_ANIMATIONS; i++) {

		// find an open slot
		if (openSlots[i] == 0) {

			// check to see if any delay has been set in place
			if (lastRan[i] == -1) {

				// check to make sure that delay isn't just zero (which would be stupid but whatever)
				if (animations[i].delay >= 1) {
					// no animation has been set, so set the delay time right off the bat
					lastRan[i] = animations[i].delay;

					// start its clock
					animations[i].clock.restart();
				}

			} else {
					
				// delay has been set, so work with that.
				if (animations[i].clock.getElapsedTime().asMilliseconds() >= animations[i].delay) {

					// increment the last ran animation
					animations[i].lastRan++;

					// this will run if the amount of time has been achieved or past
					if (animations[i].lastRan >= animations[i].animations) {

						animations[i].sprite->setTexture(animations[i].textures[0]);

						// set it to one because we will run animation zero now
						animations[i].lastRan = 0;

					} else {

						// run the next animation
						animations[i].sprite->setTexture(animations[i].textures[animations[i].lastRan]);

					}

				}

			}

		}

	}

	// TODO

}

int Animator::addAnimation(Animation &animation) {

	// Loop through and find an empty spot
	for (int i = 0; i < MAX_ANIMATIONS; i++) {

		// If we find an open spot, use it
		if (openSlots[i] == 1) {

			animations[i] = animation;
			openSlots[i] = 0;

			return i;

		}

	}

}

void Animator::removeAnimation(const int i) {

	// "delete" it, so it will be overidden later
	openSlots[i] = 1;

}

Animation & Animator::buildAnimation(sf::Sprite *sprite, sf::Texture *textures, const int animationAmount, long int delay) {

	// build the struct!
	Animation animation;

	animation.sprite = sprite;
	animation.textures = textures;
	animation.animations = animationAmount;
	animation.delay = delay;
	animation.lastRan = 0;

	return animation;

}