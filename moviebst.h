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

// insert
bool insertHelper(Node* root, std::shared_ptr<Movie> movie);

// retrieve
std::shared_ptr<Movie> retrieveHelper(Node* root, std::shared_ptr<Movie> tempSearchKey);

// display
void displayHelper(Node* root);

// clear
void clear(Node* root);

public:

// constructor
MovieBST();

// destructor
~MovieBST();

// insert
bool insert(std::shared_ptr<Movie> movie);

// retrieve
std::shared_ptr<Movie> retrieve(std::shared_ptr<Movie> tempSearchKey);

// display
void display();

};

#include "moviebst.hpp"