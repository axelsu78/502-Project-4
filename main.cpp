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
   int customerID;
   char mediaType, movieType;

   ss >> commandType >> customerID >> mediaType >> movieType;

   string movieData;
   getline(ss, movieData);
   
   // for each movie type, create search key to find the movie in the appropriate BST
   string searchKey;
   switch (movieType) {
      case 'F': { 
         string title;
         int year;
         stringstream movieStream(movieData);
         getline(movieStream, title, ',');
         movieStream >> year;
         searchKey = title + to_string(year);
         break;
      }

      case 'D': { 
         string director, title;
         stringstream movieStream(movieData);
         getline(movieStream, director, ',');
         getline(movieStream, title, ',');
         searchKey = director + title;
         break;
      }

      case 'C': { 
         int month, year;
         string actor;
         stringstream movieStream(movieData);
         movieStream >> month >> year;
         getline(movieStream, actor);
         searchKey = to_string(month) + to_string(year) + actor;
         break;
      }

      default:
         cout << "Unknown movie type: " << movieType << endl;
         return;
   }
   // Find the movie in inventory
   auto moviePtr = inventory.movieBST.find(searchKey);
   // Create appropriate action using action
   if (moviePtr) {
      unique_ptr<Action> action;
      switch (commandType) {
         case 'B': { // Borrow
            BorrowFactory borrowFactory;
            action = borrowFactory.createAction();
            break;
         }
         case 'R': { // Return
            ReturnFactory returnFactory;
            action = returnFactory.createAction();
            break;
         }
         default:
            cout << "Unknown action type: " << commandType << endl;
            return;
      }
      // Call the execute method on the action
      if (action) {
         action->execute();
      } else {
         cout << "Error: Action creation failed" << endl;
      }
   // movie not found in inventory
   } else {
      cout << "Error: Movie not found in inventory" << endl;
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

         break;
      }
      case 'R':{

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

   for (const auto& cmd : inventory.actionCommands){
      parseCommand(cmd, inventory);
      cout << endl;
   }

   return 0;
}