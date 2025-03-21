#include "returnfactory.h"
#include "return.h"
#include "action.h"

// bool ReturnFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie){
   
//    std::shared_ptr<Action> returnObject = std::make_shared<Return>(customer, movie);

//    if (returnObject->execute()){
//       customer->addHistory(returnObject);
//       return true;
//    }

//    return false;

// }

bool ReturnFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie){
   
   std::cout << "DEBUG Return: Creating action for movie: " << movie->getTitle() 
             << ", Customer: " << (customer ? "Valid" : "Invalid") 
             << std::endl;
   
   std::shared_ptr<Action> returnObject = std::make_shared<Return>(customer, movie);

   std::cout << "DEBUG Return: Executing action" << std::endl;
   if (returnObject->execute()){
      std::cout << "DEBUG Return: Action executed successfully" << std::endl;
      customer->addHistory(returnObject);
      return true;
   }

   std::cout << "DEBUG Return: Action execution failed" << std::endl;
   return false;
}