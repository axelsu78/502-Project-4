#pragma once

#include "movie.h"
#include "mediatype.h"
#include "movieparams.h"

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