#include "Compressor.h"
#include <iostream>

std::string Compressor::serializeFreq() 
{
	std::string serial = "";

	//append binary data
	for (int i = 0; i < freq_count; i++) 
	{
		serial += freq[i].first + std::to_string(freq[i].second) + ',';
	}
	
	//get the size of the meta data
	int size = serial.size();

	//add amount of freq characters and meta data size
	serial = std::to_string(totalChars) + '_' + std::to_string(size) + "_" + std::to_string(freq_count) + '_' + serial + '\n';

	return serial;
}