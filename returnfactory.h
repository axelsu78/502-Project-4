/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   ReturnFactory class
*/
#pragma once

#include "actionfactory.h"
#include "action.h"

/* ReturnFactory class
   -- creates a return action to return a movie into store inventory
*/

class ReturnFactory : public ActionFactory {

public:

   bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie) override;

};