//Borrow
#pragma once
#include <memory>
#include "movie.h"
#include "action.h"

class Return : public Action {

public:

   Return(std::shared_ptr<Customer> custPtr, std::shared_ptr<Movie> moviePtr, int count)
   : Action(custPtr, moviePtr, count) {}

   bool execute() override;

   string getActionType() const override;

};