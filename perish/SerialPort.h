#pragma once

#include <Windows.h>
#include <iostream>

class SerialPort {
private:
	HANDLE serialPortHandle;

public:
	SerialPort();
	~SerialPort();

	int connect();
	int connect(wchar_t *device);
	void disconnect(void);
	bool write(unsigned char byte);
	unsigned char read();

	void clear();
};