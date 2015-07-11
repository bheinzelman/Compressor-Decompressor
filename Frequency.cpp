#include "Frequency.h"
#include <iostream>


Frequency::Frequency(const char* buffer, int bufferLength) : buffer(buffer), bufferLength(bufferLength) {
	this->keyCount = 0;
}


Frequency::~Frequency() {}

int Frequency::getKeyCount() const {
  return keyCount;
}

KeyPair* Frequency::frequencyGenerator() {
  KeyMap mp = countKeysFromBuffer();

  KeyPair* pairs = new KeyPair[keyCount];

  for (int i = 0; i < keyCount; i++) {
    pairs[i].first = keys[i];
    pairs[i].second = mp[keys[i]];
  }

  return pairs;
}

KeyMap Frequency::countKeysFromBuffer() {
  KeyMap keysMap = KeyMap();
  
  for (int i = 0; i < bufferLength; i++) {
    if (keysMap.find(buffer[i]) == keysMap.end() && buffer[i] > 0) {
      keysMap[buffer[i]] = 1;
	  keys.push_back(buffer[i]);
      keyCount++;
    }
    else {
      keysMap[buffer[i]]++;
    }
  }
  
  return keysMap;
}


