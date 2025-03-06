/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include <stdexcept>
using std::runtime_error;

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    //throw std::runtime_error(
    


}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    // TODO: LinearDictionary<K,V>::~LinearDictionary
    
    
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return vector1.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    if (vector1.size() == 0){
        return true;
    } else {
        return false;
    }
        
    
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    pair<K,V> pair1(key,value);
    for(int i=0; i < vector1.size(); i++){
        if (vector1[i].first == key){
            throw runtime_error("Key already exists");
        }
    }
    vector1.push_back(pair1);
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    int check = 0;
   for(int i=0; i < vector1.size(); i++){
        if (vector1[i].first == key){
            vector1[i].second = value;
            check += 1;
        }
    }
    if (check == 0){
        throw runtime_error("key not found");
    }
    
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    for(int i=0; i < vector1.size(); i++){
        if (vector1[i].first == key){
            return vector1[i].second;
        }
    }
    throw runtime_error("key not found");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for(int i=0; i < vector1.size(); i++){
        if(vector1[i].first == key) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    int key_index= 0;
    int check = 0;
    if (vector1.size() == 0){
        throw runtime_error("vector is empty");
    }
    for(int i=0; i < vector1.size(); i++){
        if(vector1[i].first == key){
            key_index = i;
            check += 1;

        }
    }

    if(check == 0){
        throw runtime_error("key not found");
    }

    vector1.erase(vector1.begin()+ key_index, vector1.begin() + key_index + 1);
    
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> vector_keys;
    for(int i=0; i < this->vector1.size(); i++){
        vector_keys.push_back(this->vector1[i].first);
    }
    return vector_keys;
   
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    return vector1;
}
