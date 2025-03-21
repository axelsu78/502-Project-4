/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   MediaType Class
*/

#pragma once

#include <string>

using string = std::string;

/* MediaType Interface
   -- Interface for Media Types
   -- getMediaType() returns the media type
*/

class MediaType {

public:

   virtual ~MediaType() = default; // virtual destructor

public:

   virtual string getMediaType() const = 0;

};