#pragma once

#include "actionfactory.h"

class ReturnFactory : public ActionFactory {

public:

   bool createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie, int count) override;

};