#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

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
  		cout << "##There is 1 important reminder you should look into##" << endl;
	  }
	else {
		cout << "##There are  " << reminders << " important reminders you should look into##" << endl;
	}
  }
  cout << "***********************************************************************" << endl;
  cout << "**************Leo & Taha's 82 Inventory Management System**************" << endl;
  cout << "******---             What would you like to do?             ---*******" << endl;
  cout << "*******              Choose an option from below                *******" << endl;
  cout << "*1. Check reminders                                                   *" << endl;
  cout << "*2. Add a new product                                                 *" << endl;
  cout << "*3. Update Existing Product                                           *" << endl;
  cout << "*4. View Products                                                     *" << endl;
  cout << "*5. Inventory checking and predicting                                 *" << endl;
  cout << "*6. Inventory worth                                                   *" << endl;
  cout << "*7. Inventory checking and predicting in events of natural disaster   *" << endl;
  cout << "*8. Quit                                                              *" << endl;
  cout << "***********************************************************************" << endl;
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

/*function to dynamically double size of array.
the inputs are current array pointer which is passed by reference so at the end this pointer is updated to the new bigger array and the current size of the array
the new size will be 2*len */
void increase_size(Product *&current, int &len) {  //Taha
	Product *ptr_to_delete_prev = current;  //to free up this memory later
	Product *biggerarray = new Product[2 * len];  //creating the new bigger array
	for (int i = 0; i < len; i++) {  //to copy all the elements from older to newer
		biggerarray[i] = current[i];
	}
	current = biggerarray;  //updating the ptr of the older (smaller) array to the newer (bigger) array
	delete[] ptr_to_delete_prev;  //releasing memory taken up by smaller array
	len = len * 2; //updating the size of our array by reference
}

void addproduct( Product goodsarray[], int &size, int &size_of_array) // Leo
{
	if (size == size_of_array)
	{
		increase_size(goodsarray, size);
	}
	cout << "Please enter the product name: " << endl;
	cin >> goodsarray[size].name;
	cout << "Please enter the product type: " << endl;
	cin >> goodsarray[size].type;
	cout << "Please enter " << goodsarray[size].name << "'s unit price (if it is liquid, per liter; if it is meat product, per kilogram): " << endl;
	cin >> goodsarray[size].price;
	cout << "How much " << goodsarray[size].name << " you would like to add this time? : " << endl;
	cin >> goodsarray[size].quantity;
	cout << "How many days can " << goodsarray[size].name << " last till it comes expired? : " << endl;
	cin >> goodsarray[size].days_left;
	cout << "Please enter the batch number of this batch of " << goodsarray[size].name << " : " << endl;
	cin >> goodsarray[size].batch;
	cout << "\nPlease hang on a minute " << goodsarray[size].name << " is being added";
	int repeat = 0;
	while (repeat != 5) {
		Sleep(350);
		cout << ".";
		repeat++;
	}
	cout << "\nProduct added Successfully! ^_^ " << endl;
	size += 1;
	return;
}

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
	while (repeat != 5){
		Sleep(350);
		cout << ".";
		repeat++;
	}
	cout << "\nProduct Updated Successfully! ^_^ " << endl;
}

/* This function takes in the database and its size, to print out the contents */
void display(Product goodsproduct[], int size) // Leo
{
	for (int i = 0; i < size; i++)
	{
		cout << goodsproduct[i].name << " " << goodsproduct[i].type << " " << goodsproduct[i].price << " " << goodsproduct[i].quantity << " " << goodsproduct[i].days_left << " " << goodsproduct[i].batch << endl;
	}
	return;
}

/*Simple Bubble Sort, to sort the cloned database, specified for each of the 3 filters which can be quantified in the Product. Takes in database, its size, and an option index to indicate specific route to commence.*/
void sortfunction(Product goodsarray[], int option, int size)
{
	Product sortedarray[size];
	for (int i = 0; i < size; i++)
	{
		sortedarray[i] = goodsarray[i];
	}
	if (option == 2)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (sortedarray[i].price > sortedarray[j].price)
				{
					Product temp;
					temp = sortedarray[i];
					sortedarray[i] = sortedarray[j];
					sortedarray[j] = temp;
				}
			}
		}
	}
	else if (option == 3)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (sortedarray[i].quantity > sortedarray[j].quantity)
				{
					Product temp;
					temp = sortedarray[i];
					sortedarray[i] = sortedarray[j];
					sortedarray[j] = temp;
				}
			}
		}
	}
	else if (option == 4)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (sortedarray[i].days_left > sortedarray[j].days_left)
				{
					Product temp;
					temp = sortedarray[i];
					sortedarray[i] = sortedarray[j];
					sortedarray[j] = temp;
				}
			}
		}
	}
	display(sortedarray, size);
}

