#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include "menu.h"

using namespace std;

int menu(int reminders) { // Taha
	int action;
	cout << endl;
	if (reminders != 0) {
		if (reminders == 1) {
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
