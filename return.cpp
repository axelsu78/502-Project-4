/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   Return class
*/

#include "return.h"
#include "action.h"

bool Return::execute() {
   // Check if customer exists
   if (!customer) {
       return false;
   }

   // Flag to track if a matching borrow action exists
   bool hasBorrowAction = false;

   // Get customer's history
   std::vector<std::shared_ptr<Action>> customerHistory = customer->getHistoryVector();

   // Iterate through customer's history to find a matching borrow action
   for (const auto& action : customerHistory) {

       // Check if there's a matching borrow action for this movie
       if (action->getActionType() == "Borrow" && action->getMovie() == movie->getTitle()) {
           hasBorrowAction = true;
           break;
       }
   }

   // Only return the movie if a matching borrow action exists
   if (hasBorrowAction) {
       movie->setStock(movie->getStock() + 1);
       return true;
   } else {
       return false;
   }
}

string Return::getActionType() const{
   return "Return";
}

string Return::getMovie(){
   return movie->getTitle();
}