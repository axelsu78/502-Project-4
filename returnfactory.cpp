/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   ReturnFactory class
*/

#include "returnfactory.h"
#include "return.h"
#include "action.h"


bool ReturnFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie){

   std::shared_ptr<Action> returnObject = std::make_shared<Return>(customer, movie);

   if (returnObject->execute()){
      customer->addHistory(returnObject);
      return true;
   }
   return false;
}