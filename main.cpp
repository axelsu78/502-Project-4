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

void parseCommand(const string& cmd){
   stringstream ss(cmd);
   char commandType;
   int customerID;
   char mediaType, movieType;

   ss >> commandType >> customerID >> mediaType >> movieType;

   string movieData;
   getline(ss, movieData);
   
   // for each type, use create search key to find the movie in the appropriate BST
   // borrow and return have different formats
   // for each different movie type - comedy titled year, drama director title year, classic month year actor title

   // if the movie is found, call the appropriate action factory to create the action
   // call the execute method on the action
   // if the movie is not found, print an error message
   

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
      processCommands(cmd, inventory);
      cout << endl;
   }

   return 0;
}