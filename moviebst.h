/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Movie Binary Search Tree
*/

#pragma once
#include <memory>
#include "movie.h"

template <typename Movie>

class MovieBST {

private:

struct Node{
   std::shared_ptr<Movie> movie;
   Node* leftChild;
   Node* rightChild;

   Node(std::shared_ptr<Movie> movie) : 
   movie(movie), 
   leftChild(nullptr), 
   rightChild(nullptr) 
   {}
};

Node* root;

/**
 * @brief inserts a Movie object into tree
 * 
 * @param root current subtree root
 * @param movie movie to be inserted
 * @return true insert was successful
 * @return false insert was not successful
 */
bool insertHelper(Node* root, std::shared_ptr<Movie> movie);

/**
 * @brief takes a movie of the sorted order parameters and returns movie containing all parameters if it exists
 * 
 * @param root 
 * @param tempSearchKey Movie containing only sorted parameters
 * @return std::shared_ptr<Movie> Movie to be found
 */
std::shared_ptr<Movie> retrieveHelper(Node* root, std::shared_ptr<Movie> tempSearchKey);

/**
 * @brief prints all movies in a tree
 * 
 * @param root current subtree node
 */
void displayHelper(Node* root);

/**
 * @brief deletes entire tree
 */
void clear(Node* root);

public:

// constructor
MovieBST();

// destructor
~MovieBST();

/**
 * @brief public function to insert movie into tree
 * 
 * @param movie movie to be inserted
 */
bool insert(std::shared_ptr<Movie> movie);

/**
 * @brief public function to find corresponding movie based on a movie object with only its sorted types
 * 
 * @param tempSearchKey movie with only corresponding sorting types
 * @return std::shared_ptr<Movie> movie to be searched for
 */
std::shared_ptr<Movie> retrieve(std::shared_ptr<Movie> tempSearchKey);

/**
 * @brief displays all movies in given subtree
 * 
 */
void display() const;

};

#include "moviebst.hpp"