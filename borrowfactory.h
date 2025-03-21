/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignnment 4
   Borrow Factory Class
*/
#pragma once

#include "actionfactory.h"
#include "action.h"

/* BorrowFactory Class
   -- Inherits from ActionFactory
   -- Factory for creating Borrow Actions
*/

class BorrowFactory : public ActionFactory {

public:   

   bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie) override;

};