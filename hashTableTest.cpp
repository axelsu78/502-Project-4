/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   HashTable Test Program
*/

#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <memory>
#include "hashTable.h"

// Simple class to use as a value in the hash table
class MovieBST {
private:
    std::string name;
    int movieCount;

public:
    MovieBST(const std::string& n, int count) : name(n), movieCount(count) {}
    
    std::string getName() const { return name; }
    int getMovieCount() const { return movieCount; }
    
    void setMovieCount(int count) { movieCount = count; }
    
    // Needed for the HashTable's duplicate checking
    bool operator==(const MovieBST& other) const {
        return name == other.name && movieCount == other.movieCount;
    }
};

// Simple class to use as a factory
class MovieFactory {
private:
    std::string type;
    int createdCount;

public:
    MovieFactory(const std::string& t) : type(t), createdCount(0) {}
    
    std::string getType() const { return type; }
    
    void createMovie() { createdCount++; }
    int getCreatedCount() const { return createdCount; }
    
    // Needed for the HashTable's duplicate checking
    bool operator==(const MovieFactory& other) const {
        return type == other.type && createdCount == other.createdCount;
    }
};

// Test helper functions
void printTestHeader(const std::string& testName) {
    std::cout << "\n===== " << testName << " =====\n";
}

void printTestResult(bool passed) {
    std::cout << (passed ? "PASSED ✓" : "FAILED ✗") << std::endl;
}

// Test function templates
template <typename K, typename V>
void testBasicOperations(const std::string& testName, const std::vector<K>& keys, const std::vector<V>& values) {
    printTestHeader(testName);
    
    HashTable<K, V*> hashTable;
    
    // Test isEmpty initially
    bool isEmptyInitially = hashTable.isEmpty();
    std::cout << "Is empty initially: " << (isEmptyInitially ? "Yes" : "No") << std::endl;
    printTestResult(isEmptyInitially);
    
    // Test insert and size
    std::vector<V*> pointers;
    for (size_t i = 0; i < keys.size(); i++) {
        V* ptr = new V(values[i]);
        pointers.push_back(ptr);
        bool inserted = hashTable.insert(keys[i], ptr);
        std::cout << "Inserted key " << static_cast<int>(keys[i]) << ": " << (inserted ? "Yes" : "No") << std::endl;
    }
    
    std::cout << "Hash table size: " << hashTable.getSize() << std::endl;
    printTestResult(hashTable.getSize() == keys.size());
    
    // Test contains
    for (size_t i = 0; i < keys.size(); i++) {
        bool contains = hashTable.contains(keys[i]);
        std::cout << "Contains key " << static_cast<int>(keys[i]) << ": " << (contains ? "Yes" : "No") << std::endl;
        assert(contains);
    }
    
    // Test a key that doesn't exist
    K nonExistentKey = keys.back() + 1;
    bool containsNonExistent = hashTable.contains(nonExistentKey);
    std::cout << "Contains non-existent key " << static_cast<int>(nonExistentKey) << ": " 
              << (containsNonExistent ? "Yes" : "No") << std::endl;
    printTestResult(!containsNonExistent);
    
    // Test find and dereference
    for (size_t i = 0; i < keys.size(); i++) {
        V** found = hashTable.find(keys[i]);
        std::cout << "Found key " << static_cast<int>(keys[i]) << ": " << (found != nullptr ? "Yes" : "No") << std::endl;
        assert(found != nullptr);
        assert(*found == pointers[i]);
    }
    
    // Test find for non-existent key
    V** notFound = hashTable.find(nonExistentKey);
    std::cout << "Found non-existent key " << static_cast<int>(nonExistentKey) << ": " 
              << (notFound != nullptr ? "Yes" : "No") << std::endl;
    printTestResult(notFound == nullptr);
    
    // Cleanup
    for (V* ptr : pointers) {
        delete ptr;
    }
}

