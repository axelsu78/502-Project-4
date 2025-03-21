/* Axel Sundstrom and Cameron Chen
   CSS 502 Assignment 4
   Inventory Storage Class
*/

#include "inventorystorage.h"

InventoryStorage::InventoryStorage() {
}

void InventoryStorage::getInventory() const{
   comedyTree.display();
   dramaTree.display();
   classicTree.display();
}