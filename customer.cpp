#include "customer.h"
#include "action.h"

void Customer::getHistory() const{
   
   if (history.size() == 0){
      cout << "History for Customer " << firstName << " " << lastName << " is empty" << endl;
   }
   
   for (const auto action : history){
      if (action->getActionType() == "Borrow"){
         cout << "Borrowed " << action->getMovie() << endl;
      } else if (action->getActionType() == "Return"){
         cout << "Returned " << action->getMovie() << endl;
      } else {
         cout << "Error returning action type" << endl;
      }
   }
}

bool Customer::addHistory(std::shared_ptr<Action> action){
   history.push_back(action);
}

string Customer::printName(){
   cout << firstName << " " << lastName;
}