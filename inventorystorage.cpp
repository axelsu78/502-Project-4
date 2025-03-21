#include "inventorystorage.h"

InventoryStorage::InventoryStorage() {
}

void InventoryStorage::getInventory() const{
   comedyTree.display();
   dramaTree.display();
   classicTree.display();
}