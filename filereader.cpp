/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/
#include "filereader.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

FileReader::FileReader() {
    
}

void FileReader::readCommands(ifstream &infile) {
    string command;
    while (getline(infile, command)) {
        cout << command << endl;
    }
}

void FileReader::readCustomers(ifstream &infile) {
    string id;
    string firstName;
    string lastName;
    while (infile >> id >> firstName >> lastName) {
        cout << id << " " << firstName << " " << lastName << endl;
    }
}

void FileReader::readMovies(ifstream &infile) {
    string line;
    while (getline(infile, line)) {  // Read each full line from the file
        stringstream ss(line);  // Use stringstream to split by commas
        string type, stock, director, title, actor, releaseMonth, releaseYear;
        
        // Read type (which is a single character)
        getline(ss, type, ',');
        
        // Read stock
        getline(ss, stock, ',');
        
        // Read director
        getline(ss, director, ',');
        
        // Read title
        getline(ss, title, ',');
        
        // For type "C", read actor and releaseMonth
        if (type == "C") {
            while (getline(ss, actor, ',')) { // Keep reading actors until no more commas
                getline(ss, releaseMonth, ','); // Read releaseMonth after actor
                getline(ss, releaseYear); // Read releaseYear (last part, no comma)
                
                // Print for each actor in type "C"
                cout << "C " << stock << " " << director << " " << title << " " 
                     << actor << " " << releaseMonth << " " << releaseYear << endl;
            }
        } 
        // Handle type "F" or "D"
        else if (type == "F" || type == "D") {
            getline(ss, releaseYear); // Read the releaseYear for F and D types
            cout << type << " " << stock << " " << director << " " << title << " " << releaseYear << endl;
        }
        else {
            cout << "Invalid movie type: " << type << endl;
        }
    }
}
