#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

typedef std::unordered_map<char, int>   KeyMap;
typedef std::pair<std::string, int>  KeyPair;

class Frequency {
 
 public:
  Frequency(const char* buffer, int buffLength);

  ~Frequency();

  /*
   * Generates the characters used and their frequencies
   */
  KeyPair* frequencyGenerator();

  /*
   * gets the count of the distinct characters
   */
  int getKeyCount() const;

 private:
 /*
  * Counts each individual key
  */
  KeyMap countKeysFromBuffer();

  const char* buffer;

  int bufferLength;
  
  std::vector<char> keys;
  
  int   keyCount;
};
#endif

