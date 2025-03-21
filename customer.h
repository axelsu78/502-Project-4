/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   Customer Class
*/
#pragma once

#include <iostream>
#include <vector>
#include <memory>


class Action;

using string = std::string;

/* Customer Class:
   -- representation of a current customer in a userbase
   -- store history of all transaction objects in vector history 
*/

// blah blah blah

class Customer {

public:

   Customer(int customerID, string firstName, string lastName);

   ~Customer();

   /**
    * @brief prints all transactions conducted by customer
    * 
    */
   void getHistory() const;

   /**
    * @brief adds Action item (Borrow/Return) to vector of actions
    * 
    * @param action 
    * @return true 
    * @return false 
    */
   bool addHistory(std::shared_ptr<Action> action);

   void printName();

   std::vector<std::shared_ptr<Action>> getHistoryVector();


private:

   int customerID;

   string firstName;

   string lastName;

   std::vector<std::shared_ptr<Action>> history;

};
