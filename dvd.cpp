/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   DVD Class
*/

#include "dvd.h"
#include <iostream>
using namespace std;

DVD::~DVD() = default;

string DVD::getMediaType() const {
    return "DVD";
}