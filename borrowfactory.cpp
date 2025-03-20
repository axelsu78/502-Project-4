#include "borrowfactory.h"
#include "borrow.h"

bool BorrowFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie, int count){
   
   std::shared_ptr<Action> borrow = std::make_shared<Borrow>(customer, movie, count);

   if (borrow->execute()){
      customer->addHistory(borrow);
      return true;
   }

   return false;

}