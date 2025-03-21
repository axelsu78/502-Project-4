/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   Return class
*/

#include "return.h"
#include "action.h"

bool Return::execute(){
   
   movie->setStock(movie->getStock() + 1);
   return true;
   
}

string Return::getActionType() const{
   return "Return";
}

string Return::getMovie(){
   return movie->getTitle();
}