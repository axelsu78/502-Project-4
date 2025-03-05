/* Axel Sundstrom, Cameron Chen, Kalina Gavrilova, Vidushi Singla
   CSS 502 Assignment 4
   Movie Interface
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <memory>
#include "mediatype.h"
#include "dvd.h"
using namespace std;

/* Movie Interface
   -- abstract class for movie objects
   -- stores movie title, director, media type, stock, and release year
   -- provides methods to access and modify movie attributes
   -- provides methods to compare movies
*/
class Movie {
public:
    
    Movie(string title = "", 
        string director = "", 
        int releaseYear = 0, 
        int stock = 0,
        std::shared_ptr<MediaType> media = nullptr
    ) : title(title), 
        director(director), 
        releaseYear(releaseYear), 
        stock(stock), 
        media(media) {}

    virtual ~Movie() = default;                           // destructor
    
    virtual bool operator<(const Movie &rhs) const;       // overloaded less than operator
    
    virtual bool operator>(const Movie &rhs) const;       // overloaded greater than operator
    
    virtual bool operator==(const Movie &rhs) const;      // overloaded equality operator
    
    virtual bool operator!=(const Movie &rhs) const;      // overloaded inequality operator
    
    virtual std::string getTitle() const{
        return title;
    }                 
    
    virtual std::string getDirector() const{
        return director;
    }              
    
    virtual int getStock() const{
        return stock;
    }                         
    
    virtual void setStock(int newStock){
        stock += newStock;
    }                    
    
    virtual int getReleaseYear() const{
        return releaseYear;
    }                   
private:
    std::string title;                                    // title of movie
    std::string director;                                 // director of movie
    std::shared_ptr<MediaType> media;                     // media type of movie
    int stock;                                            // stock of movie
    int releaseYear;                                      // movie release year  
};

#endif