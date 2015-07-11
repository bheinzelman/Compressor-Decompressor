#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <fstream>
#include <map>

#include "Frequency.h"
#include "BinaryIO.h"

#define BITS_PER_BYTE 7

typedef unsigned char BYTE;


class Compressor {
 public:
  Compressor(char* fileBuffer, int buffLen) : fileBuffer(fileBuffer) 
  {
	  Frequency f = Frequency(fileBuffer, buffLen);
	  this->freq = f.frequencyGenerator();
	  this->freq_count = f.getKeyCount();
	  this->totalChars = buffLen;
  };

  /*
   * Compresses the input buffer and returns a BYTE*
   */
  virtual unsigned char* compress(long& size)=0;
  
 protected:
  /*
   * Serializes meta data that goes along with the compressed file
   */
  virtual std::string serializeFreq();

  //buffer to be compressed
  char* fileBuffer;
  
  KeyPair* freq;

  int freq_count;

  int totalChars;
};
#endif

