/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Main - driver for Movie Rental System
*/

/*
to build file we used:

   g++ movie.cpp movieparams.cpp borrow.cpp return.cpp filereader.cpp customer.cpp 
   borrowfactory.cpp returnfactory.cpp inventorystorage.cpp 
   comedymovie.cpp dramamovie.cpp classicmovie.cpp comedyfactory.cpp dramafactory.cpp classicfactory.cpp 
   main.cpp

just want to make sure the program doesn't have issues running 

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "inventorystorage.h"
#include "filereader.h"
#include "action.h"
#include "customer.h"
#include "movie.h"
#include "borrowfactory.h"
#include "returnfactory.h"

using namespace std;

/* Main 
   -- Driver for the Movie Rental System
   -- Reads customer, movie, and command data from files
   -- Processes the commands and performs the appropriate actions
*/


/* parseCommand()
   -- Parses a command string and performs the appropriate action
   -- cmd: command string to parse
   -- inventory: InventoryStorage object containing the data
   -- creates a search key for the movie and searches the appropriate BST
   -- performs the action on the movie if found
*/

void parseCommand(const string& cmd, InventoryStorage& inventory){
   stringstream ss(cmd);
   char commandType;
   int customerID;
   char mediaType, movieType;

   ss >> commandType >> customerID >> mediaType >> movieType;

   if (ss.fail()) {
      cout << "Error: Command format invalid - missing required parameters" << endl;
      cout << "Expected format: [B/R] [customerID] [mediaType] [movieType] [amount]" << endl;
      return;
   }

   auto customerPtr = inventory.customerSearchTable.find(customerID);
      if (!customerPtr){
         cout << "Customer not found" << endl;
         return;
      }

   string movieData;
   getline(ss, movieData);
   
   // for each movie type, create search key to find the movie in the appropriate BST
   string searchstring;

   searchstring = movieData.substr(movieData.find_first_not_of(" \t"));

   switch (movieType) {
      case 'F': {
         {
         size_t commaPos = movieData.find(',');
         if (commaPos != string::npos) {
            string title = movieData.substr(0, commaPos);
            
            while (!title.empty() && isspace(title.back())) {
               title.pop_back();
            }
           
           // Get the release year part, trimming leading whitespace
            string yearPart = movieData.substr(commaPos + 1);
            size_t firstDigit = yearPart.find_first_not_of(" \t");
            if (firstDigit != string::npos) {
               yearPart = yearPart.substr(firstDigit);
            }
            
            int releaseYear = stoi(yearPart);

            MovieParams params(title, "", releaseYear, 0, nullptr);

            shared_ptr<Movie> searchKey = inventory.comedyFactory.createSearchKey(params);
            auto moviePtr = inventory.comedyTree.retrieve(searchKey);
            if (moviePtr){
               switch (commandType) {
                  case 'B': { // Borrow
                     bool success = inventory.borrowFactory.createAction(*(customerPtr), moviePtr);
                     if (!success) {
                        cout << "Failed to borrow: " << moviePtr->getTitle() << endl;
                     }
                     break;
                  }
                  case 'R': { // Return
                     bool success = inventory.returnFactory.createAction(*(customerPtr), moviePtr);
                     if (!success){
                        cout << "Failed to return: " << moviePtr->getTitle() << endl;
                     }
                     break;
                  }
               default:
                  cout << "Unknown action type: " << commandType << endl;
                  return;
               }
            }
         }
      }
         break;
      }
      case 'D': {
         {
        size_t commaPos = movieData.find(',');
        if (commaPos != string::npos) {
            string director = movieData.substr(0, commaPos);
            string title = movieData.substr(commaPos + 1);
            
            
            title = title.substr(title.find_first_not_of(" \t"));
            if (title.back() == ',') {
                title = title.substr(0, title.length() - 1);
            }

         MovieParams params(title, director, 0, 0, nullptr);

         shared_ptr<Movie> searchKey = inventory.dramaFactory.createSearchKey(params);
         auto moviePtr = inventory.dramaTree.retrieve(searchKey);
         if (moviePtr){
            switch (commandType) {
               case 'B': { // Borrow
                  bool success = inventory.borrowFactory.createAction(*(customerPtr), moviePtr);
                  if (!success) {
                     cout << "Failed to borrow: " << moviePtr->getTitle() << endl;
                  }
                  break;
              }
               case 'R': { // Return
                  bool success = inventory.returnFactory.createAction(*(customerPtr), moviePtr);
                  if (!success){
                     cout << "Failed to return: " << moviePtr->getTitle() << endl;
                  }
                  break;
               }
            default:
               cout << "Unknown action type: " << commandType << endl;
               return;
            }
         }
      }
         break;
      }
      case 'C': {
         {
         // Classic format: Month Year Actor
         istringstream iss(movieData);
         int month, year;
         string actorFirstName, actorLastName;
         
         // Read the month and year
         if (!(iss >> month >> year)) {
             cout << "Invalid classic movie format. Expected: Month Year Actor" << endl;
             return;
         }
         
         // Read the actor's name (rest of the line)
         string actorFullName;
         getline(iss, actorFullName);
         actorFullName = actorFullName.substr(actorFullName.find_first_not_of(" \t"));
         
         // Split into first and last names if space exists
         size_t spacePos = actorFullName.find(' ');
         if (spacePos != string::npos) {
             actorFirstName = actorFullName.substr(0, spacePos);
             actorLastName = actorFullName.substr(spacePos + 1);
         } else {
             actorFirstName = actorFullName;
         }
         
         // Create the parameters for searching
         MovieParams params("", "", year, 0, nullptr);
         params.setReleaseMonth(month);
         params.addActor(actorFullName);
         
         // Create search key and find the movie
         shared_ptr<Movie> searchKey = inventory.classicFactory.createSearchKey(params);
         auto moviePtr = inventory.classicTree.retrieve(searchKey);
         
         if (moviePtr) {
             switch (commandType) {
                 case 'B': { // Borrow
                     bool success = inventory.borrowFactory.createAction(*(customerPtr), moviePtr);
                     if (!success) {
                         cout << "Failed to borrow: " << moviePtr->getTitle() << endl;
                     }
                     break;
                 }
                 case 'R': { // Return
                     bool success = inventory.returnFactory.createAction(*(customerPtr), moviePtr);
                     if (!success) {
                         cout << "Failed to return: " << moviePtr->getTitle() << endl;
                     }
                     break;
                 }
                 default:
                     cout << "Unknown action type: " << commandType << endl;
                     return;
             }
         }
      }
         break;
     }
      default:
         cout << "Unknown movie type: " << movieType << endl;
         return;
      }      
   }
}

