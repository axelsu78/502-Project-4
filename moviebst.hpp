/* Axel Sundstrom, Cameron Chen
   CSS 502 Assignment 4
   Movie Binary Search Tree
*/

#include "moviebst.h"


template <typename Movie>
MovieBST<Movie>::MovieBST() : root(nullptr){}



template <typename Movie>
MovieBST<Movie>::~MovieBST(){
   clear(root);
   root = nullptr;
}


template <typename Movie>
bool MovieBST<Movie>::insertHelper(Node* root, std::shared_ptr<Movie> movie){
   // if the pointer is nullptr then do basecase and end recursion
   if (root == nullptr){
      return false;
   }

   // check left node
   if (*movie < *(root->movie)){
      if (root->leftChild == nullptr){
         root->leftChild = new Node(movie);
         return true;
      } else {
         insertHelper(root->leftChild, movie);
      }
   }

   // check right node
   if (*movie > *(root->movie)){
      if (root->rightChild == nullptr){
         root->rightChild = new Node(movie);
         return true;
      } else {
         insertHelper(root->rightChild, movie);
      }
   }

   // check if equal and handle case
   if (*movie == *(root->movie)){
      return (root->movie->mergeWith(movie));
   }

   return false;

}

template <typename Movie>
std::shared_ptr<Movie> MovieBST<Movie>::retrieveHelper(Node* root, std::shared_ptr<Movie> tempSearchKey){
   
   if (root == nullptr){
      return nullptr;
   }

   if (*tempSearchKey == *(root->movie)){
      return root->movie;
   }

   if (*tempSearchKey < *(root->movie)){
      if (root->leftChild){
         return retrieveHelper(root->leftChild, movie);
      }
   } else {
      if (root->rightChild){
         return retrieveHelper(root->rightChild, movie);
      }
      
   }

   return nullptr;

}

template <typename Movie>
void MovieBST<Movie>::displayHelper(Node* root){
   
   if (root == nullptr){
      return;
   }
   
   if (root->leftChild){
      displayHelper(root->leftChild);
   }

   root->movie->printMovie();

   if (root->rightChild){
      displayHelper(root->rightChild);
   }
}

template <typename Movie>
void MovieBST<Movie>::clear(Node* root){

   if (root == nullptr){
      return;
   }

   if (root->leftChild){
      clear(root->leftChild);
      root->leftChild = nullptr;
   }

   if (root->rightChild){
      clear(root->rightChild);
      root->rightChild = nullptr;
   }

   delete root;

}


template <typename Movie>
bool MovieBST<Movie>::insert(std::shared_ptr<Movie> movie){
   if (root == nullptr){
      root = new Node(movie);
      return true;
   } else {
      return insertHelper(root, movie);
   }
}

template <typename Movie>
std::shared_ptr<Movie> MovieBST<Movie>::retrieve(std::shared_ptr<Movie> tempSearchKey){
   if (root != nullptr){
      return retrieveHelper(root, movie);
   }
   return false;
}

template <typename Movie>
void MovieBST<Movie>::display(){
   if (root != nullptr){
      displayHelper(root);
   }
}
