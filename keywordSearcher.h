#pragma once

/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Fall 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/5y84s7e
*/

#include <string>
#include <vector>
#include "hashTable.h"
#include "adts/stlMaxPriorityQueue.h"

/**
 * This class represents a tool which can be used to perform a keyword
 * search on a document.  The user of this class instantiates it,
 * updates it with words from a document, and can then use it to
 * identify the pages on which specific words appear most frequently.
 */
class KeywordSearcher {
  public:
    /**
     * Creates a new keyword searcher with no data.
     */
    KeywordSearcher();

    /**
     * Destructs a KeywordSearcher and releases the memory it is using.
     */
    ~KeywordSearcher();

    /**
     * Loads the words from a given file into this searcher.
     * @param filename The name of the text file to use.
     * Throws a runtime error if the filename does not exist.
     */
    void loadWords(std::string filename);

    /**
     * Searches this object to find the pages on which a particular word most
     * frequently appeared.
     * @param word The word to find.
     * @return A vector of pairs between page numbers and occurrences.  The top
     *         ten pages are returned, ordered from most to least occurrences.
     *         All pairs have a positive (non-zero) number of occurrences; if a
     *         word appears on fewer than ten pages, the returned vector
     *         contains fewer than ten elements.
     */
    std::vector<std::pair<int, int>> search(std::string word);

  private:
    // TODO: put your fields and helper declarations here!
    HashTable<std::string, HashTable<int, int>*>* hash1;

    /*
    *add the words to the hastable
    * @param word the word to add
    * @param page_number the page number the word is on
    *returns void
    * throws runtime_error if the word is already in the hash table
    */
    void addWords(std::string word, int page_number);
};
