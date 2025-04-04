/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Borrow Action Class 
*/

#include "borrow.h"
#include "action.h"

bool Borrow::execute() {
   // Check if any stock is available
   if (movie->getStock() <= 0) {
       std::cout << "Borrow failed: Out of Stock" << std::endl;
       return false;
   } else {
      movie->setStock(movie->getStock() - 1);
      return true;
   }
}


string Borrow::getActionType() const{
   return "Borrow";
}

string Borrow::getMovie(){
   return movie->getTitle();
}
