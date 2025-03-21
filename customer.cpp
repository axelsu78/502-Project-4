#include "customer.h"
#include "action.h"

using namespace std;

Customer::Customer(int customerID, string firstName, string lastName) {
   this->customerID = customerID;
   this->firstName = firstName;
   this->lastName = lastName;
}

Customer::~Customer() {
}

void Customer::getHistory() const{
   
   if (history.empty()){
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
   std::cout << "DEBUG: Adding action to history. " 
             << "Action type: " << action->getActionType() 
             << ", Movie: " << action->getMovie() 
             << ", History size before: " << history.size() 
             << std::endl;
   
   history.push_back(action);
   
   std::cout << "DEBUG: History size after: " << history.size() << std::endl;
   return true;
}

void Customer::printName(){
   cout << firstName << " " << lastName;
}