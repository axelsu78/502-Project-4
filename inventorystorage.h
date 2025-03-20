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
#include "comedyfactory.h"
#include "classicfactory.h"
#include "dramafactory.h"
#include "moviefactory.h"
#include <iostream>

using namespace std;

/* InventoryStorage class
   Contains all data structures used to store data
   -- sidenote: probably should be renamed to "Store" but didn't feel like refactoring
*/

class InventoryStorage {
public:
    
    InventoryStorage();

    /**
     * @brief displays all movies in inventory
     * 
     */
    void getInventory() const;

    HashTable<int, std::shared_ptr<Customer>> customerSearchTable;
    
    // vector containing all valid action commands
    vector<string> actionCommands;

    ComedyFactory comedyFactory;
    DramaFactory dramaFactory;
    ClassicFactory classicFactory;

    MovieBST<Movie> comedyTree;
    MovieBST<Movie> dramaTree;
    MovieBST<Movie> classicTree;

};

#endif