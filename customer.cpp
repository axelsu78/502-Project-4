#include "customer.h"

std::vector<std::unique_ptr<Action>> Customer::getHistory() const{
   for (const auto action : history){
      if (action->getActionType == "Borrow"){
         cout << "Borrowed"
      }
   }
}

bool Customer::addHistory(std::shared_ptr<Action> action){
   history.push_back(action);
}