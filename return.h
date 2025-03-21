//Borrow
#pragma once
#include <memory>
#include <vector>
#include "movie.h"
#include "action.h"
#include "customer.h"

class Return : public Action {

public:

   Return(std::shared_ptr<Customer> custPtr, std::shared_ptr<Movie> moviePtr)
   : Action(custPtr, moviePtr) {}

   bool execute() override;

   string getActionType() const override;

   string getMovie();

};