/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include "keywordSearcher.h"
#include <iostream> 
#include <fstream> 
#include <vector>
#include <string>

#include <stdexcept>

using namespace std;

KeywordSearcher::KeywordSearcher() {
    this-> hash1 = new HashTable<string, HashTable<int, int>*>();
}

KeywordSearcher::~KeywordSearcher() {
    vector<string> keys = hash1->getKeys();
    for(int j=0; j< keys.size(); j++){
        delete hash1->get(keys[j]);
    }
    delete hash1;
}



void KeywordSearcher::loadWords(string filename) {
    ifstream file;
    string word;
    int page_number;
    file.open(filename);
    if (!file.is_open()){
        throw runtime_error("Unable to open file " + filename + ".");
    }
    while (!file.eof()){
        file >> word;
        if (word == "$$@@$$PAGE:"){
            file >> word;
            page_number = stoi(word);
        } else{
            addWords(word, page_number);
        }   
    }
    file.close();
}

vector<pair<int, int>> KeywordSearcher::search(string word) {
    vector<pair<int, int>> final_vector;
    if (hash1->contains(word) == false){
        return final_vector;
    }else{
        vector<pair<int, int>> vector_items = hash1->get(word)->getItems();
        vector<pair<int, int>> vector_queue;
        for (int i=0; i < vector_items.size();i++ ){
            pair<int, int> pair1(vector_items[i].second, vector_items[i].first);
            vector_queue.push_back(pair1);
        }
        STLMaxPriorityQueue<int, int>* priority_queue = new STLMaxPriorityQueue<int, int>(vector_queue);
        while (!priority_queue->isEmpty() && final_vector.size()<10){
            //store peekpriortiy
            int temp_peek = priority_queue->peekPriority();
            int temp_value = priority_queue->remove();
            pair<int, int> temp_pair(temp_value, temp_peek);
            
            final_vector.push_back(temp_pair);
        }
        delete priority_queue;
        return final_vector;
    }
}

void KeywordSearcher::addWords(string word, int page_number){
    if (this->hash1->contains(word) == true){
        HashTable<int, int>* hash_inside = hash1->get(word);
        if (hash_inside->contains(page_number)){
            int occurences = hash_inside->get(page_number);
            hash_inside->update(page_number, occurences+1);
        } else {
            hash_inside->insert(page_number,1);
        }
    } else {
        HashTable<int, int>* hash_inside = new HashTable<int, int>();
        int one = 1;
        hash_inside->insert(page_number, one);
        hash1->insert(word, hash_inside);

    }
    
}
