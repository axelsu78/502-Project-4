/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   Return class
*/

#include "return.h"
#include "action.h"

// bool Return::execute(){
   
   

//    movie->setStock(movie->getStock() + 1);
//    return true;
   
// }

bool Return::execute() {
   std::cout << "DEBUG Return: Attempting to return movie: " << movie->getTitle() 
             << " for customer: " << (customer ? "Valid" : "Invalid") 
             << std::endl;

   // Check if customer exists
   if (!customer) {
       std::cout << "DEBUG Return: Invalid customer" << std::endl;
       return false;
   }

   // Flag to track if a matching borrow action exists
   bool hasBorrowAction = false;

   // Get customer's history
   std::vector<std::shared_ptr<Action>> customerHistory = customer->getHistoryVector();

   // Iterate through customer's history to find a matching borrow action
   for (const auto& action : customerHistory) {
       std::cout << "DEBUG Return: Checking previous action - Type: " << action->getActionType() 
                 << ", Movie: " << action->getMovie() 
                 << std::endl;

       // Check if there's a matching borrow action for this movie
       if (action->getActionType() == "Borrow" && action->getMovie() == movie->getTitle()) {
           hasBorrowAction = true;
           break;
       }
   }

   // Only return the movie if a matching borrow action exists
   if (hasBorrowAction) {
       std::cout << "DEBUG Return: Matching borrow action found. Returning movie." << std::endl;
       movie->setStock(movie->getStock() + 1);
       return true;
   } else {
       std::cout << "DEBUG Return: No matching borrow action found. Return failed." << std::endl;
       return false;
   }
}

string Return::getActionType() const{
   return "Return";
}

string Return::getMovie(){
   return movie->getTitle();
}