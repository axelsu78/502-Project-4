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

      if (getDirector() != rhs.getDirector()){
         return (getDirector() < rhs.getDirector());
      }

      return (getTitle() < rhs.getTitle());

   }
    
   bool DramaMovie::operator>(const Movie &rhs) const{

      if (getDirector() != rhs.getDirector()){
         return (getDirector() > rhs.getDirector());
      }

      return (getTitle() > rhs.getTitle());

   }       
    
   bool DramaMovie::operator==(const Movie &rhs) const{

      if (getDirector() != rhs.getDirector()){
         return false;
      }

      return (getTitle() == rhs.getTitle());

   }      
    
   bool DramaMovie::operator!=(const Movie &rhs) const{

      if (getDirector() == rhs.getDirector()){
         return false;
      }

      return (getTitle() != rhs.getTitle());

   } 

};