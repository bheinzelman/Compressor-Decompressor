#include "HuffmanDecompressor.h"
#include "HuffmanException.h"
#include "BinaryIO.h"
#include <iostream>

BYTE* HuffmanDecompressor::decompress() {
	try {
		//get data to build huffman tree
		deSerializeFrequency();

		tree.setFreqAndSize(freq, freqCount);
		
		//get newline
		file.get();

		//build the tree
		tree.buildTree();

		unsigned long pos = static_cast<unsigned long>(file.tellg());

		file.seekg(0, file.end);

		//get the length of the remaining data
		int length = file.tellg();
		length -= pos;

		file.seekg(pos);
		
		//alloc buffer to put binary from file into
		unsigned char* buffer = new unsigned char[length];
		
		char c = file.get();
		
		for (int i = 0; i < length; i++)
		{
			buffer[i] = c;
			c = file.get();
		}

		//turn data into string of 1's and 0's
		std::string bits = BinaryIO::read_bin(buffer, length);

		BYTE *out = new BYTE[totalChars];
		int bufferIndex = 0;

		//feed bits to tree and get outputted characters
		for (auto i = 0; i < bits.size(); i++)
		{
			char* j = NULL;
			bool b = false;
			if (bits[i] == '1')
				b = tree.feedCode(1, j);
			else
				b = tree.feedCode(0, j);
			if (b)
			{
				char c = *j;
				out[bufferIndex] = c;
				bufferIndex++;
			}
		}

        delete[] buffer;
		return out;
	}
	catch (HuffmanException e) 
	{
        std::cerr << e.what() << std::endl;
		return NULL;
	}	
	
}

HuffmanDecompressor::~HuffmanDecompressor()
{
}