/*The main sorting body of the rest of the unquantifiable filters in Product, and the skeleton program for view product itself, which supports the inspection of the whole data base, with filters featured.*/
void viewproduct(Product goodsarray[], int size, string checkproduct) // Leo
{
	int counter = 0;
	string No = "No";
	string EVERYTHING = "EVERYTHING";
	if (checkproduct == EVERYTHING)
	{
		cout << "These are some of the filters for you to choose from." << endl;
		cout << "1. Product Type." << endl;
		cout << "2. Product Selling Price." << endl;
		cout << "3. Product Quantity in Stock." << endl;
		cout << "4. Product Days Left Before Expiry." << endl;
		cout << "So, which is it gonna be?" << endl;
		int option;
		cin >> option;
		if (option == 1)
		{
			cout << "Which type of product would you like to check on?" << endl;
			string product_type;
			cin >> product_type;
			cout << "So these are all the " << product_type << " products that are currently in stock." << endl;
			for (int i = 0; i < size; i++)
			{
				if (goodsarray[i].type == product_type)
				{
					counter += 1;
					cout << goodsarray[i].name << " " << goodsarray[i].type << " " << goodsarray[i].price << " " << goodsarray[i].quantity << " " << goodsarray[i].days_left << " " << goodsarray[i].batch << endl;
				}
			}
		}
		else if (option == 2)
		{
			counter += 1;
			cout << "So these are all the products in stock with prices ranging from highest to lowest." << endl;
			sortfunction(goodsarray, 2, size);
		}
		else if (option == 3)
		{
			counter += 1;
			cout << "So these are all the products in stock with quantity ranging from highest to lowest." << endl;
			sortfunction(goodsarray, 3, size);
		}
		else if (option == 4)
		{
			counter += 1;
			cout << "So these are all the products in stock with their days left before expiry, from most to least Number of Days." << endl;
			sortfunction(goodsarray, 4, size);
		}
	}
	else
	{
		cout << "Please enter the batch number for this product you want to check (if you wanna check all the batches of this product, enter EVERYTHING): " << endl;
		string batchnum;
		cin >> batchnum;
		if (batchnum == EVERYTHING)
		{
			for (int i = 0; i < size; i++)
			{
				if (goodsarray[i].name == checkproduct)
				{
					counter += 1;
					cout << goodsarray[i].name << " " << goodsarray[i].type << " " << goodsarray[i].price << " " << goodsarray[i].quantity << " " << goodsarray[i].days_left << " " << goodsarray[i].batch << endl;
				}
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (goodsarray[i].name == checkproduct && goodsarray[i].batch == batchnum)
				{
					counter += 1;
					cout << goodsarray[i].name << " " << goodsarray[i].type << " " << goodsarray[i].price << " " << goodsarray[i].quantity << " " << goodsarray[i].days_left << " " << goodsarray[i].batch << endl;
				}
			}
		}
	}
	if (counter == 0)
	{
		cout << "\nSorry, the product you are looking for does not exist in the database, you might want to input again to prevent possible typos if you're sure the product exists. :)" << endl;
	} 
}

