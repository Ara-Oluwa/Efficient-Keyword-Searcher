/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include <string>
#include "hashTable.h"
using namespace std;

int main(int argc, char** argv) {
    // You can use this main to experiment with the code you have written
  HashTable<int,string> H;
  H.insert(0,"0");
  H.insert(1,"1");
  H.insert(2,"2");
  H.insert(3,"3");
  H.insert(4,"4");
  H.insert(5,"5");
  H.insert(6,"6");
  H.insert(7,"7");
  H.insert(8,"8");
  H.insert(9,"9");
  return 0;
}