// Test resize functionality
void testResize() {
    printTestHeader("Testing Resize Functionality");
    
    HashTable<int, MovieBST*> hashTable(10); // Start with a small capacity
    
    // Insert enough elements to trigger resize
    const int NUM_ELEMENTS = 20;
    std::vector<MovieBST*> pointers;
    
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        MovieBST* bst = new MovieBST("BST" + std::to_string(i), i);
        pointers.push_back(bst);
        hashTable.insert(i, bst);
        std::cout << "Inserted element " << i << std::endl;
    }
    
    std::cout << "Final hash table size: " << hashTable.getSize() << std::endl;
    printTestResult(hashTable.getSize() == NUM_ELEMENTS);
    
    // Verify all elements are still accessible after resize
    bool allFound = true;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        MovieBST** found = hashTable.find(i);
        if (found == nullptr || *found != pointers[i]) {
            allFound = false;
            std::cout << "Failed to find element " << i << " after resize" << std::endl;
            break;
        }
    }
    
    std::cout << "All elements found after resize: " << (allFound ? "Yes" : "No") << std::endl;
    printTestResult(allFound);
    
    // Cleanup
    for (MovieBST* ptr : pointers) {
        delete ptr;
    }
}

// Test collision handling
void testCollisionHandling() {
    printTestHeader("Testing Collision Handling");
    
    // Create a tiny hash table to force collisions
    HashTable<int, MovieFactory*> hashTable(5);
    
    // These keys will definitely collide in a small table
    std::vector<int> keys = {5, 10, 15, 20, 25};
    std::vector<MovieFactory*> factories;
    
    for (size_t i = 0; i < keys.size(); i++) {
        MovieFactory* factory = new MovieFactory("Factory" + std::to_string(i));
        factories.push_back(factory);
        bool inserted = hashTable.insert(keys[i], factory);
        std::cout << "Inserted key " << keys[i] << ": " << (inserted ? "Yes" : "No") << std::endl;
    }
    
    // Verify all elements can be found despite collisions
    bool allFound = true;
    for (size_t i = 0; i < keys.size(); i++) {
        MovieFactory** found = hashTable.find(keys[i]);
        if (found == nullptr || *found != factories[i]) {
            allFound = false;
            std::cout << "Failed to find element with key " << keys[i] << " after collision" << std::endl;
            break;
        }
    }
    
    std::cout << "All elements found despite collisions: " << (allFound ? "Yes" : "No") << std::endl;
    printTestResult(allFound);
    
    // Test size
    std::cout << "Hash table size: " << hashTable.getSize() << std::endl;
    printTestResult(hashTable.getSize() == keys.size());
    
    // Cleanup
    for (MovieFactory* factory : factories) {
        delete factory;
    }
}

// Main function
int main() {
    std::cout << "===== HASH TABLE TEST PROGRAM =====\n";
    
    // Test with integer keys and MovieBST* values
    std::vector<int> intKeys = {1, 2, 3, 4, 5};
    std::vector<MovieBST> bstValues = {
        MovieBST("Comedy", 10),
        MovieBST("Drama", 15),
        MovieBST("Action", 20),
        MovieBST("Horror", 5),
        MovieBST("Documentary", 8)
    };
    testBasicOperations<int, MovieBST>("Testing Integer Keys with MovieBST Values", intKeys, bstValues);
    
    // Test with char keys and MovieFactory* values
    std::vector<char> charKeys = {'A', 'B', 'C', 'D', 'E'};
    std::vector<MovieFactory> factoryValues = {
        MovieFactory("ComedyFactory"),
        MovieFactory("DramaFactory"),
        MovieFactory("ActionFactory"),
        MovieFactory("HorrorFactory"),
        MovieFactory("DocumentaryFactory")
    };
    testBasicOperations<char, MovieFactory>("Testing Char Keys with MovieFactory Values", charKeys, factoryValues);
    
    // Test resize functionality
    testResize();
    
    // Test collision handling
    testCollisionHandling();
    
    std::cout << "\n===== ALL TESTS COMPLETED =====\n";
    
    return 0;
} 