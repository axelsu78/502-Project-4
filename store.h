/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   Inventory Class
*/

#ifndef STORE_H
#define STORE_H 
#include "movie.h"
#include "customer.h"
#include "hashtable.h"
#include "moviebst.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MOVIE_GENRES = 3;  // number of movie genres

/* Store class
   -- supports methods that access a store's inventory and customer information 
*/
class Store {

public:
                   
    MovieBST<Movie>* movieInventory[MOVIE_GENRES - 1];   // array of binary search trees for movie genres

    Store();                                    // constructor
    ~Store();                                   // destructor
    int getMovieCount(Movie *movie);            // returns count of movie in inventory
    void inventory();                           // displays inventory of movies

private:
    
HashTable<int ID, Customer*> customers;    // hash table of customers
};

#endif