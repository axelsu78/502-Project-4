/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Action Class
*/

#include "action.h"
#include "customer.h"
#include "movie.h"
#include "store.h"
#include <iostream>
using namespace std;

Action::~Action() = default;

bool Action::execute() {
    cout << "Action::execute" << endl;
    return false;
}

string Action::getActionType() const {
    cout << "Action::getActionType" << endl;
    return "";
}

