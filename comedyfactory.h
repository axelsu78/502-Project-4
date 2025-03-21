/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Comedy Factory Class
*/

#pragma once

#include "moviefactory.h"
#include "movieparams.h"

/* ComedyFactory Class
   -- Inherits from MovieFactory
   -- Factory for creating Comedy Movies
*/

class ComedyFactory : public MovieFactory{

public:

   ComedyFactory();

   std::shared_ptr<Movie> createMovie(const MovieParams& params) override;

   std::shared_ptr<Movie> createSearchKey(const MovieParams& params) override;

};