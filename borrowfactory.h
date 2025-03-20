#pragma once

#include "actionfactory.h"

class BorrowFactory : public ActionFactory {

public:   

   bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie, int count) override;

};