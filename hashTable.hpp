/* Axel Sundstrom, Cameron Chen
CSS 502 Assignment 4
HashTable Class

Note - as this assignment only needs chars or ints as hash values, the hash
function should work - however, may need to be implemented differently
if different data types are used in a Hash Table subclass

*/
#include "hashTable.h"
#include <cstddef>



template <typename K, typename V>
std::size_t HashTable<K,V>::hash(const K& key) const {
   return static_cast<std::size_t>(key);
}

template <typename K, typename V>
std::size_t HashTable<K,V>::findIndex(const K& key) const{
   std::size_t index = hash(key) % capacity;
   std::size_t originalIndex = index;
   int i = 0;

   while (table[index].occupied == true && table[index].key != key){
      i++;
      index = (originalIndex + i*i) % capacity;

      if (index == originalIndex){
         break;
      }
   }

   return index;
}

template <typename K, typename V>
void HashTable<K,V>::resize(std::size_t newCapacity){
   Entry* oldTable = table;
   std::size_t oldCapacity = capacity;

   table = new Entry[newCapacity];
   capacity = newCapacity;
   count = 0;

   for (std::size_t i = 0; i < oldCapacity; i++){
      if (oldTable[i].occupied){
         insert(oldTable[i].key, oldTable[i].value);
      }
   }

   delete[] oldTable;

}

template <typename K, typename V>
HashTable<K,V>::HashTable(std::size_t initialCapacity) : capacity(initialCapacity), count(0) {
table = new Entry[capacity]();
}

template <typename K, typename V>
HashTable<K,V>::~HashTable(){
   delete[] table;
}

template <typename K, typename V>
bool HashTable<K,V>::insert(const K& key, const V& value){
   if (static_cast<double>(count + 1) / capacity > 0.7) {
      resize(capacity * 2 - 1);
   }

   std::size_t index = findIndex(key);

   // prevents duplicate values
   if (table[index].occupied == true
      && table[index].key == key
      && table[index]. value == value){
      return true;
   }

   table[index].key = key;
   table[index].value = value;
   table[index].occupied = true;
   count++;

   return true;
}

template <typename K, typename V>
bool HashTable<K,V>::contains(const K& key){
   std::size_t index = findIndex(key);

   return table[index].occupied && (table[index].key == key);
}

template <typename K, typename V>
V* HashTable<K,V>::find(const K& key){
   std::size_t index = findIndex(key);

   if (table[index].occupied && table[index].key == key){
      return &(table[index].value);
   }

   return nullptr;

}

template <typename K, typename V>
std::size_t HashTable<K,V>::getSize() const {
   return count;
}

template <typename K, typename V>
bool HashTable<K,V>::isEmpty() const {
   return (count == 0);
}


