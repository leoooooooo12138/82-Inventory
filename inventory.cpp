#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
using namespace std;


int menu() { // Taha
  int action;
  cout << "*************************************************" << endl;
  cout << "***Leo & Taha's 82 Inventory Management System***" << endl;
  cout << "******---  What would you like to do?  ---*******" << endl;
  cout << "*******    Choose an option from below    *******" << endl;
  cout << "*1. Add a new product                           *" << endl;
  cout << "*2. Update Existing Product                     *" << endl;
  cout << "*3. Check A Product                             *" << endl;
  cout << "*4. Catastrophic event                          *" << endl;
  cout << "*5. Inventory worth                             *" << endl;
  cout << "*6. Quit                                        *" << endl;
  cout << "*************************************************" << endl;
  //reminder();
  cin >> action;
  return action;
}
struct Product { // Taha
	string name;
	string type;
	int price;
	int quantity;
	int days_left;
	string batch;
};
/*
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
}*/

void updateproduct(Product goodsarray[], int size, string updateproduct, string lot) // Taha
{
	//need to locate product first
	int loc;
	for(int i = 0; i < size; i++) {
		if(goodsarray[i].name == updateproduct && goodsarray[i].batch == lot) {
			loc = i;
			break;
		}
		else if(i + 1 == size) {  //incase we reach last iteration and product still not found
			cout <<"\nSorry, The Product you are looking for does not exist in the database." << endl << endl;
			Sleep(500);
			return;
		}
	}
	
	//updating the product 
	cout << "\nEnter the new Price: ";
	cin >> goodsarray[loc].price; 
	cout << "\nEnter the updated quantity: ";
	cin >> goodsarray[loc].quantity;
	cout << "\nEnter the new Expiry date: ";
	cin >> goodsarray[loc].days_left;
	
	cout << "\nHang on a minute " << goodsarray[loc].name << " is being added";
	int repeat = 0;
	while (repeat != 3){
		Sleep(350);
		cout << ".";
		repeat++;
	}
	cout << "\nProduct Updated Successfully! ^_^ " << endl << endl;
	Sleep(500);
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
/*
void inventory_worth( Product arrayofgoods[], int &number) // Leo
{
	string productname;
	cout << "Which product's inventory worth would you like to know? (If you want to know how much is everything worth in the warehouse just to feel like a BOSS, type EVERYTHING)" << endl;
	cin >> productname;
	cout << endl;
	if (productname == "EVERYTHING")
	{
		int sum = 0;
		for (int i = 0; i < number; i++)
		{
			sum += arrayofgoods[i].price * arrayofgoods[i].quantity;
		}
		cout << "You have $" << sum << " worth of products in your warehouse!" << endl;
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
*/

//function to double size of array. Current is current array and len is current size. new size will be 2*len
Product* increase_size(Product *&current, int &len) {  //Taha
	Product *ptr_to_delete_prev =  current;  //to free up this memory later
	Product *biggerarray = new Product [2*len];  //creating the new bigger array
	for(int i = 0; i < len; i++) {  //to copy all the elements from older to newer
		biggerarray[i] = current[i];
	}
	current = biggerarray;  //updating the ptr of the older (smaller) array to the newer (bigger) array
	delete [] ptr_to_delete_prev;  //releasing memory taken up by smaller array
	len = len*2; //updating the size of our array by reference
}

//function to load data from database using file input
void load_array(Product *array, int sizeofarray) // Taha
{
	cout << "Please wait a moment while the program is loading ";
	int repeat = 0;
	while (repeat != 4){
		Sleep(350);
		cout << ".";
		repeat++;
	}
	cout << endl;
	int idx = 0;
	stringstream ss;
	string lineofdata;
	ifstream fin;
	fin.open("Database.txt");
	if(fin.fail()) {
	    cout << "Failed to open database.txt" << endl;
		exit(1);
	}
	repeat = 0;
	while(repeat !=3) {
		Sleep(300);
		cout << "." << endl;
		repeat++;
	}
	cout << "Database loaded successfully!" << endl << endl;
	while(getline(fin, lineofdata)) {  //read in each line which contains product info and make a stream to feed these values into array
	    if(idx == sizeofarray) {  //incase our product number reaches max size of the array, then increase the size of array
	    	increase_size(array, sizeofarray);
	    }
	    ss.str(lineofdata);
		ss >> array[idx].name;
		ss >> array[idx].type;
		ss >> array[idx].price;
		ss >> array[idx].quantity;
		ss >> array[idx].days_left;
		ss >> array[idx].batch;
		idx++;
	}
	fin.close();
}

int main() {
  int choice, size = 10;
  Product database[10]; //array to store all our products
  load_array(database, size);  //initializing program from last saved version
  choice = menu();
  while (choice != 6) {
	cout << endl;
	switch(choice) {
	  case 1: {
		//addproduct();
		break;
	  }
  
	  case 2: {
		string update, batch;
		cout << "Which product would you like to update: ";
		cin >> update;
		cout << "\nPlease enter the batch number for this product: ";
		cin >> batch;
		updateproduct(database, size, update, batch);
		break;
      }	  
	  case 3: {
		//checkproduct();
		break;
      }
	  case 4: {
	    //forecast();
		break;
      }	
	  case 5: {
	    //inventory_worth();
		break;
      }
	  default:
		cout << "Please choose a number between 1-6!" << endl;
    }
    choice = menu();
  }
  cout << "\nThank you for using Leo & Taha's 82 Inventory Management System!\nHave a nice day! :)\nBye Bye! ^_^" << endl;
}

