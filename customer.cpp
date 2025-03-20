#include "customer.h"

void Customer::getHistory() const{
   
   if (history.size() == 0){
      cout << "History for Customer " << firstName << " " << lastName << " is empty" << endl;
   }
   
   for (const auto action : history){
      if (action->getActionType() == "Borrow"){
         cout << "Borrowed " << action->getCount() << " copies of " << action->getMovie() << endl;
      } else if (action->getActionType() == "Return"){
         cout << "Returned " << action->getCount() << " copies of " << action->getMovie() << endl;
      } else {
         cout << "Error returning action type" << endl;
      }
   }
}

bool Customer::addHistory(std::shared_ptr<Action> action){
   history.push_back(action);
}

string Customer::getName(){
   cout << firstName << " " << lastName;
}