
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