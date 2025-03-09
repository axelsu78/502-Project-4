#include "dramafactory.h"
#include "dramamovie.h"

std::shared_ptr<Movie> DramaFactory::createMovie(const MovieParams& params){
   return std::make_shared<DramaMovie>(
       params.title, 
       params.director, 
       params.releaseYear, 
       params.stock, 
       params.media
   );
}

std::shared_ptr<Movie> DramaFactory::createSearchKey(const MovieParams& params){
   return std::make_shared<DramaMovie>(
      params.title, 
      params.director, 
      0, 
      0, 
      nullptr
   );
}