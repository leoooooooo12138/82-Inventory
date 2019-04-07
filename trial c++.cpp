#include <iostream>
using namespace std;


int menu() { // Taha
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
struct Product { // Taha
	string name;
	string type;
	int price;
	int quantity;
	int days_left;
	string batch;
};

void addproduct( Product arrayofgoods[],int &number) // Leo
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

void updateproduct(Product goodsarray[], int size, string updateproduct, string lot) // Taha
{
	//need to locate product first
	int loc;
	for(int i = 0; i < size; i++) {
		if(goodsarray[i].name == updateproduct && goodsarray[i].batch == lot) {
			loc = i;
			break;
		}
		else if(i + 1 == num) {  //incase we reach last iteration and product still not found
			cout <<"Sorry, The Product you are looking for does not exist in the database." << endl;
			return;
		}
	}
	
	//updating the product 
	cout << "Enter the new Price: ";
	cin >> goodsarray[loc].price << endl;
	cout << "Enter the updated quantity: ";
	cin >> goodsarray[loc].quantity << endl;
	cout << "Enter the new Expiry date: ";
	cin >> goodsarray[loc].expiry << endl;
	
	cout << "Product Updated Successfully! ^_^ " << endl;
}

void checkproduct() // Leo
{

}

void forecast() // Leo
{

}

void reminder() // Taha
{

}

void inventory_worth( Product arrayofgoods[], int &number) // Leo
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

array load_array() // Taha
{

}

int main() {
  int choice;
  choice = menu();
  load_array();
  while (choice != 6) {
	reminder();
	cin >> choice << endl;
	switch(choice) {
	  case 1:
		addproduct();
		break;
  
	  case 2:
		string update, batch;
		cout << "Which product do you want to update?";
		cin >> update << endl;
		cout << "Enter the batch number for this product: ";
		cin >> batch << endl;
		updateproduct(productarray, size, update, batch);
		break;
		  
	  case 3:
		checkproduct();
		break;
		  
	  case 4:
	    forecast();
		break;
		
	  case 5:
	    inventory_worth();
		break;
		
	  case 6:
		cout << "Thank you for using LT Management System\n Have a nice day! :)" << endl;
		break;
		
	  default:
		cout << "Please choose a number between 1-6!"
    }
  }
}

