/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Store Class
*/

#include "store.h"
#include "movie.h"
#include "customer.h"
#include "hashtable.h"
#include "moviebst.h"
#include "inventorystorage.h"
#include <iostream>
#include <fstream>
using namespace std;

Store::Store() {
    customers = new HashTable<int, Customer*>();
    inventory = new MovieBST();
}

Store::~Store() {
    delete customers;
    delete inventory;
}

int Store::getMovieCount(Movie *movie) {
    return inventory->getMovieCount(movie);
}

void Store::getInventory() {
    inventory->display();
}