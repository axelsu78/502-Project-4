/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Customer Class
 */

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
   history.push_back(action);
   return true;
}

void Customer::printName(){
   cout << firstName << " " << lastName;
}

std::vector<std::shared_ptr<Action>> Customer::getHistoryVector(){
   return history;
}