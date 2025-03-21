/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   Return class
*/
#pragma once
#include <memory>
#include "movie.h"
#include "action.h"

/* Return class
   -- creates a return action to return a movie into store inventory
*/
class Return : public Action {

public:

   Return(std::shared_ptr<Customer> custPtr, std::shared_ptr<Movie> moviePtr)
   : Action(custPtr, moviePtr) {}

   bool execute() override;

   string getActionType() const override;

   string getMovie();

};