#include "return.h"
#include "action.h"

bool Return::execute(){
   
   movie->setStock(movie->getStock() + amount);
   return true;
   
}

string Return::getActionType() const{
   return "Return";
}

string Return::getMovie(){
   return movie->getTitle();
}