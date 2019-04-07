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
  cout << "3. Check Inventory" << endl;
  cout << "4. Catastrophic event" << endl;
  cout << "5. Inventory worth" << endl;
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

void addproduct( Product arrayofgoods[],int &number)
{
	cout << "Please enter the product name: " << endl;
	cin >> Product.name >> endl;
	cout << "Please enter the product type: " << endl;
	cin >> Product.type >> endl;
	cout << "Please enter " << Product.name << "'s unit price (if it is liquid, per liter; if it is meat product, per kilogram): " << endl;
	cin >> Product.price >> endl;
	cout << "How much " << Product.name << " you would like to add this time? : " << endl;
	cin >> Product.quantity >> endl;
	cout << "How many days can " << Product.name << " last till it comes expired? : " << endl;
	cin >> Product.days_left >> endl;
	cout << "Please enter the batch number of this batch of " << Product.name << " : " << endl;
	cin >> Product.batch >> endl;

	arrayofgoods[number + 1] = Product;
	number += 1;

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

void inventoryworth( Product arrayofgoods[], int &number)
{
	string productname;
	cout << "Which product's inventory worth would you like to know? (If you want to know how much is everything worth in the warehouse just to feel like a BOSS, type EVERYTHING)" << endl;
	cin >> productname >> endl;
	if (productname == "EVERYTHING")
	{
		int sum = 0;
		for (int i = 0; i < number; i++)
		{
			sum += arrayofgoods[i].price * arrayofgoods[i].quantity;
		}
		cout << "You have " << sum << "$ worth of products in your warehouse!" << endl;
	}
	for (int i = 0; i < number; i++)
	{
		int sum = 0;
		if (productname == arrayofgoods[i].name)
		{
			sum += arrayofgoods[i].price * arrayofgoods[i].quantity;
		}
		cout << "You have " << sum << "$ worth of " << productname << " in your warehouse!" << endl;
	}

}

array load_array()
{

}

int main()
{
  int choice;
  choice = menu();
  load_array();

  while (choice != 6)
  {
	  reminder();
	  if (choice == 1)
	  {
		  addproduct(arrayofgoods,number);
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
	  if (choice == 5)
	  {
		  inventoryworth();
	  }
  }
 }

