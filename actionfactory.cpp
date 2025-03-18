/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Action Factory Class
*/

#include "actionfactory.h"
#include "action.h"
#include "customer.h"
#include "movie.h"
#include <iostream>
using namespace std;

bool ActionFactory::createAction(std::shared_ptr<Customer> customer, std::shared_ptr<Movie> movie) {
    cout << "ActionFactory::createAction" << endl;
    return false;
};

