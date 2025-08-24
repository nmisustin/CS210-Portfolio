//Nicolette Misustin
//These are all of the member functions of the grocery item class.
//8/16/2025
#include <iostream>
using namespace std;

#include "GroceryItem.h"
//constructor
GroceryItem::GroceryItem() {
	itemName = " ";
	itemCount = 0;
}
//function returns the item name
string GroceryItem::getItemName() {
	return itemName;
}
void GroceryItem::setItemName(string name) {
	itemName = name;
}
//function returns the item count 
int GroceryItem::getItemCount() {
	return itemCount;
}
//function changes the item count (to be used to increment while reading file)
void GroceryItem::changeItemCount(int newCount) {
	itemCount = newCount;
}