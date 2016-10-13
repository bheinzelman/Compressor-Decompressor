#include "Decompressor.h"
#include "HuffmanException.h"
#include <iostream>
#include <string>


Decompressor::Decompressor(std::fstream& file) : file(file) 
{
	freq = NULL;
	freqCount = 0;
	totalChars = 0;
}

Decompressor::~Decompressor() 
{
    if (freq != NULL) 
    {
        delete[] freq;
    }
}

void Decompressor::deSerializeFrequency() 
{
	std::string charCountStr = "";
	std::string totalCharStr = "";

	if (!file.is_open())
	{
		std::cout << "Could Not open binary file\n"; 
		return;
	}

	char c = file.get();

	while (c != '_')
	{
		if (!isdigit(c))
		{
			throw HuffmanException("Invalid bzip file");
		}


		totalCharStr += c;
		c = file.get();
	}

	this->totalChars = std::stoi(totalCharStr);

	c = file.get();

	while (c != '_')
	{
		if (!isdigit(c))
		  throw HuffmanException("Invalid bzip file");

		charCountStr += c;
		c = file.get();
	}

	int charCount = std::stoi(charCountStr);

	std::string freqCountStr = "";

	c = file.get();

	while (c != '_') 
	{
		if (!isdigit(c))
		    throw HuffmanException("Invalid bzip file");

		freqCountStr += c;
		c = file.get();
	}
	freqCount = stoi(freqCountStr);

	freq = new KeyPair[freqCount];

	char* buffer = new char[charCount];
	file.read(buffer, charCount);

	int index = 0;
	int i;
	for (i = 0; i < freqCount; i++) {
		freq[i].first = buffer[index];
		index++; 

		std::string characterFreq = "";
		if (isdigit(buffer[index])) {
			characterFreq += buffer[index];
			index++;
			while (buffer[index] != ',') {
				characterFreq += buffer[index];
				index++;
			}
			freq[i].second = std::stoi(characterFreq);
			index++;
		}
		else {
			throw HuffmanException("Invalid bzip file");
		}
	}

    delete[] buffer;
}


int Decompressor::getTotalChars()
{
	return totalChars - 1;
}
