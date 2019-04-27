# project-by-baga
## This is a 1340 project
## We are going to build an Accounting System
## Problem statement
- Problem cause
## We want to make an accounting system to help ourselves to better manage our money.Lower is a brief introduction
- Basically you add, delete and edit records.We use sort function in "view" function so you can clearly see the id of each record.(placed at the front of each record)
- We also set
     
## Problem settings
- Basic recording part
  1. records of income and expenses including basic information such as  amount, date, types of income or expense (e.g. food, game,salary, etc.), account (e.g. cash, bank card, credit card, etc.),remarks.
  2. the records should be added,deleted,edited and viewed.
- advanced functions
  1. analysis of financial state including monthly/year income, outcome and Engel's cofficient
  2. set the monthly burget and check if the user need to save money linerly(e.g. if user's monthly burget is $3000,it will send alert if he has spent more than $1500 for the first half of the month )

## functionalities and future
1. add new records
   - this function allows users to input all the information expect ID of a new record and then append it into the "record.txt".The default of ID is 0,which is not imported before view.
2. edit records
   - this function can be only used after viewing the records.However, if the user add a new record after viewing,he/she needs to view again before editing records.
   - this function allows users to edit one information in a record with the ID of the record in the latest viewed records from the records.txt.
3. delete records 
   - this function can be only used after viewing the records.However, if the user add a new record after viewing,he/she needs to view again before deleting records.
   - this function allows users to delete a whole record with the ID of the record in the latest viewed records from the records.txt.
4. view records
   - this function allows users to view all the records in the records.txt sorted by date,account,type,income or expense and amount.
   - this function will assign the ID of records and is necessary for editing and deleting.
5. analyse financial state
   - this function can analyze the yearly/monthly income,expenses and Engel's cofficient.
   - this function will ask users to choose which month/year and what to analyse.
6. check burget for this month
   - this function will ask users to input today's date and the burget for this month and judge if the users need to save money linerly.It will print "WARNING!SAVE YOUR MONEY" or "safe".
0. quit
   - quit the accounting system
