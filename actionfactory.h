#pragma once

#include "action.h"
#include "customer.h"
#include "movie.h"

/* Action Factory Class
   -- creates actions
*/
class ActionFactory {

public:

   virtual bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie, int count) = 0;

};