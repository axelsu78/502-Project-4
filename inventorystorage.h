/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Inventory Storage Class
*/

#ifndef INVENTORYSTORAGE_H
#define INVENTORYSTORAGE_H
#include "movie.h"
#include "moviebst.h"
#include "hashtable.h"
#include "action.h"
#include "actionfactory.h"
#include "moviefactory.h"
#include <iostream>

using namespace std;

/* InventoryStorage class
   -- stores inventory of Movie objects in a rental system
*/

class InventoryStorage {
public:
    
    InventoryStorage();

    ~InventoryStorage();

    void getInventory() const; // displays inventory of movies
    
    HashTable<char, std::unique_ptr<MovieBST<Movie>>> movieSearchTable;
    HashTable<int, std::shared_ptr<Customer>> customerSearchTable;
    HashTable<char, std::unique_ptr<ActionFactory>> actionFactoryTable;
    HashTable<char, std::shared_ptr<MovieFactory>> movieFactoryTable;
    vector<string> customerCommands;
    vector<string> movieCommands;
    vector<string> actionCommands;
};

#endif