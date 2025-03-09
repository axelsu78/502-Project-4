//Borrow
#pragma once
#include <memory>
#include "movie.h"
#include "action.h"

class Borrow : public Action {

public:

   Borrow(std::shared_ptr<Customer> custPtr, std::shared_ptr<Movie> moviePtr)
   : Action(custPtr, moviePtr) {}

   bool execute() override;

   string getActionType() const override;

};