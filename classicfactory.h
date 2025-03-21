/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Classic Factory Class
*/
#pragma once

#include "moviefactory.h"
#include "movieparams.h"
#include "classicmovie.h"

/* ClassicFactory Class
   -- Inherits from MovieFactory
   -- Factory for creating Classic Movies
*/

class ClassicFactory : public MovieFactory{

public:

   ClassicFactory();

   std::shared_ptr<Movie> createMovie(const MovieParams& params) override;

   std::shared_ptr<Movie> createSearchKey(const MovieParams& params) override;

};