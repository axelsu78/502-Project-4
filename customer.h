/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   Customer Class
*/
#pragma once

#include <iostream>
#include <vector>
#include "action.h"

using string = std::string;

/* Customer Class:
   -- representation of a current customer in a userbase
   -- store history of all transaction objects in vector history 
*/


class Customer {

public:

   Customer(int customerID);

   ~Customer();

   void getHistory() const;

   bool addHistory(std::shared_ptr<Action> action);

   string getName();

private:

   int customerID;

   string firstName;

   string lastName;

   std::vector<std::shared_ptr<Action>> history;


};
