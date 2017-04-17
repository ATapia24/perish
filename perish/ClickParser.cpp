#include "ClickParser.h"

ClickParser::ClickParser(int maxClicks) :
	MAX_CLICK_EVENTS(maxClicks) {

	coords = new CoordRange*[MAX_CLICK_EVENTS];
	clicked = new bool[MAX_CLICK_EVENTS];

	for (int i = 0; i < MAX_CLICK_EVENTS; i++) {
		coords[i] = NULL;
		clicked[i] = false;
	}

}

ClickParser::~ClickParser() {

	// delete all items stored withing the coords array
	for (int i = 0; i < MAX_CLICK_EVENTS; i++) {
		delete coords[i];
	}

	// now delete the memory allocated for the arrays
	delete[] coords;
	delete[] clicked;

}

int ClickParser::addClick(float x1, float y1, float x2, float y2) const {

	CoordRange *temp = new CoordRange;

	temp->x1 = x1;
	temp->y1 = y1;
	temp->x2 = x2;
	temp->y2 = y2;

	for (int i = 0; i < MAX_CLICK_EVENTS; i++) {

		if (coords[i] == NULL) {
			coords[i] = temp;
			clicked[i] = false;
			return i;
		}

	}

}

void ClickParser::removeClick(int loc) {

	coords[loc] = NULL;
	clicked[loc] = false;

}

void ClickParser::editClick(int loc, float x1, float y1, float x2, float y2) {

	coords[loc]->x1 = x1;
	coords[loc]->y1 = y1;
	coords[loc]->x2 = x2;
	coords[loc]->y2 = y2;

}

bool ClickParser::wasClicked(int loc) const {

	if (loc >= 0 && loc < MAX_CLICK_EVENTS) {
		return clicked[loc];
	} else
		return false;

}

void ClickParser::parseClick(float x, float y) {

	for (int i = 0; i < MAX_CLICK_EVENTS; i++) {

		if (coords[i] != NULL) {

			if (x >= coords[i]->x1 && x <= coords[i]->x2 && y >= coords[i]->y1 && y <= coords[i]->y2) {
				clicked[i] = true;
			} else {
				// reset any ones that weren't clicked
				clicked[i] = false;
			}

		}

	}

}

ClickParser::ClickParser(const ClickParser &clck) :
			MAX_CLICK_EVENTS(clck.MAX_CLICK_EVENTS){

	for (int i = 0; i < MAX_CLICK_EVENTS; i++) {

		coords[i] = clck.coords[i];
		clicked[i] = clck.clicked[i];

	}

}

ClickParser ClickParser::operator=(const ClickParser &clck) {

	ClickParser temp(clck.MAX_CLICK_EVENTS);

	for (int i = 0; i < temp.MAX_CLICK_EVENTS; i++) {

		temp.coords[i] = clck.coords[i];
		temp.clicked[i] = clck.clicked[i];

	}

	return temp;

}