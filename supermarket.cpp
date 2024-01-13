#include <iostream>
#include <iomanip>
using namespace std;
int id[50]; //Global declaration
float price[50];
int choice;
int itemId;
int counter = 0;

void storing(); //Prototype functions
void sort();
void mainMenu();
void retrieve();
void enterId();
void display();
void display_price();
void deleteAll();
void delete_item();

int main()
{
	char option;
	storing(); //function call
	sort();
	do {
		mainMenu();
		cout << "Option: ";
		cin >> option; //user chooses the task he wants
		system("cls");
		switch (option) {
		case'a':
		case'A':
			enterId(); //code to be excuted if user enters a
			break;
		case'b':
		case'B':
			retrieve();
			break;
		case 'c':
		case'C':
			display();
			break;
		case 'd':
		case'D':
			display_price();
			break;
		case 'f':
		case'F':
			deleteAll();
			break;
		case 'g':
		case'G':
			delete_item();
			break;
		case'e':
		case'E':
			break;//break, used to jump out of switch statement
		default: cout << "Invalid input!\n";
		}
	} while (option != 'e'); //loop is repeated untill user enters e
}

void storing() {
	//store input from the user to array
	do {
		for (int i = 0; i < 50; i++) {
			cout << "ID " << i + 1 << ": ";
			cin >> id[i];
			cout << "Price: ";
			cin >> price[i];
			counter++;
			cout << "Enter 1 to store another item\n";
			cout << "Enter 2 to stop storing\n";
			cin >> choice;
			if (choice == 2)
				break;
			system("cls");               //clear console
		}
	} while (choice != 2);
}

void sort() {
	//arranging the items in an ascending order based on their prices
	for (int i = 0; i < counter; i++) {
		for (int j = i + 1; j < counter; j++) {
			if (price[i] > price[j]) {   //checking whether price of first loop is greater than that of second or not
				int temp = price[i];
				price[i] = price[j];
				price[j] = temp;
				temp = id[i];
				id[i] = id[j];
				id[j] = temp;
			}
		}
	}
}

void mainMenu() {
	cout << "**********************Main Menu**********************\n";
	cout << "a.Enter an item ID and price\n";
	cout << "b.Retrieve the price of a specific item\n";
	cout << "c.Display all items\n";
	cout << "d.Display all items within a specific range of prices\n";
	cout << "f.Delete all items\n";
	cout << "g.Delete an item\n";
	cout << "e.Exit\n";
	cout << "*****************************************************\n";
}
void enterId() {
	do {
		for (int i = counter; i < counter + 1; i++) {   //loop starts loop from counter1 & stops at sum of num and counter1
			cout << "ID " << i + 1 << ": ";
			cin >> id[i];
			cout << "Price: ";
			cin >> price[i];
			system("cls");
		}
		counter++;
		cout << "Enter 1 to add another item\n";
		cout << "Enter 2 to return to the main menu\n";
		cin >> choice;
	} while (choice != 2);
}
void retrieve() {
	do {
		cout << "Enter item's ID: ";
		cin >> itemId;
		bool found = false; //boolean expression,checks whether item id is found or not
		for (int i = 0; i < counter; i++) {
			if (itemId == id[i]) { //check whether item the user entered is equal to value of an array
				cout << "Price: " << price[i] << endl; //if condition is true, returns its price
				found = true; //if condition is true, found is  true
			}
		}
		if (!found)
			cout << "Item's ID is not found!\n";
		cout << "Enter 1 to enter another item\n";
		cout << "Enter 2 to return to the main menu\n";
		cin >> choice;
	} while (choice != 2);
}
void display() {
	//printing array elements
	cout << "***********************Items**************************\n";
	for (int i = 0; i < counter; i++) {
		cout << "ID " << i + 1 << ":" << id[i] << setw(20);
		cout << "Price: " << price[i] << endl;
	}
	cout << "Enter 1 to return to the main menu\n";
	cin >> choice;
	system("cls");
}
void display_price() {
	//printing array elements of range betwen prices the user have entered
	int price1, price2;
	do {
		cout << "Enter range of prices.." << endl;
		cout << "From: ";
		cin >> price1;
		cout << "To: ";
		cin >> price2;
		cout << endl;
		for (int i = 0; i < counter; i++) {
			if (price[i] >= price1 && price[i] <= price2) {
				//checks whether values of array "price" are between the range of price the user haved entered
				cout << "ID " << i + 1 << ":" << id[i] << setw(20);
				cout << "Price: " << price[i] << endl;
			}
		}
		cout << "Enter 1 to add another range\n";
		cout << "Enter 2 to return to the main menu\n";
		cin >> choice;
		system("cls");
	} while (choice != 2);
}
void deleteAll() {
	//deleting all items
	for (int i = 0; i < counter; i++) {
		for (int j = i + 1; j < counter; j++) {
			id[i] = id[j]; //replace each array by the one above it, in each iteration
			price[i] = price[j];
			counter--; //decrement the size of array by one
		}
	}
	counter = 0; //all arrays are deleted
	cout << "All items are deleted successfully\n";
}
void delete_item() {
	//deleting an item
	bool found = false;//boolean expression,checks whether item id is found or not
	cout << "Enter the ID of the number you want to delete";
	cin >> itemId;
	int i;
	for (i = 0; i < counter; i++) {
		if (itemId == id[i]) {//check whether item the user entered is equal to value of an array
			found = true; //if condition is true, found is  true
			break;         // break, used to jump out of loop
		}
	}
	if (i < counter) {
		counter--; //decrements counter by one
		for (int j = i; j < counter; j++) {
			id[i] = id[i + 1];
			price[i] = price[i + 1];
		}
		cout << "Item is deleted successfully\n";
	}
	if (!found)
		cout << "Item's ID is not found\n";

}
