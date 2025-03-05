/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   Inventory Storage Class
*/

#ifndef INVENTORYSTORAGE_H
#define INVENTORYSTORAGE_H
#include "movie.h"
#include <iostream>

using namespace std;

/* InventoryStorage class
   -- stores inventory of Movie objects in a rental system
*/

class InventoryStorage {
public:
    void getInventory() const; // displays inventory of movies

private:
    const int MOVIE_GENRES = 3; // number of movie genres
    MovieBST movieInventory[MOVIE_GENRES]; // array of binary search trees for movie genres
};

#endif