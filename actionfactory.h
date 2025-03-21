/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Action Factory Class
*/

#pragma once

#include "action.h"
#include "customer.h"
#include "movie.h"

/* Action Factory Class
   -- creates actions
*/
class ActionFactory {

public:

   virtual bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie) = 0;

};