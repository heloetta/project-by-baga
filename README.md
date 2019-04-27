# project-by-baga
## This is a 1340 project
## We are going to build an Accounting System
## Problem statement
- Currently we find our students sometimes have no ideas about the expense and income or have a hard time trace the records, which result in poor use of the money.This unbalanced financial issue should be tackled and an accounting system will help a lot.          
## Problem settings
- Basic recording part
  income and expenses records
- Basic information: amount, date, types of income or expense (e.g. food, game,salary, etc.), account (e.g cash, bank card, credit card, etc.),remarks; 
  We assume that a expense/income has these 5 basic feature(excluded id).And we define a class Record in Record.h for the sets of data.
And we thought using linked list is a goodchoice to manner the data.So we define a class Node in Record.h through which we apply the use   of dynamic array.
- the records should be added,deleted,edited and viewed
  We store all our records in a file named "records.txt" line by line below the sub values and to make changes.The output data after using a function will cover the previous file.We think this kind of setting reduce the amount of new files we will use thus for us to trace the records more easily.
- Also we design the interface of the output so it will be clearer for the user to see.
- advanced functions
  1. analysis of financial state including monthly/year income, outcome and Engel's cofficient
     We think various kinds of analysis will help user get more aware of his financial status.
  2. set the monthly burget and check if the user need to save money linerly
     We assume that we used money in a linear way.
     (e.g. if user's monthly burget is $3000,it will send alert if he has spent more than $1500 for the first half of the month )
- Makefile
  We use a makefile to help compile all the .cpp&.h files so technically you just first enter make main and ./main in your linux system.
## functionalities and future

-

