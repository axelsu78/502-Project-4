/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   HashTable Class

   Note - as this assignment only needs chars or ints as hash values, the hash
   function should work - however, may need to be implemented differently
   if different data types are used in a Hash Table subclass

*/

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

   virtual size_t hash(const key& key) const {
      return static_cast<size_t>(key);
   }

   size_t findIndex(const key& key) const{
      size_t index = hash(key) % capacity;
      size_t originalIndex = index;
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

   void resize(size_t newCapacity){
      Entry* oldTable = table;
      size_t oldCapacity = capacity;

      table = new Entry*[newCapacity];
      capacity = newCapacity;
      count = 0;

      for (size_t i = 0; i < oldCapacity; i++){
         if (oldTable[i].occupied){
            insert(oldTable[i].key, oldTable[i].value);
         }
      }

      delete[] oldTable;

   }

public:

   HashTable(size_t initialCapacity = 101) : capacity(initialCapacity), count(0) {
      table = new Entry[capacity];
   }
   
   virtual ~HashTable(){
      delete[] table;
   }

   bool insert(const K& key, const V& value){
      if (static_cast<double>(count + 1) / capacity > 0.7) {
         resize(capacity * 2 - 1);
      }

      size_t index = findIndex(key);

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

   bool contains(const K& key){
      size_t index = findIndex(key);

      return table[index].occupied && !table[index].key == key;
   }

   V* find(const K& key){
      size_t index = findIndex(key);

      if (table[index].occupied && table[index].key == key){
         return &(table[index].value);
      }

      return nullptr;

   }

   size_t getSize() const {
      return count;
   }

   bool isEmpty() const {
      return (count == 0);
   }

};
