#LT Inventory Management System

We are making a inventory management system that stores, sorts and manages inventory for small bussinesses.
It will have different features which the user can choose to implement through his input selection to the console.
The basic outline is as follows:

Menus (Loop): // what the user can choose
1. Add product (include specific details)(What, how much, type,
expiry date, price,batch number)
2. Update products (New batch, quantity, expiry date, (modify))
3. Check products( 1.check all inventory, 2. search by types or
expiry dates, by batch, by quantity, days of inventory left)
4. Forecast (Demand(simple suggestions))
5. Reminder / alert message (link to 3) (multiple reminder
checking) (Expiry 1/2 days left, extreme shortage less than 10,
excessive stock )
6. Quit

The Special features of this management system will be:
1.Categories: Fruits, meat, others(perishables, non-perishables,
dry, non-dry)
2.Forecasting the demands based on simple forecasting methods.
3.Cater for typhoons as special event
4.Expiry date check (every time check if close to expiry date)
5.Inventory worth
6.will be able to handle Batches

Assumptions:
1. Limit the brand of products to only one.
2. Only cater to typhoon as unexpected events and the user will be giving the information
like how long it will come for on what dates and the intensity.
3. For expiry and other prediction systems, we will be using a simplified count system
where we assume all months are for 30 days and expiry times will be shorter (< 2 years)
4. For demand prediction, the system will take the the previous month demand, and total consumption 
for the current month to predict for next month.
