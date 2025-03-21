/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   HashTable Class

   Note - as this assignment only needs chars or ints as hash values, the hash
   function should work - however, may need to be implemented differently
   if different data types are used in a Hash Table subclass

*/

#pragma once

#include <cstddef>
/**
 * @brief Inserts a key-value pair into the hash table.
 *
 * This function inserts the given key and value into the hash table. If the 
 * load factor exceeds 0.7 after the insertion, the hash table is resized to 
 * accommodate more elements. The function also ensures that duplicate key-value 
 * pairs are not inserted.
 *
 * @tparam K Type of the key.
 * @tparam V Type of the value.
 * @param key The key to be inserted.
 * @param value The value to be inserted.
 * @return true if the insertion is successful or if the key-value pair already exists.
 */

template <typename K, typename V>
class HashTable {

private:

   struct Entry {
      K key;
      V value;
      bool occupied;

      Entry() : occupied(false) {}

      Entry (const K& k, const V& v) : key(k), value(v), occupied(false) {}
   };

   Entry* table;
   size_t capacity;
   size_t count;

   virtual size_t hash(const K& key) const;

   size_t findIndex(const K& key) const;

   void resize(size_t newCapacity);

public:

   HashTable(size_t initialCapacity = 101);
   
   virtual ~HashTable();

   bool insert(const K& key, const V& value);

   bool contains(const K& key);

   V* find(const K& key);

   size_t getSize() const;

   bool isEmpty() const;

};

#include "hashtable.hpp"