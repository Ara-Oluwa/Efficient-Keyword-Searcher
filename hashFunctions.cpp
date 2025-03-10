/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include "hashFunctions.h"
#include <string>

using std::string;

int hash(int data, int range) {
    // data is already an int, but could be out of range
    // use mod to put back into range
    int toReturn = data % range;
    if (toReturn < 0) {
        // NOTE: C++ % can return negative numbers if the value beeing
        // modded is negative.  To fix: add range to get positive.
        toReturn += range;
    }
    return toReturn;
}

int hash(string data, int range) {
    int hash_value = 0;
    for (int i = 0; i < data.length(); i++) {
        hash_value *= 31;       // prime number helps to avoid hash collisions
        hash_value += data[i]; // remember: characters can be treated as ints
    }

    // now, compress down to range
    int toReturn = hash_value % range;
    if (toReturn < 0) {
        toReturn += range;
    }
    return toReturn;
}
