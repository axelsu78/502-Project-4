/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   Movie Binary Search Tree
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