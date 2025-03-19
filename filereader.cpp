/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/
#include "filereader.h"
#include "actionfactory.h"
#include "customer.h"
#include "movieparams.h"
#include "moviefactory.h"
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
    while (getline(infile, line)) {  
        stringstream ss(line);  
        string type, stock, director, title, actor, releaseMonth, releaseYear;
        
        getline(ss, type, ',');
        
        getline(ss, stock, ',');
        
        getline(ss, director, ',');
        
        getline(ss, title, ',');
        
        if (type == "C") {
            while (getline(ss, actor, ',')) { 
                getline(ss, releaseMonth, ','); 
                getline(ss, releaseYear); 
                
                cout << "C " << stock << " " << director << " " << title << " " 
                     << actor << " " << releaseMonth << " " << releaseYear << endl;
            }
        } 

        else if (type == "F" || type == "D") {
            getline(ss, releaseYear); 
            cout << type << " " << stock << " " << director << " " << title << " " << releaseYear << endl;
        }
        else {
            cout << "Invalid movie type: " << type << endl;
        }
    }
}
