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

   bool ComedyMovie::operator<(const Movie &rhs) const{

      if (getTitle() != rhs.getTitle()){
         return (getTitle() < rhs.getTitle());
      }

      return (getReleaseYear() < rhs.getReleaseYear());

   }
    
   bool ComedyMovie::operator>(const Movie &rhs) const{

      if (getTitle() != rhs.getTitle()){
         return (getTitle() > rhs.getTitle());
      }

      return (getReleaseYear() > rhs.getReleaseYear());

   }       
    
   bool ComedyMovie::operator==(const Movie &rhs) const{

      if (getTitle() != rhs.getTitle()){
         return false;
      }

      return (getReleaseYear() == rhs.getReleaseYear());

   }      
    
   bool ComedyMovie::operator!=(const Movie &rhs) const{

      if (getTitle() == rhs.getTitle()){
         return false;
      }

      return (getReleaseYear() != rhs.getReleaseYear());

   } 

};