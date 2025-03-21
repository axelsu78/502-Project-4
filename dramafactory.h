/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Drama Factory Class
*/

#pragma once

#include "moviefactory.h"
#include "movieparams.h"

 /* DramaFactory Class
    -- Inherits from MovieFactory
    -- Factory for creating Drama Movies
 */

class DramaFactory : public MovieFactory{

public:

   DramaFactory();

   std::shared_ptr<Movie> createMovie(const MovieParams& params) override;

   std::shared_ptr<Movie> createSearchKey(const MovieParams& params) override;

};