#ifndef HUFFMAN_COMPRESSOR_H
#define HUFFMAN_COMPRESSOR_H

#include "Compressor.h"
#include "HTree.h"

class HuffmanCompressor : public Compressor {
public:
	HuffmanCompressor(char* fileBuffer, int buffLen); 

	virtual unsigned char* compress(long& size);
};
#endif