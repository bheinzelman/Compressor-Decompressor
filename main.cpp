#include <iostream>
#include <fstream>

#include "Frequency.h"
#include "HuffmanCompressor.h"
#include "HTree.h"
#include "HuffmanDecompressor.h"


const char* getBufferFromFile(const char* filename, int& length, bool binary=false);

void writeBinary(unsigned char* buffer, int size, std::string filename);


int main(int argc, char* argv[]) {
  
  if (argc < 2) {
	std::cerr << "Insufficient args\n";

    exit(EXIT_FAILURE);
  }

  int fileSize;

  //get the buffer from the input file 
  const char* inBuffer = getBufferFromFile(argv[1], fileSize);

  //make the compressor
  HuffmanCompressor compressor = HuffmanCompressor((char*)inBuffer, fileSize);

  long compSize;
  //compress the data
  unsigned char* compressedData = compressor.compress(compSize);

  std::string path = std::string(argv[1]) + ".bzip";

  //write the compressed data to the disk
  writeBinary(compressedData, compSize, path);

  std::fstream in(path, std::ios::in|std::ios::binary);

  HuffmanDecompressor dec = HuffmanDecompressor(in);

  BYTE* data = dec.decompress();
  int dataSize = dec.getTotalChars();

  writeBinary(data, dataSize, "smallDec.txt");
 
  //release the memory
  delete[] compressedData;

  delete[] inBuffer;

  delete[] data;

  return 0;
}

const char* getBufferFromFile(const char* file, int& length, bool binary)
{
	std::fstream inFile(file, std::ios::in | std::ios::binary);


	//check to see if file is open
	if (!inFile.is_open())
	{
		std::cerr << "Could not not open file to compress\n";
		exit(EXIT_FAILURE);
	}

	//get the length of the file
	inFile.seekg(0, inFile.end);
	length = inFile.tellg();
	length++;
	inFile.seekg(0);

	char* buffer = new char[length+1];
	for (int i = 0; i < length; i++)
		buffer[i] = inFile.get();
	buffer[length] = '\0';
	

	return (const char*)buffer;
}

void writeBinary(unsigned char* buffer, int size, std::string filename)
{
	std::ofstream out(filename, std::ios::out | std::ios::binary);

	for (int i = 0; i < size; i++)
	{
		out << buffer[i];
	}
}