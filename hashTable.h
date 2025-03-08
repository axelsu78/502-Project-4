/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   HashTable Class

   Note - as this assignment only needs chars or ints as hash values, the hash
   function should work - however, may need to be implemented differently
   if different data types are used in a Hash Table subclass

*/

#include <cstddef>

template <typename K, typename V>
class HashTable {

private:

   struct Node {
      K key;
      V value;
      bool occupied;

      Node (constK& k, const V& v) : key(k), value(v), occupied(false) {}
   };

   Entry* table;
   size_t capacity;
   size_t count;

   virtual size_t hash(const key& key) const;

   size_t findIndex(const key& key) const;

   void resize(size_t newCapacity);

public:

   HashTable(size_t initialCapacity = 101) : capacity(initialCapacity), count(0) {
      table = new Entry[capacity];
   }
   
   virtual ~HashTable();

   bool insert(const K& key, const V& value);

   bool contains(const K& key);

   V* find(const K& key);

   size_t getSize() const;

   bool isEmpty() const;

};

#include "hashTable.hpp"