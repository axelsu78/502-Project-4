/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/

#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <iostream>
#include <vector>
#include "inventorystorage.h"
using namespace std;

/* File Reader Class
   -- reads data from a file
*/
class FileReader {
public:
   FileReader(); // constructor
   
   /**
    * @brief creates a vector of all legal commands to be read by main
    * 
    * @param infile the file containing all commands
    * @return vector<std::string> vector where all legal commands are stored
    */
   vector<std::string> readCommands(ifstream &infile); // reads commands from file
   
   /**
    * @brief reads file for all legal customers and adds to customer hashtable
    * 
    * @param infile file containing customer commands
    * @param inventory inventory storage class containing hash table for items to be stored to
    */
   void readCustomers(ifstream &infile, InventoryStorage& inventory); // reads customers from file
   
   /**
    * @brief reads file for all legal movies and adds them to BST associated with type
    * 
    * @param infile file containing movie commands
    * @param inventory inventory storage class containing Movie BSTs for items to be stored to
    */
   void readMovies(ifstream &infile, InventoryStorage& inventory); // reads movies from file
};

#endif 