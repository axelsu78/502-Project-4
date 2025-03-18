/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Customer Storage Class
*/

#ifndef CUSTOMERSTORAGE_H
#define CUSTOMERSTORAGE_H
#include "customer.h"
#include "hashtable.h"
#include <iostream>

using namespace std;

/* CustomerStorage class
   -- stores customers in a hash table
*/

class CustomerStorage {
public:
    void getHistory(int customerID);                 // displays rental history of customer
private:
    HashTable<int ID, Customer*>* customers;         // hash table of customers
};

#endif