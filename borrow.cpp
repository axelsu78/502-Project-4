#include "borrow.h"

bool Borrow::execute() {
   // Check if any stock is available
   if (movie->getStock() <= 0) {
       std::cout << "Borrow failed: Out of Stock" << std::endl;
       return false;
   } else {
      movie->setStock(movie->getStock() - amount);
      return true;
   }
}


string Borrow::getActionType() const{
   return "Borrow";
}

string Borrow::getMovie(){
   return movie->getTitle();
}
