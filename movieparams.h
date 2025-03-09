#pragma once

#include "movie.h"
#include "mediatype.h"
#include "vector"

using string = std::string;

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

~MovieParams();

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