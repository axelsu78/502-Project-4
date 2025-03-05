/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   MediaType Class
*/

#pragma once

#include <string>

using string = std::string;

class MediaType {

   virtual ~MediaType() = default; // virtual destructor

   virtual string getMediaType() const = 0;

};