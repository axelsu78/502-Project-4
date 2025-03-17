 /* Axel Sundstrom, Cameron Chen
    CSS 502 Assignment 4
    File Reader Class
 */

 #include "filereader.h"
 #include <fstream>
 #include <iostream>
 using namespace std;

 
 FileReader::FileReader() {
    
 }
 
 void FileReader::readCommands(ifstream infile) {
    string command;
    while (infile >> command) {
        cout << command << endl;
    }
 }

 void FileReader::readCustomers(ifstream infile) {
    string id;
    string firstName;
    string lastName;
    while (infile >> id >> firstName >> lastName) {
        cout << id << " " << firstName << " " << lastName << endl;
    }
 }
 void FileReader::readMovies(ifstream infile) {
    string type;
    string stock;
    string director;
    string title;
    string actor;
    string releaseMonth;
    string releaseYear;
    while (infile >> type) {
        if (type == "F") {
            infile >> stock >> director >> title >> releaseYear;
            cout << type << " " << stock << " " << director << " " << title << " " << releaseYear << endl;
        } else if (type == "D") {
            infile >> stock >> director >> title >> releaseYear;
            cout << type << " " << stock << " " << director << " " << title << " " << releaseYear << endl;
        } else if (type == "C") {
            infile >> stock >> director >> title >> actor >> releaseMonth >> releaseYear;
            cout << type << " " << stock << " " << director << " " << title << " " << actor << " " << releaseMonth << " " << releaseYear << endl;
        }
    }   
 }