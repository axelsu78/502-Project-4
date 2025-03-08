/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Movie Interface
*/
#include "movie.h" 

// Provide minimal implementations for comparison operators
bool Movie::operator<(const Movie& /*rhs*/) const {
   return false;
}

bool Movie::operator>(const Movie& /*rhs*/) const {
   return false;
}

bool Movie::operator==(const Movie& /*rhs*/) const {
   return false;
}

bool Movie::operator!=(const Movie& /*rhs*/) const {
   return false;
}

bool Movie::mergeWith(const std::shared_ptr<Movie>& /*other*/) {
   return false;
}

void Movie::printMovie() {
   std::cout << title << ", " << stock << std::endl;
}

// Implement getter methods
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