/*A time series prediction, asks the user for historical datas and use them to predict further demand. Several options inside, weighted options from 1 month to 7 months historical data supported.*/
void time_series_prediction(Product goodsproduct[], int n, string predictent, int size)
{
	cout << "Please enter the data of previous months you have in order: " << endl;
	int sum = 0;
	switch (n)
	{
		case 1:
		{
			int whatever;
			cin >> whatever;
			cout << "It is likely that the demand of " << predictent << " will be " << whatever << " in the next 30 days. " << endl;
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
				{
					sum += goodsproduct[i].quantity;
				}
			}
			if (sum <= whatever)
			{
				cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
				cout << "You better purchase at least " << whatever - sum << " more " << predictent << "(s) with an expiry date of at least 30 days or more, or else you'll face stock out!" << endl;
			}
			else
			{
				cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
			}
			break;
		}
		case 3:
		{
			double pre = 0;
			int pred;
			double d1, d2, d3;
			cin >> d1;
			cin >> d2;
			cin >> d3;
			pre = d1 * 0.15 + d2 * 0.35 + d3 * 0.5;
			pred = ceil(pre);
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
				{
					sum += goodsproduct[i].quantity;
				}
			}
			cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
			if (sum <= pred)
			{
				cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
				cout << "You better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
			}
			else
			{
				cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
			}
			break;
		}
		case 5:
		{
			double pre = 0;
			int pred;
			double d1, d2, d3, d4, d5;
			cin >> d1;
			cin >> d2;
			cin >> d3;
			cin >> d4;
			cin >> d5;
			pre = d1 * 0.05 + d2 * 0.15 + d3 * 0.2 + d4 * 0.25 + d5 * 0.35;
			pred = ceil(pre);
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
				{
					sum += goodsproduct[i].quantity;
				}
			}
			cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
			if (sum <= pred)
			{
				cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
				cout << "You better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
			}
			else
			{
				cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
			}
			break;
		}
		case 7:
		{
			double pre = 0;
			int pred;
			double d1, d2, d3, d4, d5, d6, d7;
			cin >> d1;
			cin >> d2;
			cin >> d3;
			cin >> d4;
			cin >> d5;
			cin >> d6;
			cin >> d7;
			pre = d1 * 0.05 + d2 * 0.08 + d3 * 0.1 + d4 * 0.15 + d5 * 0.17 + d6 * 0.2 + d7 * 0.25;
			pred = ceil(pre);
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
				{
					sum += goodsproduct[i].quantity;
				}
			}
			cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
			if (sum <= pred)
			{
				cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
				cout << "You'd better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
			}
			else
			{
				cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
			}
			break;
		}
	}
	return;
}

/*A more calibrated time series prediction with coefficient of disaster itself taken into consideration.*/
void time_series_prediction_disaster(Product goodsproduct[], int n, string predictent, int size, int disaster_index, int length)
{
	cout << "Please enter the data of previous months you have in order: " << endl;
	int sum = 0;
	switch (n)
	{
	case 1:
	{
		int whatever;
		cin >> whatever;
		whatever = whatever * (1 + disaster_index * 0.1)*(1+length*0.1);
		cout << "It is likely that the demand of " << predictent << " will be " << whatever << " in the next 30 days. " << endl;
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
			{
				sum += goodsproduct[i].quantity;
			}
		}
		if (sum <= whatever)
		{
			cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
			cout << "You'd better purchase at least " << whatever - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
		}
		else
		{
			cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
		}
		break;
	}
	case 3:
	{
		double pre = 0;
		int pred;
		double d1, d2, d3;
		cin >> d1;
		cin >> d2;
		cin >> d3;
		pre = d1 * 0.15 + d2 * 0.35 + d3 * 0.5;
		pre = pre * (1 + disaster_index * 0.1)*(1 + length * 0.1);
		pred = ceil(pre);
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
			{
				sum += goodsproduct[i].quantity;
			}
		}
		cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
		if (sum <= pred)
		{
			cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
			cout << "You'd better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
		}
		else
		{
			cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
		}
		break;
	}
	case 5:
	{
		double pre = 0;
		int pred;
		double d1, d2, d3, d4, d5;
		cin >> d1;
		cin >> d2;
		cin >> d3;
		cin >> d4;
		cin >> d5;
		pre = d1 * 0.05 + d2 * 0.15 + d3 * 0.2 + d4 * 0.25 + d5 * 0.35;
		pre = pre * (1 + disaster_index * 0.1)*(1 + length * 0.1);
		pred = ceil(pre);
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
			{
				sum += goodsproduct[i].quantity;
			}
		}
		cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
		if (sum <= pred)
		{
			cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
			cout << "You'd better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
		}
		else
		{
			cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
		}
		break;
	}
	case 7:
	{
		double pre = 0;
		int pred;
		double d1, d2, d3, d4, d5, d6, d7;
		cin >> d1;
		cin >> d2;
		cin >> d3;
		cin >> d4;
		cin >> d5;
		cin >> d6;
		cin >> d7;
		pre = d1 * 0.05 + d2 * 0.08 + d3 * 0.1 + d4 * 0.15 + d5 * 0.17 + d6 * 0.2 + d7 * 0.25;
		pre = pre * (1 + disaster_index * 0.1)*(1 + length * 0.1);
		pred = ceil(pre);
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
			{
				sum += goodsproduct[i].quantity;
			}
		}
		cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
		if (sum <= pred)
		{
			cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
			cout << "You'd better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
		}
		else
		{
			cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
		}
		break;
	}
	}
	return;
}

