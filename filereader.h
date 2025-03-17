/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/

#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>

using namespace std;

/* File Reader Class
   -- reads data from a file
*/
class FileReader {
public:
   FileReader(); // constructor
   void readCommands(ifstream infile); // reads commands from file
   void readCustomers(ifstream infile); // reads customers from file
   void readMovies(ifstream infile); // reads movies from file
};

#endif