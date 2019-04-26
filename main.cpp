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

void print_menu()
{
	cout<<"$$$$$$$$$$"<<endl;
	cout<<"MAIN MENU:"<<endl;
	cout<<"1.add new records"<<endl;
	cout<<"2.edit records"<<endl;
	cout<<"3.delete records"<<endl;
	cout<<"4.view records"<<endl;
	cout<<"5.analyze financial state"<<endl;
	cout<<"6.burget setting"<<endl;
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
	bool ifv=false;//only view before can then edit or delete
	while(choice!="0")
	{
		if(choice=="1")
		{
			cout<<"1.add new records"<<endl;
			add();
			ifv=false;
			cout<<endl;
		}
		else if(choice=="2")
		{
			cout<<"2.edit record"<<endl;
			if(ifv)
				edit();
			else
				cout<<"Please view before edit a record"<<endl;
			cout<<endl;
		}
		else if(choice == "3")
		{
			cout<<"3.delete record"<<endl;
			if(ifv)
				deleteline();
			else
				cout<<"Please view before delete a record"<<endl;
			cout<<endl;
		}
		else if(choice == "4")//only view assign id
		{
			cout<<"4.view records"<<endl;
			view();
			ifv=true;
			cout<<endl;
		}
		else if(choice=="5")
		{
			cout<<"5.analyze financial state"<<endl;
			analyse();
			cout<<endl;
		}
		else if (choice=="6")
		{
			cout<<"6.set your budget"<<endl;
			alert();
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
