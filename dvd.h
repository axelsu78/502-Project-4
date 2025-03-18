/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   DVD Class
*/
#pragma once

#include "mediatype.h"

class DVD : public MediaType {

public:

   virtual ~DVD() = default;

   string getMediaType() const override{
      return "DVD";
   }
};