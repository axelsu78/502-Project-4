/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/
#include "filereader.h"
#include "inventorystorage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

FileReader::FileReader() {}

vector<std::string> FileReader::readCommands(ifstream &infile) {
    string command;
    vector<std::string> actionCommands;
    while (getline(infile, command)) {
        actionCommands.push_back(command);
    }
    return actionCommands;
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
