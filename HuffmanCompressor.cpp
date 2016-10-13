#include "HuffmanCompressor.h"
#include <iostream>
#include <cstring>

HuffmanCompressor::HuffmanCompressor(char* fileBuffer, int buffLen) : Compressor(fileBuffer, buffLen) 
{
}

unsigned char* HuffmanCompressor::compress(long& size)  
{
	HTree tree = HTree(freq, freq_count);

	std::string output = "";
	
	long buffLength = strlen(fileBuffer);

	try {
		
		std::string code = "";
		for (long i = 0; i < /*buffLength*/totalChars; i++)
		{
			std::string ch = std::string(1, fileBuffer[i]);

			//get rid of crap chars
			if (ch[0] > 0)
				code += tree.getCode(ch);
		}

		int dataLen;

		unsigned char* data = BinaryIO::write_bin(code, dataLen);

		std::string meta = serializeFreq();

		int binLen = dataLen + meta.size();

		unsigned char* binary = new unsigned char[binLen];

		//write the meta data from 'serializeFreq'
		for (unsigned int i = 0; i < meta.size(); i++)
		{
			if (meta[i] != '\0')
				binary[i] = (unsigned char)meta[i];
		}

		//write the actual encoding
		for (unsigned int j = meta.size(); j < meta.size() + dataLen; j++)
		{
			binary[j] = data[j - meta.size()];
		}

		//set the output size
		size = meta.size() + dataLen;
		return binary;
			
	}
	//catch exception if a huffman error occurs
	catch (HuffmanException e) 
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
	
}
