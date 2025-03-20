/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/

#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/* File Reader Class
   -- reads data from a file
*/
class FileReader {
public:
   FileReader(); // constructor
   vector<std::string> readCommands(ifstream &infile); // reads commands from file
   void readCustomers(ifstream &infile, InventoryStorage& inventory); // reads customers from file
   vector<std::string> readMovies(ifstream &infile, InventoryStorage& inventory); // reads movies from file
};

#endif 