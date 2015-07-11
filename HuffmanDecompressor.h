#ifndef HUFFMAN_DECOMPRESSOR_H
#define HUFFMAN_DECOMPRESSOR_H

#include "Decompressor.h"

class HuffmanDecompressor :public Decompressor {
public:
	HuffmanDecompressor(std::fstream& file) : Decompressor(file) {};

	~HuffmanDecompressor();

	virtual BYTE* decompress();

private:
	HTree tree;

};
#endif