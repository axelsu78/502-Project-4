#include "comedyfactory.h"
#include "comedymovie.h"

std::shared_ptr<Movie> createMovie(const MovieParams& params){
   return std::make_shared<ComedyMovie>(
       params.title, 
       params.director, 
       params.releaseYear, 
       params.stock, 
       params.media
   );
}

std::shared_ptr<Movie> createSearchKey(const MovieParams& params){
   return std::make_shared<ComedyMovie>(
      params.title, 
      "", 
      params.releaseYear, 
      0, 
      nullptr
   );
}