#include <iostream>
using namespace std;


int menu() {
  int choice;
  cout << "*************************************************" << endl;
  cout << "***Leo & Taha's 82 Inventory Management System***" << endl;
  cout << "******--What would you like to do today?--******" << endl;
  cout << "******    Choose an option from below    ******" << endl;
  cout << "1. Add a new product" << endl;
  cout << "2. Update Existing Product" << endl;
  cout << "2. Update Existing Product" << endl;
  cout << "3. Check Inventory" << endl;
  cout << "6. Quit" << endl;
  cin >> choice;
  return choice;
}
struct Product {
	string name;
	string type;
	int price;
	int quantity;
	int days_left;
	string batch;
};

int main()
{
  int choice;
  choice = menu();

  while (choice != 6)
  {
	  if (choice == 1)
	  {

	  }
	  if (choice == 2)
	  {

	  }
	  if (choice == 3)
	  {

	  }
  }
 }


// updated message 23321321321
// new shittttttt
//Hellloooooooooo bitches
//82 bitchesssssssssss
