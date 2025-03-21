/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   DVD Class
*/
#pragma once

#include "mediatype.h"

/* DVD Class
   -- Inherits from MediaType
   -- Represents a DVD
*/

class DVD : public MediaType {

public:

   virtual ~DVD() = default;

   string getMediaType() const override{
      return "DVD";
   }
};