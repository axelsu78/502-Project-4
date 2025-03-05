//Action
#pragma once
#include <memory>
#include "inventory.h"
#include "movie.h"
#include "store.h"


class Action {

protected:

   std::shared_ptr<Store> store;

   
   std::shared_ptr<Movie> movie;
   

public:

   Action();

   virtual ~Action() = default;

   virtual bool execute() = 0;

};