/*A Linear Regression Prediction, using past historical datas to form an equation, thus achieving the porpose of predicting future data points.*/
void linear_regression_prediction(Product goodsproduct[], int n, int premonth, string predictent, int size)
{
	double sumofx = 0;
	double sumofy = 0;
	int arrayofx[n];
	int arrayofy[n];
	for (int i = 0; i < n; i++)
	{
		int month = 0, demand = 0;
		cout << "Please enter the index of month for dataset " << i+1 << " . " << endl;
		cin >> month;
		arrayofx[i] = month;
		cout << "Please enter the corresponding demand of this month. " << endl;
		cin >> demand;
		arrayofy[i] = demand;
		sumofx += month;
		sumofy += demand;
	}
	sumofx = sumofx / n;
	sumofy = sumofy / n;
	double a, b, sumofa, sumofb, sumofab, sumofa2;
	for (int i = 0; i < n; i++)
	{
		sumofa += arrayofx[i];
		sumofb += arrayofy[i];
		sumofab += arrayofx[i] * arrayofy[i];
		sumofa2 += arrayofx[i] * arrayofx[i];
	}
	b = (n*sumofab - sumofa * sumofb) / (n*sumofa2 - sumofa * sumofa);
	a = sumofy - b * sumofx;
	double pre=0;
	int pred;
	pre = a + b * premonth;
	pred = ceil(pre);
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
		{
			sum += goodsproduct[i].quantity;
		}
	}
	cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
	if (sum <= pred)
	{
		cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
		cout << "You'd better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
	}
	else
	{
		cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
	}
	return;
}

/*A more calibrated Linear Regression Prediction, with coefficient of disaster itself taken into consideration. */
void linear_regression_prediction_disaster(Product goodsproduct[], int n, int premonth, string predictent, int size, int disaster_index, int length)
{
	double sumofx = 0;
	double sumofy = 0;
	int arrayofx[n];
	int arrayofy[n];
	for (int i = 0; i < n; i++)
	{
		int month = 0, demand = 0;
		cout << "Please enter the index of month for dataset " << i + 1 << " . " << endl;
		cin >> month;
		arrayofx[i] = month;
		cout << "Please enter the corresponding demand of this month. " << endl;
		cin >> demand;
		arrayofy[i] = demand;
		sumofx += month;
		sumofy += demand;
	}
	sumofx = sumofx / n;
	sumofy = sumofy / n;
	double a, b, sumofa, sumofb, sumofab, sumofa2;
	for (int i = 0; i < n; i++)
	{
		sumofa += arrayofx[i];
		sumofb += arrayofy[i];
		sumofab += arrayofx[i] * arrayofy[i];
		sumofa2 += arrayofx[i] * arrayofx[i];
	}
	b = (n*sumofab - sumofa * sumofb) / (n*sumofa2 - sumofa * sumofa);
	a = sumofy - b * sumofx;
	double pre = 0;
	int pred;
	pre = a + b * premonth;
	pre = pre * (1 + disaster_index * 0.1)*(1 + length * 0.1);
	pred = ceil(pre);
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (goodsproduct[i].name == predictent && goodsproduct[i].days_left >= 30)
		{
			sum += goodsproduct[i].quantity;
		}
	}
	cout << "It is likely that the demand of " << predictent << " will be " << pred << " in the next 30 days. " << endl;
	if (sum <= pred)
	{
		cout << "Since you only have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired after the coming 30 days." << endl;
		cout << "You'd better purchase at least " << pred - sum << " more " << predictent << "(s) with expire date at least 30 days or more, or else you'll face stock out!" << endl;
	}
	else
	{
		cout << "You have " << sum << " " << predictent << "(s) left in your inventory that can remain unexpired even after the coming 30 days, plenty left, there's no need to worry! " << endl;
	}
	return;
}

