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

   std::vector<std::unique_ptr<Action>> getHistory() const;

private:

   int customerID;

   std::vector<Action> history;


};
