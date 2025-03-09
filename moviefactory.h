#pragma once

#include "movie.h"
#include "movieparams.h"

using string = std::string;

class MovieFactory {

   public:

   virtual ~MovieFactory() = default;

   virtual std::shared_ptr<Movie> createMovie(const MovieParams& params) = 0;

   virtual std::shared_ptr<Movie> createSearchKey(const MovieParams& params) = 0;

   protected:

};