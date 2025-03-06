/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Classic Movie Class
*/
#include "classicmovie.h"
#include <algorithm>

bool ClassicMovie::operator<(const Movie &rhs) const{
   
   /**
    * Typecasting movie input to classic movie so it can access
    * the getReleaseDate and majorActor functions
    */
   const ClassicMovie& rhsClassic = static_cast<const ClassicMovie&>(rhs);
   
   if (getReleaseYear() != rhsClassic.getReleaseYear()){
      return (getReleaseYear() < rhsClassic.getReleaseYear());
   }

   if (getReleaseDate() != rhsClassic.getReleaseDate()){
      return (getReleaseDate() < rhsClassic.getReleaseDate());
   }

   if (!majorActors.empty() && !rhsClassic.majorActors.empty()) {
      if (majorActors.front() != rhsClassic.majorActors.front()) {
         return majorActors.front() < rhsClassic.majorActors.front();
      }
   }

   return false;

}
 
bool ClassicMovie::operator>(const Movie &rhs) const{


   const ClassicMovie& rhsClassic = static_cast<const ClassicMovie&>(rhs);
   
   if (getReleaseYear() != rhsClassic.getReleaseYear()){
      return (getReleaseYear() > rhsClassic.getReleaseYear());
   }

   if (getReleaseDate() != rhsClassic.getReleaseDate()){
      return (getReleaseDate() > rhsClassic.getReleaseDate());
   }

   if (!majorActors.empty() && !rhsClassic.majorActors.empty()) {
      if (majorActors.back() != rhsClassic.majorActors.back()) {
         return majorActors.back() > rhsClassic.majorActors.back();
      }
   }

   return false;

}       
 
bool ClassicMovie::operator==(const Movie &rhs) const{

   
   const ClassicMovie& rhsClassic = static_cast<const ClassicMovie&>(rhs);
   
   if (getReleaseYear() != rhsClassic.getReleaseYear()){
      return false;
   }

   if (getReleaseDate() != rhsClassic.getReleaseDate()){
      return false;
   }

   if (!majorActors.empty() && !rhsClassic.majorActors.empty()) {
      for (const auto& actor : getMajorActors()){
         if (std::find(rhsClassic.majorActors.begin(), 
            rhsClassic.majorActors.end(), 
            actor) != rhsClassic.majorActors.end()) {
            return true;
        }
      }
   }

   return false;

}      
 
bool ClassicMovie::operator!=(const Movie &rhs) const{

   const ClassicMovie& rhsClassic = static_cast<const ClassicMovie&>(rhs);
   
   if (getReleaseYear() != rhsClassic.getReleaseYear()){
      return true;
   }

   if (getReleaseDate() != rhsClassic.getReleaseDate()){
      return true;
   }

   if (!majorActors.empty() && !rhsClassic.majorActors.empty()) {
      for (const auto& actor : getMajorActors()){
         if (std::find(rhsClassic.majorActors.begin(), 
            rhsClassic.majorActors.end(), 
            actor) != rhsClassic.majorActors.end()) {
            return false;
        }
      }
   }

   return true;
   
}

int ClassicMovie::getReleaseDate() const{
   return releaseDate;
}

const std::vector<std::string> ClassicMovie::getMajorActors() const{
   return majorActors;
}

void ClassicMovie::addActor(const std::string& actor){
   
   // creates iterator at first element that is not less than inserted value
   auto insertPos = std::lower_bound(majorActors.begin(), majorActors.end(), actor);
    
   // if iterator is at end of list (all values are less than) or is not a duplicate of entry
   if (insertPos == majorActors.end() || *insertPos != actor) {
      majorActors.insert(insertPos, actor);
   }

}

void ClassicMovie::mergeWith(const shared_ptr<Movie>& other){

   Movie::mergeWith(other);

}