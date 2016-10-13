#include <iostream>
#include <fstream>
#include <string.h>

#include "Frequency.h"
#include "HuffmanCompressor.h"
#include "HTree.h"
#include "HuffmanDecompressor.h"


const char* getBufferFromFile(const char* filename, int& length, bool binary=false);

void writeBinary(unsigned char* buffer, int size, std::string filename);

void printInfo();

const char* getUnzipName(char* zipname);

int main(int argc, char* argv[]) {
  
  if (argc < 3) {
    printInfo();

    return 0;  
  }
	
  char* flag = argv[1];

  if (strcmp(flag, "-c") == 0) {
    int fileSize;
	
    //get the buffer from the input file 
    const char* inBuffer = getBufferFromFile(argv[2], fileSize);

    //make the compressor
    HuffmanCompressor compressor = HuffmanCompressor((char*)inBuffer, fileSize);

    long compSize;
    //compress the data
    unsigned char* compressedData = compressor.compress(compSize);

    std::string path = std::string(argv[2]) + ".bzip";

    //write the compressed data to the disk
    writeBinary(compressedData, compSize, path);

    delete [] compressedData;

    delete [] inBuffer;

    return 0;
  }

  else if (strcmp(flag, "-d") == 0) {
    std::fstream in(argv[2], std::ios::in|std::ios::binary);

    HuffmanDecompressor dec = HuffmanDecompressor(in);

    BYTE* data = dec.decompress();

    int dataSize = dec.getTotalChars();

    writeBinary(data, dataSize, "out.txt");

    delete [] data;

    return 0;
  }

  else {
    printInfo();
  }

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


void printInfo() {
	std::cout << "[param] file" << std::endl;

	std::cout << "params: \n";

	std::cout << "-d -> decompress\n";

	std::cout << "-c -> compress\n~";
}

const char* getUnzipName(char* zipname) {
	std::string ret = "";

	std::string tmp = std::string(zipname);

	for (auto i = 0; i < tmp.size() - 4; i++) {
		ret += tmp[i];
	}

	return ret.c_str();
}
