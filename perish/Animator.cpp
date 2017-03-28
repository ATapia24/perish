#include "Animator.h"

#include <iostream>

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

			// check to see if the clock works
			if (animations[i].clock.getElapsedTime().asMilliseconds() >= animations[i].delay) {

				// increment the animation to the next one
				if (animations[i].lastRan + 1 >= animations[i].animations)
					animations[i].lastRan = 0;
				else
					animations[i].lastRan++;

				std::cout << animations[i].lastRan << '\n';

				animations[i].sprite->setTexture(*animations[i].texture);
				animations[i].sprite->setTextureRect(animations[i].rects[animations[i].lastRan]);

				animations[i].clock.restart();

			}

		}

	}

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