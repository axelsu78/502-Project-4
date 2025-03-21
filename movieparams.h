/* Axel Sundstrom and Cameron Chen
   CSS 502 - Assignment 4
   MovieParams class
*/

#pragma once

#include "movie.h"
#include "mediatype.h"
#include "vector"

using string = std::string;

/* MovieParams class
   -- creates a movie object with all necessary parameters
   -- used to create a movie object to be added to the inventory
   -- can be used to create a search key for a movie
   -- can be used to create a movie object to be added to a customer's history
*/
class MovieParams{

public:

MovieParams(
   const std::string& title,
   const std::string& director,
   int releaseYear,
   int stock,
   std::shared_ptr<MediaType> media
) : 
   title(title),
   director(director),
   releaseYear(releaseYear),
   stock(stock),
   media(media)
{}

   string title;
   string director;
   int releaseYear;
   int stock;
   std::shared_ptr<MediaType> media;
   int releaseMonth = 0;
   std::vector<string> actors;

   MovieParams& setReleaseMonth(int month);

   MovieParams& addActor(const string& actor);

   MovieParams& setActors(const std::vector<string>& actorList);

};