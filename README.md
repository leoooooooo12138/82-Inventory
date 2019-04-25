The "Linux Inventory 82" is our project for Linux enviroment, with a makefile and seperated source code and .h files which can all run in Linux.

The "Windows Inventory 82" contains almost the same coding content in one sigular .cpp file, with the added windows.h header which enables us to add in simple animation effects. The .exe file is a direct executable file for the entire project in case the source code cannot be complied for windows enviroment.

It is advised for you to run the .exe file under the windows version directly. Both version has the same content.

Problem Statement: This is an Inventory management system to help small stores manage their inventory. It gives useful reminders which makes managing inventory easier; gives forecast under both normal circumstances and special events like Typhoon which is often the case in Hong Kong. It also makes viewing product easier by sorting them.

The data is stored in an output file called "Database.txt"
Each time the program runs, this data is loaded, and when the program ends, the updated data is overwritten
Incase the program fails to load the file, an error message will be shown as well as if it fails to write it before ending the program

Each product is stored in a separate line, separated by a space, in the format:
Name Type Price Quantity Daysleftbeforexpiry Batch
where name is a string without any space
type is a string without space
price is a double type
quantity is an integer
daysleftforexpiry is an integer
batch is a string without a space
e.g 
Mango Perishables 5 1000 3 D1

Assumptions: 
It is assumed that there is always atleast 1 product in the database and It is not completely empty because duplicate products will not be treated separately.
For predictions in option 5 & 7, It is assumed there is some sort of data to make the predictions. So incase of option 5, at least one month's data is present on demand and for typhoon prediction, it is known how long the typhoon will rage for and what the intensity will be.
For time series prediction, the data is taken from the user (1, 3, 5, or 7 months' data continously prior to the current month)
For linear regression, after taking in the datasets in the format of month index and demand (e.g. 3 and 50 means the demand for month index 3 is 50) the system predicts the demand for any index month as requested by the user. It merely checks whether currently there are enough products to satisfy this predicted demand, without taking into consideration expiry dates and other factors.
For now, due to the restrictions of method implemented in the prediction process, we do not treat perishables separately so it is advised not to predict demand for perishables. 
For option 6, the data type of the output sum is a double, if the value is too large, it will be given in scientific notation.



The user will use an interface to interact with the program, with 8 options provided. It can handle incorrect input case on the menu, such as a string input instead of a number.
If there are some important reminders, a display message on top of the menu will be displayed grabbing the users attention, Otherwise just the menu will be displayed
The different options can do as follows:

Features:
1. Check reminder: 
There will be a reminder for expiry if "Perishables" are about to expire in 1 day.
There will be a reminder for expiry if "Non Perishables" are about to expire within 1 week.
There will be a reminder for excess inventory if there are more than 10000 units of a particular Product.
If there are no reminders, an output message will be displayed stating as such.

2. Add a new product: To add a new entry into the database. The system will prompt the user for the information from name to batch number, then add it to the database.

3. Update existing Product: It lets you update any of the existing products. It asks for which product to update and the batch number in order to locate the specific product.
In case the product does not exist then an output message will be displayed, otherwise it will prompt the user for the new price, quantity, and expiry date to update the product.

4. View Products: You can check the specific information on products, such as Searching for specific products or inspecting the whole database using filters such as sorting by type, price, quantity, days left till expire. Incase two products have the same value of the filter the user has chosen, the clashing products will be printed out in their existing order in the database. The lower index product will get preference.
All Products will list out the entire database.
Specific Product will search for a specific product after asking for the name and batch number. If the product doesn't exist, it will tell the user not found. Otherwise it will list it out.
By type will list out the inventory, sorted lexicographically according to type
By price will list out all the inventory, sorted by price, printed out from biggest to smallest.
By quantity will list out all the inventory, sorted by quantity, printed out from biggest to smallest.
By days left will list out all the inventory, sorted by how many days will it have till expire, from the biggest to smallest.

5. Inventory checking and predicting: The system will Make predictions of demand and compare with existing stock levels to check for shortages. This option will show the entire current database and give the user a choice to change any of the existing products as deemed necessary before the system makes predictions. Since the system requires some previous data in order to make the predictions it will ask the user which prediction mechanism to use as well as explain what the difference is, and what kind of data each method necessitates. The user can choose a prediction mechanism based on his/her liking.
For time series the demand for the next 30 days is calculated. The system counts all the matching products that have an expiry of more than 30 days, adds up their stock together and compares with the predicted demand. If this sum is less than the predicted demand, it displays a warning, otherwise it tells the user there is enough stock. For this prediction, products with expiry less than 30 days are discounted.
For linear regression, for each data entry two data points are needed i.e Month index and demand and then the system can predict for the demand for a particualar month as specified by the user. The system then checks if at the current point in time, there is enough stock to fulfill that amount of demand, if so the user is told, otherwise a warning is issued.
The user may also check the definition of the two methods incase of further clarification (press 4 or 5 when the program asks). 

6. Inventory worth: You can check the worth of products that are in the inventory. This can be done either by a particular product name, which gives the combined worth of all the batches of the said product, or by typing EVERYTHING, which gives the entire worth of the inventory.

7. Inventory checking and predicting in events of natural disaster: An inventory prediction system taken into consideration the natural disaster situation. It is based on the prediction mechanism from No. 5 but it also takes into consideration what intensity typhoon is incoming and how long it will ravage for. Then using the 2 prediction methods, it tells whether or not there is a chance of facing a stock out.

8. Quit: The updated database will be stored into the file and the program will end.


