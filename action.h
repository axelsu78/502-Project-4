//Action
#pragma once
#include <memory>
#include "movie.h"
#include "store.h"
#include "customer.h"

using string = std::string;

class Action {

protected:
   
   std::shared_ptr<Customer> customer;
   std::shared_ptr<Movie> movie;

   Action(std::shared_ptr<Customer> custID, std::shared_ptr<Movie> moviePtr) 
      : customer(custID), movie(moviePtr) {}
   
public:

   virtual ~Action() = default;

   virtual bool execute() = 0;

   virtual string getActionType() const = 0;

};