#include "borrow.h"

bool Borrow::execute() {
   // Check if any stock is available
   if (movie->getStock() <= 0) {
       std::cout << "Borrow failed: Out of Stock" << std::endl;
       return false;
   }
   if (movie->getStock() < amount) {
      std::cout << "Warning: Only " << movie->getStock() << " copies available. Borrowing all available copies." << std::endl;
      amount = movie->getStock();
      movie->setStock(0);
      return true;
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

int Borrow::getCount(){
   return amount;
}
