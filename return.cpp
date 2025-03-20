#include "return.h"

bool Return::execute(){
   
   movie->setStock(movie->getStock() + amount);
   return true;
   
}

string Return::getActionType() const{
   return "Return";
}