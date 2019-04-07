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

void addproduct()
{

}

void updateproduct()
{

}

void checkproduct()
{

}

void forecast()
{

}

void reminder()
{

}

int main()
{
  int choice;
  choice = menu();

  while (choice != 6)
  {
	  reminder();
	  if (choice == 1)
	  {
		  addproduct();
	  }
	  if (choice == 2)
	  {
		  updateproduct();
	  }
	  if (choice == 3)
	  {
		  checkproduct();
	  }
	  if (choice == 4)
	  {
		  forecast();
	  }
  }
 }

