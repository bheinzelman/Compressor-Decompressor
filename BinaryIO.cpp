#include "BinaryIO.h"
#include <string>

unsigned char* BinaryIO::write_bin(std::string in, int& size) {
	//get even bytes
	int times = in.size() % 8;
	if (times != 0)
	{
		for (int i = 0; i < times; i++)
		{
			in += '0';
		}
	}
	int byteCount = in.size() / 8;
	unsigned char* out = new unsigned char[byteCount];

	unsigned char currentByte = 0;
	int bitNumber = BITS_PER_BYTE;
	int bytesWritten = 0;

	for (unsigned long i = 0; i < in.size(); i++)
	{
		if (in[i] == '1')
			currentByte += static_cast<unsigned char>(pow(2.0, bitNumber));
		bitNumber--;
		if (bitNumber < 0)
		{
			out[bytesWritten] = currentByte;
			bytesWritten += 1;
			bitNumber = BITS_PER_BYTE;
			currentByte = 0;
		}
	}
	size = byteCount;
	return out;
}

std::string BinaryIO::decToBin(BYTE dig)
{
	std::string result = std::to_string(dig % 2);
	int quotient = dig / 2;

	for (int i = 0; i < 7; i++)
	{
		result = std::to_string(quotient % 2) + result;
		quotient = quotient / 2;
	}

	
	return result;
}

std::string BinaryIO::read_bin(BYTE* stream, int streamLen) {
	std::string bits = "";

	for (int i = 0; i < streamLen; i++)
	{
		bits += decToBin(stream[i]);
	}
	return bits;
}
