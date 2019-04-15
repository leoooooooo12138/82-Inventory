#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <windows.h>

using namespace std;

std::string to_string(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}
/*this function takes an int argument which is the number of different reminders
if the reminders are 0, then it simply displays the menu
otherwise it will also display that there are n number of reminders
the input of this function is the action that the user will choose to do
the function returns the int that specifies what action the user wants to do*/
int menu(int reminders) { // Taha
  int action;
  Sleep(350);
  cout << endl;
  if(reminders != 0) {
  	if(reminders == 1) {
  		cout << "##There is one important reminder you should look into##" << endl;
	  }
	else {
		cout << "##There are  " << reminders << " important reminders you should look into##" << endl;
	}
  }
  cout << "*************************************************" << endl;
  cout << "***Leo & Taha's 82 Inventory Management System***" << endl;
  cout << "******---  What would you like to do?  ---*******" << endl;
  cout << "*******    Choose an option from below    *******" << endl;
  cout << "*1. Check reminders                             *" << endl;
  cout << "*2. Add a new product                           *" << endl;
  cout << "*3. Update Existing Product                     *" << endl;
  cout << "*4. View Products                               *" << endl;
  cout << "*5. Check Stock in case of a Typhoon            *" << endl;
  cout << "*6. Inventory worth                             *" << endl;
  cout << "*7. Quit                                        *" << endl;
  cout << "*************************************************" << endl;
  cin >> action;
  return action;
}

struct Product { // Taha
	string name;
	string type;
	double price;
	int quantity;
	int days_left;
	string batch;
};

/*
//this function will etiher return an integer (or update by reference) that keeps track of how many items there are in total in the function. Please incorporate a counter var in the function to keep track of how many products
//there are in the array. i need this info.
//i have added the number in the header. One will store the size of the array but the other stores how many items there are inside
int addproduct( Product arrayofgoods[],int &number, int num_products) // Leo
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

/*This function will update a certain product that the user wishes to modify (taken as input before the function was called and now passed by value)
it will take the struct array, numbers of products in the array, what product to update and the batch string as its arguments
it will then search for this product in the array and update it according to how the user wishes by taking in input of new price, quantity & expiry
if the product is not found a message as such will be displayed*/
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
			cout <<"\nSorry, the Product you are looking for does not exist in the database. :/" << endl;
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
	
	cout << "\nPlease hang on a minute " << goodsarray[loc].name << " is being added";
	int repeat = 0;
	while (repeat != 3){
		Sleep(350);
		cout << ".";
		repeat++;
	}
	cout << "\nProduct Updated Successfully! ^_^ " << endl;
}

void viewproduct(Product goodsarray[], int size, string checkproduct, string batchstring ) // Leo
{
	int counter = 0;
	string No = "No";
	if (batchstring == No)
	{
		for (int i = 0; i < size; i++)
		{
			if (goodsarray[i].name == checkproduct)
			{
				counter += 1;
				cout << "\nYou have " << checkproduct << " of batch " << goodsarray[i].batch << " with the current selling price of " << goodsarray[i].price << " in stock, the overall quantity of this batch is " << goodsarray[i].quantity << ". They'll have " << goodsarray[i].days_left << " day(s) before expire." << endl;
				continue;
			}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (goodsarray[i].name == checkproduct && goodsarray[i].batch == batchstring)
			{
				counter += 1;
				cout << "\nYou have " << checkproduct << " of batch " << goodsarray[i].batch << " with the current selling price of " << goodsarray[i].price << " in stock, the overall quantity of this batch is " << goodsarray[i].quantity << " . They'll have " << goodsarray[i].days_left << " day(s) before expire." << endl;
			}
		}
	}
	if (counter == 0)
	{
		cout << "\nSorry, the product you are looking for does not exist in the database, you might wanna input again to prevent possible typos if you're sure the product exist. :)" << endl;
	} 
}

void forecast() // Leo
{

}

