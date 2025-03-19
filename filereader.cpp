/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   File Reader Class
*/
#include "filereader.h"
#include "actionfactory.h"
#include "customerstorage.h"
#include "movieparams.h"
#include "moviefactory.h"
#include "returnfactory.h"
#include "borrowfactory.h"
#include "inventorystorage.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

FileReader::FileReader() {}

void FileReader::readCommands(ifstream &infile) {
    string command;
    while (getline(infile, command)) {
    
        // B - create borrow object, check if movie matches all parameters, and add to customer history if customer ID is valid  and movie is in stock
        if (command[0] == 'B') {
            // Create borrow object using ActionFactory
            ActionFactory actionFactory;
            Action* actionObj = actionFactory.createAction(command);

            // Check if actionObj is created successfully
            if (actionObj == nullptr) {
            cout << "Error: Failed to create action object." << endl;
            continue;
            }
            // Check if movie matches all parameters
            if (inventory.isMovieInStock(actionObj->getMovie())) {
            // Check if customer ID is valid
            if (customerTable.isValidCustomer(actionObj->getCustomerID())) {
                // Add to customer history
                customerTable.getCustomer(actionObj->getCustomerID()).borrowMovie(actionObj->getMovie());
                // Remove movie from stock
                inventory.borrowMovie(actionObj->getMovie());
            } else {
                cout << "Error: Invalid customer ID." << endl;
            }
            } else {
            cout << "Error: Movie not in stock." << endl;
            }
            delete actionObj;
        }

        // R - create return object, check if customer ID valid and that the movie is in their borrow history, and return movie to stock
        if (command[0] == 'R') {
            // Create return object using ReturnFactory
            ReturnFactory returnFactory;
            Return* returnObj = returnFactory.createReturn(command);

            // Check if returnObj is created successfully
            if (returnObj == nullptr) {
            cout << "Error: Failed to create return object." << endl;
            continue;
            }
            // Check if customer ID is valid
            if (customerTable.isValidCustomer(returnObj->getCustomerID())) {
            // Check if the movie is in their borrow history
            if (customerTable.getCustomer(returnObj->getCustomerID()).hasBorrowed(returnObj->getMovie())) {
                // Return movie to stock
                inventory.returnMovie(returnObj->getMovie());
                // Update customer history
                customerTable.getCustomer(returnObj->getCustomerID()).returnMovie(returnObj->getMovie());
            } else {
                cout << "Error: Movie not found in customer's borrow history." << endl;
            }
            } else {
            cout << "Error: Invalid customer ID." << endl;
            }
            delete returnObj;
        }

        // I - calls getInventory() from inventoryStorage to output all items in the store
        if (command[0] == 'I') {
            inventory.getInventory();
        }

        // H - search for customer ID in hash table and display customer info
        if (command[0] == 'H') {
            int customerID = stoi(command.substr(2));
            if (customerTable.isValidCustomer(customerID)) {
            customerTable.getCustomer(customerID).displayHistory();
            } else {
            cout << "Error: Invalid customer ID." << endl;
            }
        }
    }
}

void FileReader::readCustomers(ifstream &infile) {
    string id;
    string firstName;
    string lastName;
    while (infile >> id >> firstName >> lastName) {
        // Create customer object and add to hash table
        Customer customer(stoi(id), firstName, lastName);
        customerTable.addCustomer(customer);
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
                // Create movie object and add to inventory
                MovieParams params = {stock, director, title, actor, releaseMonth, releaseYear};
                MovieFactory movieFactory;
                Movie* movie = movieFactory.createMovie(type, params);
                inventory.addMovie(movie);
            }
        } 

        else if (type == "F" || type == "D") {
            getline(ss, releaseYear); 
            // Create movie object and add to inventory
            MovieParams params = {stock, director, title, releaseYear};
            MovieFactory movieFactory;
            Movie* movie = movieFactory.createMovie(type, params);
            inventory.addMovie(movie);
        }
        else {
            cout << "Invalid movie type: " << type << endl;
        }
    }
}
