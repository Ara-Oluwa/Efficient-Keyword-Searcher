/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include <iostream>
#include <string>

#include "keywordSearcher.h"

using namespace std;

int main(int argc, char** argv) {
    // TODO
    KeywordSearcher main_hash;
    if(argc == 2){
      string filename = argv[1];
      try{
        main_hash.loadWords(filename);
      } catch(runtime_error e){
        cout<< e.what() << endl;
        return 1;
      }
      cout << "File loaded." << endl;
      string user_word;

  
      while (user_word != "!"){ 
        cout << "Please enter a search word or '!' to quit: ", cin >> user_word;
   
        if(user_word == "!") {
          cout << "Goodbye!" << endl;
          break;
        }
        vector<pair<int, int>> final_vector = main_hash.search(user_word);
        if (final_vector.size() != 0){
          cout << "The word " << user_word << " appears in this file..." << endl; 
          for (int i=0; i < 10; i++){
            cout << "on page " << final_vector[i].first << " (" << final_vector[i].second << " occurences)" << endl;
          }
        } else {
          cout << "The word " << user_word << " does not appear in " << filename <<  " " << endl;
        }
      } 
    } else {
      try{
          string filename = argv[2];
          main_hash.loadWords(filename);
        } catch(runtime_error e){
          cout<< "Please enter 1 arguement." << endl;
          return 1;
      }
    }
}
