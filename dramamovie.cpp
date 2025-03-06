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

bool DramaMovie::mergeWith(const shared_ptr<Movie>& other){
   
   std::shared_ptr<DramaMovie> otherDrama = std::dynamic_pointer_cast<DramaMovie>(other);

   if (!otherDrama) {
      return false;
   }

   if (getTitle() != otherDrama->getTitle() ||
      getReleaseYear() != otherDrama->getReleaseYear() ||
      getMedia() != otherDrama->getMedia() || 
      getDirector() != otherDrama->getDirector()){
         return false;
   }

   setStock(getStock() + otherDrama->getStock());
   return true;

}