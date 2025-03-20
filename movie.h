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

    virtual ~Movie() = default;                           
    
    virtual bool operator<(const Movie &rhs) const = 0;       
    
    virtual bool operator>(const Movie &rhs) const = 0;       
    
    virtual bool operator==(const Movie &rhs) const = 0;      
    
    virtual bool operator!=(const Movie &rhs) const = 0;      
    
    virtual std::string getTitle() const;
    
    virtual std::string getDirector() const;
    
    virtual int getStock() const;              
    
    virtual void setStock(int newStock);       
    
    virtual int getReleaseYear() const;
    
    virtual string getMedia() const;

    /**
     * @brief if two movies share the same values when adding to a data structure, they increase each other's stock
     * (and in classic's case add the additional lead actor) instead of creating two separate objects
     * 
     * @param other movie to be compared to
     * @return true movies were merged
     * @return false movies weren't merged
     */
    virtual bool mergeWith(const shared_ptr<Movie>& other) = 0;

    virtual void printMovie();


private:
    
    std::string title;                                    // title of movie
   
    std::string director;                                 // director of movie
    
    int releaseYear;                                      // movie release year 
    
    int stock;                                            // stock of movie

    std::shared_ptr<MediaType> media;                     // media type of movie     

};

#endif