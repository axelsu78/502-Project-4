#pragma once

#include "movie.h"
#include "mediatype.h"
#include "dvd.h"

class ComedyMovie : public Movie {

   // Constructor
   ComedyMovie(string title = "", 
      string director = "", 
      int releaseYear = 0, 
      int stock = 0,
      std::shared_ptr<MediaType> media = nullptr
   ) : Movie(title, director, releaseYear, stock, media) {}

};