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

// file read customers
   // add strings to customerCommands

// add customers to customer hash table
   // no need to factory, just use string to create movie

// file read movies
   

// add movies to movieBST
   // call the appropriate moviefactory to create a movie
   // add that to the appropriate movieBST

// file read commands

void parseCommand(const string& cmd, InventoryStorage& inventory){
   stringstream ss(cmd);
   char commandType;
   int customerID, amount;
   char mediaType, movieType;

   ss >> commandType >> customerID >> mediaType >> movieType >> amount;

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
      cout << endl;
   }

   return 0;
}