/*A function to check for important issues to bring to the user's attention before he makes any decision.
the input is the struct array, number of products, as well as a by reference int value for how many imp reminders there are and 
a char that specifies whether we want to be printing out the reminders as well or just updating the value of how many reminders there are
incase the char is I, only the number of reminders value will be updated, but incase it is different, this function will print out the reminders
*/
void reminder(Product *array, int num_p, int &notices, char demand) // Taha
{
	string output;
	notices = 0; //resetting value of notices, to put a fresh calculated value
	//checking expiry
	for(int i = 0; i < num_p; ++i) {
		if(array[i].type != "Perishables" && array[i].days_left < 7) {  //need to treat perishables separately due to their shorter life
			output += "--> " + array[i].name + " of Batch " + array[i].batch + " will expire in " + to_string(array[i].days_left) + " day(s).\n";
			++notices;
		}
		else if (array[i].type == "Perishables" && array[i].days_left < 2) {
			output += "--> " + array[i].name + " of Batch " + array[i].batch + " will expire in " + to_string((array[i].days_left)) + " day.\n";
			++notices;
		}
	}
	//checking excess inventory
	for(int j = 0; j < num_p; ++j) {
		if(array[j].quantity > 10000) {
			output += "--> " + std::string("There are ") + to_string((array[j].quantity)) + " units of unsold " + array[j].name + " of Batch " + array[j].batch + ".\n";
			++notices;
		}
	}
	if(demand == 'I') {  //no need to print anything, only the count of notices was wanted
		return;
	}
	else if(notices == 0) {  //incase viewer chooses option 1 even when there are no imp reminders
		cout << "Great News! You have no pending issues to take note of. \n";
	}
	else {
		cout << "Your attention is called to the following pending issues you may wish to resolve: \n" << output;
	}
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

/*function to dynamically double size of array.
the inputs are current array pointer which is passed by reference so at the end this pointer is updated to the new bigger array and the current size of the array
the new size will be 2*len*/
void increase_size(Product *&current, int &len) {  //Taha
	Product *ptr_to_delete_prev =  current;  //to free up this memory later
	Product *biggerarray = new Product [2*len];  //creating the new bigger array
	for(int i = 0; i < len; i++) {  //to copy all the elements from older to newer
		biggerarray[i] = current[i];
	}
	current = biggerarray;  //updating the ptr of the older (smaller) array to the newer (bigger) array
	delete [] ptr_to_delete_prev;  //releasing memory taken up by smaller array
	len = len*2; //updating the size of our array by reference
}

/*This function will load the database from the database file when the program is run
it takes a pointer to the aray, as well as size of the array and the number of products in it currently
it will then insert these products into the array for further processing by the program*/
void load_array(Product *array, int sizeofarray, int &num_products) // Taha
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
	    cout << "Failed to open Database.txt" << endl;
		exit(1);
	}
	repeat = 0;
	while(repeat !=3) {
		Sleep(300);
		cout << "." << endl;
		repeat++;
	}
	
	while(getline(fin, lineofdata)) {  //read in each line which contains product info and make a stream to feed these values into array
	    if(idx == sizeofarray) {  //incase our product number reaches max size of the array, then increase the size of array
	    	increase_size(array, sizeofarray);
	    }
	    ss.clear();  //tdont forget to clear the stream
	    ss.str(lineofdata);
		ss >> array[idx].name;
		ss >> array[idx].type;
		ss >> array[idx].price;
		ss >> array[idx].quantity;
		ss >> array[idx].days_left;
		ss >> array[idx].batch;
		idx++;
		num_products++;
	}
	if(num_products == 0 || num_products > 1) {
		cout << num_products << " Products loaded successfully!" << endl;
	}
	else {
		cout << num_products << " Product loaded successfully!" << endl;
	}
	fin.close();
}

/*This function outputs the final list of products which are stored in the memory and writes them to the output file. it will be called before
the program terminates. The input is the struct array as well as how many products there are in the array while the output is a file containing all the
details of each product in separate lines for each product
*/
void write_array(Product *save_myarray, int total_products) {
	ofstream fout;
	fout.open("Database.txt");
	if(fout.fail()) {
		cout << "Failed to save data to Database.txt" << endl;
		exit(1);
	}
	for(int  i = 0; i < total_products; ++i) {
		fout << save_myarray[i].name << " ";
		fout << save_myarray[i].type << " ";
		fout << save_myarray[i].price << " ";
		fout << save_myarray[i].quantity << " ";
		fout << save_myarray[i].days_left << " ";
		fout << save_myarray[i].batch << endl;
	}
	fout.close();
}
//
int main() {
  int choice, size = 10, num_products = 0, notices = 0;
  Product database[10]; //struct array to store all our products
  load_array(database, size, num_products);  //initializing program from last saved version
  reminder(database, num_products, notices, 'I');  //I argument so we only get the number of notices, the reminders wont be posted
  choice = menu(notices);
  while (choice != 7) {
	cout << endl;
	switch(choice) {
	  case 1: {
	  	reminder(database, num_products, notices, 'P');  //P arg will mean it prints out the reminders instead of only calculating how many reminders there are
		break;
	  }
	  case 2: {
		//addproduct();
		break;
	  }
	  case 3: {
		string update, batch;
		cout << "Which product would you like to update: ";
		cin >> update;
		cout << "\nPlease enter the batch number for this product: ";
		cin >> batch;
		updateproduct(database, num_products, update, batch);
		break;
      }	  
	  case 4: {
		string check, batch;
		cout << "Which product would you like to check on: ";
		cin >> check;
		cout << "\nPlease enter the batch number for this product (if you wanna check all the batches of one product, enter No): ";
		cin >> batch;
		viewproduct(database, num_products, check, batch);
		break;
      }
	  case 5: {
	    //forecast();
		break;
      }	
	  case 6: {
	    //inventory_worth();
		break;
      }
	  default: {
	  	cout << "Please choose a number between 1 & 7" << endl;
	  	cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  //for max size of buffer or until newline
	  }
    }
    
    reminder (database, num_products, notices, 'I'); //update the value of notices incase any action taken, I so nothing gets printed
    choice = menu(notices);
  }
  write_array(database, num_products);
  cout << "\nThank you for using Leo & Taha's 82 Inventory Management System!\nHave a nice day! :)\nBye Bye!" << endl;
}