/*Forecast function's skeleton program. Mainly provides the user with an interface to interact with.*/
void forecast(Product goodsproduct[], int size) // Leo
{
	string disaster;
	string response, NO="NO";
	cout << "This is a total list of your current inventory stored in the system, is there anything different from the actual inventory you'd like to update us with? (If nothing more, type NO) " << endl;
	display(goodsproduct, size);
	cin >> response;
	while (response != NO)
	{
		string batch;
		cout << "Which batch of " << response << " you'd like to update?" << endl;
		cin >> batch;
		updateproduct(goodsproduct, size, response, batch);
		cout << "Anything more?" << endl;
		cin >> response;
	}
	cout << "Which product you would like to make prediction on? " << endl;
	string predictent;
	cin >> predictent;
	cout << "OK, in order to make prediction on " << predictent << ", we need some more information, stick with us. " << endl;
	cout << "There are several prediction methods for you to choose from, each with different specifications on the input parameters." << endl;
	cout << "These methods are as follows: " << endl << endl;
	cout << "1.Time Series (Number of months to which you have data, every individual data)" << endl;
	cout << "2.Linear Regression methods (Number of data sets you have, every individual data set in the format of (x,y) )" << endl;
	cout << "If you're not sure what they stand for, enter 4 or 5 for each one of the method's definition respectively. " << endl << endl;
	int method;
	cout << "Which one would you like to choose? " << endl;
	cin >> method;
	while (method != 0)
	{
		if (method == 1)
		{
			cout << "In time series prediction, you'll need to feed us with the following information: " << endl;
			cout << "The number of continuous month on which you have data to, prior to this month (1, 3, 5 or 7. The greater the number is, the more accurate this prediction will likely be, in other words, the more data you have, the better. ): " << endl;
			int n;
			cin >> n;
			time_series_prediction(goodsproduct, n, predictent, size);
			break;
		}
		else if (method == 2)
		{
			cout << "In linear regression prediction, you'll need to feed us with the following information: " << endl;
			cout << "The number of data sets you have, in the format of (month, quantity): " << endl;
			int n;
			cin >> n;
			cout << "Which month's demand would you like for us to predict?" << endl;
			int premonth;
			cin >> premonth;
			linear_regression_prediction(goodsproduct, n, premonth, predictent, size);
			break;
		}
		else if (method == 4)
		{
			cout << "Time Series Prediction: Uses historical data assuming that what has occurred in the past will continue to occur in the future. " << endl;
			cout << "So, which one would you like to choose? " << endl;
			cin >> method;
		}
		else if (method == 5)
		{
			cout << "Try to fits a trend one degree equation to a series of historical data point, thus predicting the future data with exsiting trend. " << endl;
			cout << "So, which one would you like to choose? " << endl;
			cin >> method;
		}
	}

	return;
}

