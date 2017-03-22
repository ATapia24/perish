#pragma once
class Location {

private:

	float x;
	float y;

public:

	Location();
	Location(float, float);
	~Location();

	float getX() const;
	float getY() const;

	void setLocation(float, float);

	Location& operator=(const Location&);

};

