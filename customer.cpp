#include "customer.h"

std::vector<std::unique_ptr<Action>> Customer::getHistory() const{

}

bool Customer::addHistory(std::shared_ptr<Action> action){
   history.push_back(action);
}