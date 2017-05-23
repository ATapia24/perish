#include "SerialPort.h"



SerialPort::SerialPort() {
	serialPortHandle = INVALID_HANDLE_VALUE;
}

SerialPort::~SerialPort() {
	if (serialPortHandle != INVALID_HANDLE_VALUE)
		CloseHandle(serialPortHandle);

	serialPortHandle = INVALID_HANDLE_VALUE;
}

int SerialPort::connect() {
	return connect(L"COM4");
}

int SerialPort::connect(wchar_t* device) {
	int error = 0;
	DCB dcb;

	memset(&dcb, 0, sizeof(dcb));

	dcb.DCBlength = sizeof(dcb);

	dcb.BaudRate = 9600;
	dcb.Parity = NOPARITY;
	dcb.fParity = 0;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;

	serialPortHandle = CreateFile(device, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, NULL, NULL);

	if (serialPortHandle != INVALID_HANDLE_VALUE) {
		if (!SetCommState(serialPortHandle, &dcb))
			error = 2;
	}
	else {
		error = 1;
	}

	if (error != 0) {
		disconnect();
	}
	else {
		clear();
	}

	if (error != 0)
		std::cout << "connect error " << error << '\n';

	return error;
}

void SerialPort::disconnect(void) {
	CloseHandle(serialPortHandle);
	serialPortHandle = INVALID_HANDLE_VALUE;

	//printf("Port 1 has been CLOSED and %d is the file descriptionn", fileDescriptor);
}

bool SerialPort::write(unsigned char byte) {
	unsigned long result;
	
	//check for error
	if (serialPortHandle == INVALID_HANDLE_VALUE) {
		std::cout << "write error\n";
		disconnect();
		return false;
	}

	//write to port
	WriteFile(serialPortHandle, &byte, 1, &result, NULL);
	return true;
}

unsigned char SerialPort::read() {
	unsigned long read_nbr;
	char byte[1];
	read_nbr = 0;

	//read error
	if (serialPortHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "Read error\n";
		return NULL;
	}

	//read
	ReadFile(serialPortHandle, byte, 1, &read_nbr, NULL);
	return byte[0];
}

void SerialPort::clear() {
	PurgeComm(serialPortHandle, PURGE_RXCLEAR | PURGE_TXCLEAR);
}