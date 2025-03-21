/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   MovieFactory class
*/

#pragma once

#include "movie.h"
#include "movieparams.h"
#include "mediatype.h"
#include "dvd.h"

using string = std::string;

/* MovieFactory class
   -- creates a movie object with all necessary parameters
   -- used to create a movie object to be added to the inventory
   -- can be used to create a search key for a movie
   -- can be used to create a movie object to be added to a customer's history
*/

class MovieFactory {

   public:

   virtual ~MovieFactory() = default;

   virtual std::shared_ptr<Movie> createMovie(const MovieParams& params) = 0;

   virtual std::shared_ptr<Movie> createSearchKey(const MovieParams& params) = 0;

   protected:

   std::shared_ptr<MediaType> createDVD() {   
      return std::make_shared<DVD>();
   }

};