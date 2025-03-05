#pragma once

#include "movie.h"
#include "mediatype.h"
#include "dvd.h"


class DramaMovie : public Movie {

   // Constructor
   DramaMovie(string title = "", 
      string director = "", 
      int releaseYear = 0, 
      int stock = 0,
      std::shared_ptr<MediaType> media = nullptr
   ) : Movie(title, director, releaseYear, stock, media) {}

   bool DramaMovie::operator<(const Movie &rhs) const{

      if (getTitle() != rhs.getTitle()){
         return (getTitle() < rhs.getTitle());
      }

      return (getReleaseYear() < rhs.getReleaseYear());

   }
    
   bool DramaMovie::operator>(const Movie &rhs) const{

      if (getTitle() != rhs.getTitle()){
         return (getTitle() > rhs.getTitle());
      }

      return (getReleaseYear() > rhs.getReleaseYear());

   }       
    
   bool DramaMovie::operator==(const Movie &rhs) const{

      if (getTitle() != rhs.getTitle()){
         return false;
      }

      return (getReleaseYear() == rhs.getReleaseYear());

   }      
    
   bool DramaMovie::operator!=(const Movie &rhs) const{

      if (getTitle() == rhs.getTitle()){
         return false;
      }

      return (getReleaseYear() != rhs.getReleaseYear());

   } 

};