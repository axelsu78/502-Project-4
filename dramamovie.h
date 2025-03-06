/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Drama Movie Header
*/
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

   bool operator<(const Movie &rhs) const override;
   bool operator>(const Movie &rhs) const override;
   bool operator==(const Movie &rhs) const override;
   bool operator!=(const Movie &rhs) const override;

   bool mergeWith(const shared_ptr<Movie>& other) override;

};