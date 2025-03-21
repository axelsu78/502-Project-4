/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   MovieParams class
*/

#include "movieparams.h"

MovieParams& MovieParams::setReleaseMonth(int month) {
   this->releaseMonth = month;
   return *this;
}

MovieParams& MovieParams::addActor(const std::string& actor) {
   this->actors.push_back(actor);
   return *this;
}

MovieParams& MovieParams::setActors(const std::vector<std::string>& actorList) {
   this->actors = actorList;
   return *this;
}