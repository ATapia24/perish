/*

I know, I know.. The name is cheesy, but it's still cool! B)

Anyways.. This class' job is to allow the programmer to add any
set of coordinates, and if any items within those coordinates has
been clicked, this class will let you know! (with a boolean of course!)

*/
#pragma once

#include <cstdlib>
#include <iostream>

class ClickParser {

private:

	// used to holds the max amount of click events
	const int MAX_CLICK_EVENTS;

	/*
	Holds the range of points that the class should look for
	*/
	struct CoordRange {
		float x1, y1, x2, y2;
	};

	// an array of pointers to hold the different coords
	CoordRange **coords;

	// an array to holds the bool values (to we can check to see if it was)
	// clicked
	bool *clicked;

public:

	// construction etc
	ClickParser(int);
	~ClickParser();

	// used to add a click to listen for
	// returns the internal location that you need
	// to see if the section has been clicked or not
	int addClick(float, float, float, float) const;

	// used to remove a click listener
	void removeClick(int);

	// used for editing a click that already exists..
	// so use this to edit bounds
	void editClick(int, float, float, float, float);

	// used to check if a specific section was clicked
	// will return true if the specific one was clicked
	bool wasClicked(int) const;

	// Determines if any of the stored CoordRanges were withing
	// the specified points. (This is the tick function of this
	// class, so pass any relevant clicks to this function)
	void parseClick(float, float);

	// equals operator and copy constructor
	ClickParser(const ClickParser&);
	ClickParser operator=(const ClickParser&);

};

