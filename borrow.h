//Borrow
#pragma once
#include <memory>
#include "inventory.h"
#include "movie.h"
#include "action.h"

class Borrow : public Action {

   bool execute() override;

};