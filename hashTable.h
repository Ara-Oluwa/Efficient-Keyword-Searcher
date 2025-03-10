#pragma once

/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include <utility> // for the "pair" STL class
#include <vector>

#include "adts/dictionary.h"
#include "linearDictionary.h"
#include "adts/dictionary.h"

template <typename K, typename V> class HashTable : public Dictionary<K, V> {
  public:
    /**
     * Creates a new HashTable with a maximum load factor of 0.75.
     */
    HashTable();

    /**
     * Creates a new HashTable.
     * @param maxLoadFactor The maximum load factor which will be permitted
     *                      before this hash table changes its capacity.
     */
    HashTable(float maxLoadFactor);
    /**
     * Cleans up this HashTable.
     */
    ~HashTable();

    /* Dictionary ADT Methods.
       You must implement these acording to ADT specification
     */
    int getSize();
    bool isEmpty();
    void insert(K key, V value);
    void update(K key, V value);
    V get(K key);
    bool contains(K key);
    void remove(K key);
    vector<K> getKeys();
    vector<pair<K, V>> getItems();

  private:
    /* TODO: put your member variables and helper methods here */
    LinearDictionary<K, V>* array1;

    /* inserts keys and value to the right index in an array1
    returns void
    param: key & value
    Does not expand capacity
    */
    void insertion(K key,V value);
    float maxLoadFactor;
    int size;
    int capacity; 
};

#include "hashTable-inl.h"
