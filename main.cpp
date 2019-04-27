#include<iostream>
#include<fstream>
#include<string>
#include "Record.h"
#include "add.h"
#include "linked_list.h"
#include "view.h"
#include "edit.h"
#include "delete.h"
#include "Alert.h"
#include <iomanip>
#include <sstream>
#include "analyse.h"
using namespace std;

void print_menu()//this function print the main menu of the accounting system
{
	cout<<"$$$$$$$$$$"<<endl;
	cout<<"MAIN MENU:"<<endl;
	cout<<"1.add new records"<<endl;
	cout<<"2.edit records"<<endl;
	cout<<"3.delete records"<<endl;
	cout<<"4.view records"<<endl;
	cout<<"5.analyse financial state"<<endl;
	cout<<"6.check burget for this month"<<endl;
	cout<<"0.quit"<<endl;
	cout<<"Please enter the number you choose: ";
}

int main()
{
	//print welcome
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<"$ Welcome to Baga's Accounting System $"<<endl;
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	//print welcome
	string choice;
	print_menu();
	cin>>choice;
	cout<<endl;
	bool ifv=false;//only view before can then edit or delete,but after 'add' user need to view again before edit or delete
	while(choice!="0")
	{
		if(choice=="1")
		{
			cout<<"1.add new records"<<endl;
			add();//add new line of record to the records.txt
			ifv=false;
			cout<<endl;
		}
		else if(choice=="2")
		{
			cout<<"2.edit record"<<endl;
			if(ifv)
				edit();//edit one content of a record from records.txt;
			else
				cout<<"Please view before edit a record"<<endl;
			cout<<endl;
		}
		else if(choice == "3")
		{
			cout<<"3.delete record"<<endl;
			if(ifv)
				deleteline();//delete a record from records.txt
			else
				cout<<"Please view before delete a record"<<endl;
			cout<<endl;
		}
		else if(choice == "4")//only view assign id
		{
			cout<<"4.view records"<<endl;
			view();//view every record after sorted by date/amount/account/income or income/type;
			ifv=true;
			cout<<endl;
		}
		else if(choice=="5")
		{
			cout<<"5.analyse financial state"<<endl;
			analyse();//analyze financial state including monthly/yearly income/outcome/engel's cofficient
			cout<<endl;
		}
		else if (choice=="6")
		{
			cout<<"6.check burget for this month"<<endl;
			alert();//input today's date and user's burget for this month and tell the user whether he needs to save money or not
			cout<<endl;
		}
		else
		{
			cout<<"invalid choice"<<endl<<endl;
		}
		print_menu();
		cin>>choice;
		cout<<endl;
	}
	cout<<"Thank You for Using Baga's Accounting System :)"<<endl<<endl;
	return 0;
}
