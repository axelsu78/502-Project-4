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
         
      }
      case 'D': {
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
            unique_ptr<Action> action;
            switch (commandType) {
               case 'B': { // Borrow
                  bool success = inventory.borrowFactory.createAction(*(customerPtr), moviePtr, amount);
                  if (!success) {
                     cout << "Failed to borrow: " << moviePtr->getTitle() << endl;
                  }
                  break;
              }
               case 'R': { // Return
                  bool success = inventory.returnFactory.createAction(*(customerPtr), moviePtr, amount);
                  if (!success){
                     cout << "Failed to borrow: " << moviePtr->getTitle() << endl;
                  }
                  break;
               }
            default:
               cout << "Unknown action type: " << commandType << endl;
               return;
            }
         }
         break;
      }
      case 'C': {
         
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