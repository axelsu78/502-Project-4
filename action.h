/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Action Class
*/

#pragma once
#include <memory>


class Movie;
class Customer;

using string = std::string;

/* Action Class
   -- Abstract class for all actions
   -- execute() completes the action
   -- getActionType() returns the type of action
   -- getMovie() returns the movie associated with the action
*/

class Action {

protected:

// push works?
   
   std::shared_ptr<Customer> customer;
   std::shared_ptr<Movie> movie;
   int amount;

   Action(std::shared_ptr<Customer> custID, std::shared_ptr<Movie> moviePtr) 
      : customer(custID), movie(moviePtr) {}
   
public:

   virtual ~Action() = default;

   /**
    * @brief completes associated action associated with subclass
    */
   virtual bool execute() = 0;

   virtual string getActionType() const = 0;

   virtual string getMovie() = 0;

};