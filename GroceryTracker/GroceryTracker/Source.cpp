//Nicolette Misustin
//This program reads a text file and then counts the number of times each type of item appears in the file. There are then several different options that the user can choose to view this information.
//8/16/2025
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "GroceryItem.h"
using namespace std;
//print menu function with available options and brief instructions on how to select
void printMenu() {
	cout << "Please Select an Option" << endl;
	cout << "1: Print a specific item's frequency." << endl;
	cout << "2: Print all items frequency." << endl;
	cout << "3: Print a histogram of item frequency" << endl;
	cout << "4: Exit Program" << endl;
	cout << "Type the corresponding number to your selection." << endl;
}
// function to increment items from input or add it to the list
vector <GroceryItem> addGroceryItem(string item, vector<GroceryItem> currList) {
	int i;
	//int to be used to check if the item was in the list
	int notInList = 0;
	//iterate through current grocery list
	for (i = 0; i < currList.size(); ++i) {
		//access object
		GroceryItem currItem = currList.at(i);
		string currName = currItem.getItemName();
		//check if the item is already in the list
		if (currName == item) {
			//increment and set the new value of the item
			int newCount = currItem.getItemCount() + 1;
			currItem.changeItemCount(newCount);
			//alter item in vector
			currList.at(i) = currItem;
			//change not in list so that new item will not be added
			notInList = 1;
		}
	}
	//check if the item was in the ist
	if (notInList == 0) {
		//create new grocery item to add to list
		GroceryItem newItem;
		newItem.setItemName(item);
		newItem.changeItemCount(1);
		//add new item
		currList.push_back(newItem);
	}
	//return updated list
	return currList;
}
//option 1 search for a specific item
void menuOptionOne(vector <GroceryItem> items) {
	string userChoice;
	GroceryItem userItem;
	int i;
	//get user input
	cout << "Please type the item you would like to see: " << endl;
	cin >> userChoice;
	//loop and compare user choice string to grocery item list
	for (i = 0; i < items.size(); ++i) {
		GroceryItem currItem = items.at(i);
		if (currItem.getItemName() == userChoice) {
			userItem = currItem;
		}
	}
	//checks if the item count is different than the constructed value (will be at least 1 if added to the list)
	if (userItem.getItemCount() == 0) {
		cout << "This item is not included in the list." << endl;
	}
	//print the item if it is on the list.
	else {
		cout << userItem.getItemName() << " " << userItem.getItemCount() << endl;
	}
}
//option 2 print list with numbers
void menuOptionTwo(vector <GroceryItem> items) {
	int i;
	//loop through grocery item vector and print out item name and number
	for (i = 0; i < items.size(); ++i) {
		GroceryItem currItem = items.at(i);
		cout << currItem.getItemName() << " " << currItem.getItemCount() << endl;
	}
}
//option 3 prin histogram
void menuOptionThree(vector<GroceryItem> items) {
	int i;
	int j;
	// loop through grocery item list
	for (i = 0; i < items.size(); ++i) {
		GroceryItem currItem = items.at(i);
		cout << currItem.getItemName() << " ";
		//loop to print symbols for histogram
		for (j = 0; j < currItem.getItemCount(); ++j) {
			cout << "*";
		}
		//end line
		cout << endl;
	}
}
//menu input handler
void menuHandler(vector <GroceryItem> items) {
	int userChoice = 0;
	//loop to check if exit condition has been met
	while (userChoice != 4) {
		//prints menu
		printMenu();
		cin >> userChoice;
		//calls function for first option
		if (userChoice == 1) {
			menuOptionOne(items);
		}
		//calls function for second option
		else if (userChoice == 2) {
			menuOptionTwo(items);
		}
		//calls function for third option
		else if (userChoice == 3) {
			menuOptionThree(items);
		}
		//acknowledge exit
		else if (userChoice == 4) {
			cout << "Goodbye!" << endl;
		}
		//acknowledges invalid input
		else {
			cout << "Invalid entry try again" << endl;
		}
	}
}
int main() {
	ifstream inFS;
	ofstream outFS;
	vector <GroceryItem> itemsList;

	//open input txt file
	inFS.open("input.txt");
	
	//check if open
	if (!inFS.is_open()) {
		cout << "could not open file." << endl;
	}
	else {
		//open output dat file
		outFS.open("frequency.dat");
		//check if output file is open
		if (!outFS.is_open()) {
			cout << "could not open output file" << endl;
		}
		else{
			//while loop looping through all items until end of file
			while (!inFS.eof()) {
				string item;
				inFS >> item;
				//call add grocery item function to update grocery item list
				itemsList = addGroceryItem(item, itemsList);
			}
			int i;
			//loop through grocery item vector and print out item name and number
			for (i = 0; i < itemsList.size(); ++i) {
				GroceryItem currItem = itemsList.at(i);
				outFS << currItem.getItemName() << " " << currItem.getItemCount() << endl;
			}
			//close input and output files
			inFS.close();
			outFS.close();
		}
		//user menu function
		menuHandler(itemsList);
	}
}