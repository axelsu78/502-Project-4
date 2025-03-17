/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Test 
*/
 
#include "filereader.h"
#include <fstream>
#include <iostream> 
using namespace std;

int main() {
    FileReader reader;

    ifstream infile("data4movies.txt");
    reader.readMovies(infile);
    infile.close();

    ifstream infile2("data4commands.txt");
    reader.readCommands(infile2);
    infile2.close();


    ifstream infile3("data4customers.txt");
    reader.readCustomers(infile3);
    infile3.close();

};