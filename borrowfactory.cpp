/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Borrow Factory Class
*/

#include "borrowfactory.h"
#include "borrow.h"
#include "action.h"

bool BorrowFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie){
   std::shared_ptr<Action> borrow = std::make_shared<Borrow>(customer, movie);

   if (borrow->execute()){
      customer->addHistory(borrow);
      return true;
   }
   return false;
}