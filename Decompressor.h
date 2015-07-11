#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <fstream>
#include <string>

#include "HTree.h"
#include "Frequency.h"

typedef unsigned char BYTE;

class Decompressor {
public:
	Decompressor(std::fstream& file);

	virtual BYTE* decompress() = 0;

	virtual int getTotalChars();
protected:
	virtual void deSerializeFrequency();

	int freqCount;

	int totalChars;

	KeyPair* freq;

	std::fstream& file;

};
#endif