/*A disaster version of forecast function, takes in two more user inputs, namely disaster index and length of the disaster.*/
void forecastwithdisaster(Product goodsproduct[], int size) // Leo
{
	string disaster = "Typhoon";
	string response, NO = "NO";
	cout << "What's the category of this time's " << disaster << "? (From 1 to 13)" << endl;
	int disaster_index;
	cin >> disaster_index;
	cout << "How long will this time's " << disaster << " last?" << endl;
	int length;
	cin >> length;
	cout << "This is a total list of your current inventory stored in the system, is there anything different from the actual inventory you'd like to update us with? (If nothing more, type NO) " << endl;
	display(goodsproduct, size);
	cin >> response;
	while (response != NO)
	{
		string batch;
		cout << "Which batch of " << response << " you'd like to update?" << endl;
		cin >> batch;
		updateproduct(goodsproduct, size, response, batch);
		cout << "Anything more?" << endl;
		cin >> response;
	}
	cout << "Which product you would like to make prediction on? " << endl;
	string predictent;
	cin >> predictent;
	cout << "OK, in order to make prediction on " << predictent << " as to encounter the coming of " << disaster << ", we need some more information, stick with us. " << endl;
	cout << "There are several prediction methods for you to choose from, each with different specifications on the input parameters." << endl;
	cout << "These methods are as follows: " << endl <<endl;
	cout << "1.Time Series (Number of months to which you have data, every individual data)" << endl;
	cout << "2.Linear Regression methods (Number of data sets you have, every individual data set in the format of (x,y) )" << endl << endl;
	cout << "If you're not sure what they stand for, enter 4 or 5 for each one of the method's definition respectively. " << endl;
	int method;
	cout << "Which one would you like to choose? " << endl;
	cin >> method;
	while (method != 0)
	{
		if (method == 1)
		{
			cout << "In time series prediction, you'll need to feed us with the following information: " << endl;
			cout << "The number of continuous month on which you have data to, prior to this month (1, 3, 5 or 7. The greater the number is, the more accurate this prediction will likely be, in other words, the more data you have, the better. ): " << endl;
			int n;
			cin >> n;
			time_series_prediction_disaster(goodsproduct, n, predictent, size, disaster_index, length);
			break;
		}
		else if (method == 2)
		{
			cout << "In linear regression prediction, you'll need to feed us with the following information: " << endl;
			cout << "The number of data sets you have, in the format of (month, quantity): " << endl;
			int n;
			cin >> n;
			cout << "Which month's demand would you like for us to predict?" << endl;
			int premonth;
			cin >> premonth;
			linear_regression_prediction_disaster(goodsproduct, n, premonth, predictent, size, disaster_index, length);
			break;
		}
		else if (method == 4)
		{
			cout << "Time Series Prediction: Uses historical data assuming that what has occurred in the past will continue to occur in the future. " << endl;
			cout << "So, which one would you like to choose? " << endl;
			cin >> method;
		}
		else if (method == 5)
		{
			cout << "Try to fits a trend one degree equation to a series of historical data point, thus predicting the future data with exsiting trend. " << endl;
			cout << "So, which one would you like to choose? " << endl;
			cin >> method;
		}
	}
	return;
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

/*To check how much money worth of products the user have inside this inventory database.*/
void inventory_worth( Product goodsarray[], int size) // Leo
{
	string productname;
	cout << "Which product's inventory worth would you like to know? (If you want to know how much is everything worth in the warehouse just to feel like a BOSS, type EVERYTHING)" << endl;
	cin >> productname;
	cout << endl;
	int sum = 0;
	if (productname == "EVERYTHING")
	{
		for (int i = 0; i < size; i++)
		{
			sum += goodsarray[i].price * goodsarray[i].quantity;
		}
		if (sum >= 500000)
		{
			cout << "You have $" << sum << " worth of products in your warehouse! You're Loaded!" << endl;
		}
		else
		{
			cout << "You have $" << sum << " worth of products in your warehouse! Go out and purchase more!" << endl;
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (productname == goodsarray[i].name)
			{
				sum += goodsarray[i].price * goodsarray[i].quantity;
			}
		}
		cout << "You have $" << sum << " worth of " << productname << " in your warehouse!" << endl;
	}

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
	if(num_products == 1) {
		cout << num_products << " Product loaded successfully!" << endl;
	}
	else {
		cout << num_products << " Products loaded successfully!" << endl;
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

int main() {
  int choice, size = 10, num_products = 0, notices = 0;
  Product database[10]; //struct array to store all our products
  load_array(database, size, num_products);  //initializing program from last saved version
  reminder(database, num_products, notices, 'I');  //I argument so we only get the number of notices, the reminders wont be posted
  choice = menu(notices);
  while (choice != 8) {
	cout << endl;
	switch(choice) {
	  case 1: {
	  	reminder(database, num_products, notices, 'P');  //P arg will mean it prints out the reminders instead of only calculating how many reminders there are
		break;
	  }
	  case 2: {
		addproduct(database, num_products, size);
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
		cout << "Which product would you like to check on (If you wanna check on everything, just type EVERYTHING): ";
		cin >> check;
		viewproduct(database, num_products, check);
		break;
      }
	  case 5: {
	    forecast(database, num_products);
		break;
      }	
	  case 6: {
	    inventory_worth(database, num_products);
		break;
      }
	  case 7: {
		  forecastwithdisaster(database, num_products);
	  }
	  default: {
	  	cout << "Please choose a number between 1 & 8" << endl;
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

