#include "return.h"

bool Return::execute(){
   
   movie->setStock(movie->getStock() + 1);
   return true;
   
}

string Return::getActionType() const{
   return "Return";
}