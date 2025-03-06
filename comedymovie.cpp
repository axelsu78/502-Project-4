/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Comedy Movie Class
*/
#include "comedymovie.h"

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

   if (getTitle() != rhs.getTitle()){
      return true;
   }

   return (getReleaseYear() != rhs.getReleaseYear());

} 

bool ComedyMovie::mergeWith(const shared_ptr<Movie>& other){
   
   std::shared_ptr<ComedyMovie> otherComedy = std::dynamic_pointer_cast<ComedyMovie>(other);

   if (!otherComedy) {
      return false;
   }

   if (getTitle() != otherComedy->getTitle() ||
      getReleaseYear() != otherComedy->getReleaseYear() ||
      getMedia() != otherComedy->getMedia() || 
      getDirector() != otherComedy->getDirector()){
         return false;
   }

   setStock(getStock() + otherComedy->getStock());
   return true;

}