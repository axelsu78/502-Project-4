/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Drama Movie Class
*/
#include "dramamovie.h"

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

   if (getDirector() != rhs.getDirector()){
      return true;
   }

   return (getTitle() != rhs.getTitle());

} 