/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Classic Factory Class
*/

#include "classicfactory.h"
#include "classicmovie.h"
#include "movieparams.h"
#include "comedyfactory.h"

ClassicFactory::ClassicFactory() {
}

std::shared_ptr<Movie> ClassicFactory::createMovie(const MovieParams& params) {
    return std::make_shared<ClassicMovie>(
        params.title,
        params.director,
        params.releaseYear,
        params.stock,
        params.media,
        params.releaseMonth,
        params.actors
    );
}

std::shared_ptr<Movie> ClassicFactory::createSearchKey(const MovieParams& params) {
    return std::make_shared<ClassicMovie>(
        "",                 // Title not needed for search
        "",                 // Director not needed for search
        params.releaseYear, // Year needed for search
        0,                  // Stock not needed for search
        nullptr,            // Media not needed for search
        params.releaseMonth, // Month needed for search
        params.actors       // Actors needed for search
    );
}