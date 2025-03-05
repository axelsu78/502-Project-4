#pragma once

#include <vector>
#include "movie.h"
#include "mediatype.h"
#include "dvd.h"


class ClassicMovie : public Movie {

   private:

   int releaseDate;
   std::vector<std::string> majorActors;

   public:
  
   // Constructor
   ClassicMovie(string title = "", 
      string director = "", 
      int releaseYear = 0, 
      int stock = 0,
      std::shared_ptr<MediaType> media = nullptr, 
      int date = 0,
      const std::vector<std::string>& actors = std::vector<std::string>()
   ) : Movie(title, director, releaseYear, stock, media), 
   releaseDate(date),
   majorActors(actors) {}

   int getReleaseDate() const;

   const std::vector<std::string> getMajorActors() const;

   void addActor(const std::string& actor);

   void mergeWith(const std::shared_ptr<Movie>& other) override;

   bool operator<(const Movie &rhs) const override;
   bool operator>(const Movie &rhs) const override;
   bool operator==(const Movie &rhs) const override;
   bool operator!=(const Movie &rhs) const override;

};