/* processCommands()
   -- Processes a command string and performs the appropriate action
   -- cmd: command string to process
   -- inventory: InventoryStorage object containing the data
   -- calls the appropriate function based on the command type
*/

void processCommands(const string& cmd, InventoryStorage& inventory){
   if (cmd.empty()){
      return;
   }

   char cmdType = cmd[0];

   switch(cmdType){
      case 'I':{
         inventory.getInventory();
         break;
      }
      case 'H':{
         istringstream iss(cmd.substr(2));
         int customerID;
         if (iss >> customerID){
            auto customerPtr = inventory.customerSearchTable.find(customerID);
            if (customerPtr) {
               cout << "Customer " << customerID << " history:" << endl;
               (*customerPtr)->getHistory();
            } else {
               cout << "Error: Can't find customer in database" << endl;
            }
         } else {
            cout << "Error: Can't process customer history command" << endl;
         }
         break;
      }
      case 'B':{
         parseCommand(cmd, inventory);
         break;
      }
      case 'R':{
         parseCommand(cmd, inventory);
         break;
      }
      default:
         cout << "Unknown command type: " << cmdType << endl;
         break;
   }
}

int main(){

   InventoryStorage inventory;

   FileReader fileReader;

      // Read customer data
    ifstream customerFile("data4customers.txt");
    if (!customerFile) {
        cerr << "Error: Unable to open customer file" << endl;
        return 1;
    }
    fileReader.readCustomers(customerFile, inventory);
    customerFile.close();
    
    // Read movie data
    ifstream movieFile("data4movies.txt");
    if (!movieFile) {
        cerr << "Error: Unable to open movie file" << endl;
        return 1;
    }
    fileReader.readMovies(movieFile, inventory);
    movieFile.close();
    
    // Read command data
    ifstream commandFile("data4commands.txt");
    if (!commandFile) {
        cerr << "Error: Unable to open command file" << endl;
        return 1;
    }
    inventory.actionCommands = fileReader.readCommands(commandFile);
    commandFile.close();

   for (const auto& cmd : inventory.actionCommands){
      processCommands(cmd, inventory);
   }

   return 0;
}
