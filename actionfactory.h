#pragma once

#include "action.h"
#include "customer.h"
#include "movie.h"

class ActionFactory {

public:

   virtual bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie) = 0;

};