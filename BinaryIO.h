#ifndef BINARY_IO_H
#define BINARY_IO_H

#define BITS_PER_BYTE 7 // 0 - 7 Eight total

#include <string>
#include <ostream>
#include <math.h>

typedef unsigned char BYTE;

class BinaryIO {
public:
	/*
	 * Given an input string, binary data will be output
	 */
	static unsigned char* write_bin(std::string in, int& size);

	/*
	 * takes an input str and a string of 1's and 0's will be returned
	 */
	static std::string read_bin(BYTE* stream, int streamLen);
private:
	/*
	 * Converts BYTE to a str of 1's and 0's
	 */
	static std::string decToBin(BYTE dig);

};
#endif