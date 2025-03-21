/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Movie Interface
*/
#include "movie.h" 

void Movie::printMovie() {
   std::cout << title << ", " << stock << std::endl;
}

std::string Movie::getTitle() const {
   return title;
}

std::string Movie::getDirector() const {
   return director;
}

int Movie::getStock() const {
   return stock;
}

void Movie::setStock(int newStock) {
   stock = newStock;
}

int Movie::getReleaseYear() const {
   return releaseYear;
}

string Movie::getMedia() const {
   return media->getMediaType();
}
