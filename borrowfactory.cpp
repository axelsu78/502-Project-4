#include "borrowfactory.h"
#include "borrow.h"
#include "action.h"

// bool BorrowFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie){
   
//    std::shared_ptr<Action> borrow = std::make_shared<Borrow>(customer, movie);

//    if (borrow->execute()){
//       customer->addHistory(borrow);
//       return true;
//    }

//    return false;

// }

bool BorrowFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie){
   std::cout << "DEBUG Borrow: Creating action for movie: " << movie->getTitle() 
             << ", Customer: " << (customer ? "Valid" : "Invalid") 
             << std::endl;
   
   std::shared_ptr<Action> borrow = std::make_shared<Borrow>(customer, movie);

   std::cout << "DEBUG Borrow: Executing action" << std::endl;
   if (borrow->execute()){
      std::cout << "DEBUG Borrow: Action executed successfully" << std::endl;
      customer->addHistory(borrow);
      return true;
   }

   std::cout << "DEBUG Borrow: Action execution failed" << std::endl;
   return false;
}