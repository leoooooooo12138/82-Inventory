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

void updateproduct(Product goodsarray[], int size, string updateproduct, string lot)
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

void checkproduct()
{

}

void forecast()
{

}

void reminder()
{

}

void inventory_worth() {
	
}

int main() {
  int choice;
  choice = menu();

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

