/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Borrow Action Class
*/

#pragma once
#include <memory>
#include "movie.h"
#include "action.h"

/* Borrow Class
   -- Inherits from Action
   -- Represents a Borrow Action
*/

class Borrow : public Action {

public:

   Borrow(std::shared_ptr<Customer> custPtr, std::shared_ptr<Movie> moviePtr)
   : Action(custPtr, moviePtr) {}

   bool execute() override;

   string getActionType() const override;

   string getMovie();
};