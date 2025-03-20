/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/
#include "filereader.h"
#include "inventorystorage.h"
#include "dvd.h"
#include "mediatype.h"
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

void FileReader::readCustomers(ifstream &infile, InventoryStorage& inventory) {
    string id;
    string firstName;
    string lastName;
    vector<Customer> customers;

    while (infile >> id >> firstName >> lastName) {
        int customerID = stoi(id);
        auto customer = std::make_shared<Customer>(customerID, firstName, lastName);
        inventory.customerSearchTable.insert(customerID, customer);
    }
}

vector<std::string> FileReader::readMovies(ifstream &infile, InventoryStorage& inventory) {
    string line;
    vector<std::string> movieCommands;
    while (getline(infile, line)) {  
        stringstream ss(line);  
        string type, director, title, actor, stock, releaseYear;
        
        getline(ss, type, ',');
        if (type == "C") {
            string releaseMonth, leadActor;
            while (getline(ss, actor, ',')) { 
                getline(ss, releaseMonth, ','); 
                getline(ss, releaseYear); 
                
                cout << "C " << stock << " " << director << " " << title << " " 
                     << actor << " " << releaseMonth << " " << releaseYear << endl;
            }
        }

        else if (type == "F") {
            getline(ss, stock, ',');
            getline(ss, director, ',');
            getline(ss, title, ',');
            getline(ss, releaseYear, ',');
            int stockInt = stoi(stock);
            int yearInt = stoi(releaseYear);

            std::shared_ptr<MediaType> dvd = std::make_shared<DVD>();

            MovieParams* params = new MovieParams(title, director, yearInt, stockInt, dvd);

            auto movie = inventory.comedyFactory.createMovie(*params);

            inventory.comedyTree.insert(movie);

        }
        else if (type == "D"){
            getline(ss, stock, ',');
            getline(ss, director, ',');
            getline(ss, title, ',');
            getline(ss, releaseYear, ',');
            int stockInt = stoi(stock);
            int yearInt = stoi(releaseYear);

            std::shared_ptr<MediaType> dvd = std::make_shared<DVD>();

            MovieParams* params = new MovieParams(title, director, yearInt, stockInt, dvd);

            auto movie = inventory.dramaFactory.createMovie(*params);

            inventory.dramaTree.insert(movie);
        }
        else {
            cout << "Invalid movie type: " << type << endl;
        }
    }
}
