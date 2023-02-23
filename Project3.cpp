// Ian Viguera Rivera
// CS210 Programming Languanges
// 02/19/2023

/* This program SEARCHES for a specific item stored in a file, RETURNS items with its purchase frequency,
	and RETURNS a graphical histogram of its item's purchase frequency. */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class ItemTracking { // Class to track item.

public: // Publicly-used Constructors.
	void ReadFile();
	void ShowMenu();

private:  // Privately-used Constructors.
	map<string,int>frequency;
	void SearchItem();
	void PrintList();
	void PrintHistogram();

};

void ItemTracking::ReadFile() {
	ifstream inFile("CS210_Project_Three_Input_File.txt"); // Instruction to read from File.
	string item;

	while (inFile >> item) {
		frequency[item]++;
	}
	inFile.close();
}

void ItemTracking::SearchItem() { // Function for searching User Input through File.
	string item;

	cout << "Enter item you wish to find: " << endl;
	cin >> item;

	if (frequency.find(item) == frequency.end()) {
		cout << "Unable to find " << item  << endl;
		cout << endl;
	}
	else {
		cout << "Item Purchase Frequency: " << frequency[item] << endl;
		cout << endl;
	}
}

void ItemTracking::PrintList() { // Funtion to Print list of items, followed by frequency quantity. 
	cout << "Inventory Purchase Frequency: " << endl;
	cout << endl;
	for (auto const& item : frequency) { // "auto" sorts data in File, returns "item" and "frequency" in one instruction.
		cout << item.first << " " << item.second << endl; 
	}
	cout << endl;
}

void ItemTracking::PrintHistogram() { // Function to Print histogram.
	cout << "Inventory Purchase Histogram: " << endl;
	cout << endl;
	for (auto const& item : frequency) {
		cout << item.first << " ";
		
		for (int i = 0; i < item.second; i++) {
			cout << "|";
		}
		cout << endl;
	}
	cout << endl;
}
 
void ItemTracking::ShowMenu() {
	int option;

	do{

	cout << "\t\t\t***********************************" << endl;
	cout << "\t\t\t* 1. Search Item" << "\t\t  *" << endl;
	cout << "\t\t\t* 2. Inventory Purchase Frequency *" << endl;
	cout << "\t\t\t* 3. Inventory Purchase Histogram *" << endl;
	cout << "\t\t\t* 4. Exit" <<"\t\t\t  *" <<endl;
	cout << "\t\t\t***********************************" << endl;

	cin >> option;

	switch (option) {

	case 1:
		SearchItem();
		break;

	case 2:
		PrintList();
		break;

	case 3:
		PrintHistogram();
		break;

	case 4:
		cout << "Goodbye..." << endl;
		break;

	default:
		cout << "Invalid Input" << endl;
		continue;
	}
	}while (option != 4);
	cout << endl;
}


int main() {
	cout << endl;
	cout << "\t\t\t***********************************" << endl;
	cout << "\t\t\t*     Corner Grocery App Menu\t  *" << endl;
	cout << "\t\t\t***********************************" << endl;
	cout << endl;
	ItemTracking itemTracking;
	itemTracking.ReadFile();
	itemTracking.ShowMenu();
	return 0;

}