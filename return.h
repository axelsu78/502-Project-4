//Borrow
#pragma once
#include <memory>
#include "movie.h"
#include "action.h"

class Return : public Action {

public:

   bool execute() override;

   string getActionType() const override;

};