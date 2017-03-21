#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>

class Timer {
private:
	std::chrono::high_resolution_clock::time_point t1, t2;
	unsigned long lastSec, lastMilli, lastNano;
public:
	Timer();
	~Timer();
	void start();
	void stop();
	void reset();
	unsigned long getSeconds();
	unsigned long getMilliseconds();
	unsigned long getNanoseconds();
};

#endif