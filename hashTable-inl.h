/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    this-> maxLoadFactor = 0.75;
    this-> size = 0;
    this-> capacity = 10;
    this-> array1 = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    //throw runtime_error(
        //"Not yet implemented: HashTable<K,V>::HashTable(float)");
    this-> maxLoadFactor = maxLoadFactor;
    this-> size = 0;
    this-> capacity = 10;
    this-> array1 = new LinearDictionary<K, V>[this->capacity];
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    // TODO: HashTable<K,V>::~HashTable
    delete[] array1;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    //throw runtime_error("Not yet implemented: HashTable<K,V>::getSize");
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    //throw runtime_error("Not yet implemented: HashTable<K,V>::isEmpty");
    if (this->size == 0){
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V> void HashTable<K, V>::insertion(K key, V value) {
    int key_num = hash(key,this->capacity); 
    this->array1[key_num].insert(key, value);

}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    
    if(((size+1)/float(this->capacity)) > maxLoadFactor) {
        int new_capacity = this->capacity*2;
        LinearDictionary<K, V>* temp_array = new LinearDictionary<K, V>[new_capacity];
        vector<pair<K, V>> temp_items = this->getItems();
        delete[] this->array1;
        this->array1 = temp_array;
        this->capacity = new_capacity;
            for(int j=0; j< temp_items.size(); j++){
                this->insertion(temp_items[j].first,temp_items[j].second);
            }
        
        this->insertion(key,value);
        size = size + 1;
    } else {
        this->insertion(key,value);
        size =  size + 1;
    }
        
} 


template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int check = 0;
    int i = hash(key, capacity);
    if (array1[i].contains(key) == true){
        array1[i].update(key, value);
        check += 1;
    }
    
    if (check == 0){
        throw runtime_error("Key not found");
    }
}


template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int i = hash(key, capacity);
    if (array1[i].contains(key) == true){
        return array1[i].get(key);
    }
    throw runtime_error("Key not found");
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    int i = hash(key, capacity);
    if (array1[i].contains(key) == true){
        return true;
    } else {
        return false;
    }
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    int j = hash(key, capacity);
    int check = 0;
    if (this->size == 0){
        throw runtime_error("Array is empty");
    }
    
        if (array1[j].contains(key) == true){
            array1[j].remove(key);
            this->size -- ;
            check += 1;
        }
    
    if (check == 0){
        throw runtime_error("Key not found");
    }
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> vector_keys;
    vector<K> temp_vector;
    for (int i=0; i < this->capacity; i++){
        temp_vector = this->array1[i].getKeys();
        for (int j=0; j < temp_vector.size(); j++){
            vector_keys.push_back(temp_vector[j]);
        }
        
    }
    return vector_keys;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    //throw runtime_error("Not yet implemented: HashTable<K,V>::getItems");
    vector<pair<K, V>> vector_items;
    vector<pair<K, V>> temp_vector_pairs;
    for (int i=0; i < this-> capacity; i++){
        temp_vector_pairs = array1[i].getItems();
        for (int j=0; j < array1[i].getSize(); j++){
            vector_items.push_back(temp_vector_pairs[j]);
        }
    }
    return vector_items;
}

// TODO: put any other definitions here
