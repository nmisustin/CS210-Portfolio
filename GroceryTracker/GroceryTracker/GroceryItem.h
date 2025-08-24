//Nicolette Misustin
//This is the definition of the grocery item used in the rest of the program
//8/16/2025
#include <string>
#ifndef GROCERYITEM_H
#define GROCERYITEM_H

class GroceryItem {
public:
	GroceryItem();
	std::string getItemName();
	void setItemName(std::string name);
	int getItemCount();
	void changeItemCount(int newCount);
private:
	std::string itemName;
	int itemCount;
};

#endif