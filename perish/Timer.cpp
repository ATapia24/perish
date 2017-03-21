#include "Timer.h"


Timer::Timer() {
	lastSec = 0;
	lastMilli = 0;
	lastNano = 0;
}


Timer::~Timer() {

}


//START
void Timer::start() {
	t1 = std::chrono::high_resolution_clock::now();
}

//STOP
void Timer::stop() {
	t2 = std::chrono::high_resolution_clock::now();
}

//RESET
void Timer::reset() {
	t1 = std::chrono::high_resolution_clock::now();
}

//GET SECONDS
unsigned long Timer::getSeconds() {
	lastSec = (unsigned long)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - t1).count();
	return lastSec;
}

//GET MILLISECONDS
unsigned long Timer::getMilliseconds() {
	lastMilli = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count();
	return lastMilli;
}

//GET NANOSECONDS
unsigned long Timer::getNanoseconds() {
	lastNano = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - t1).count();
	return lastNano;
}