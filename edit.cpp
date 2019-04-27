#include<iostream>
#include<string>
#include "Record.h"
#include<fstream>
#include "edit.h"
#include "linked_list.h"
#include<iomanip>
#include<sstream>
using namespace std;
void edit()
{
	int ide;//get the id of the record to be edited
	cout<<"edit which record?\nplease enter the ID of the record: ";
	cin>>ide;
	ifstream fin;
	fin.open("records.txt");
	if(fin.fail())
	{
		cout<<"Error in file opening when editing fin"<<endl;
		exit(1);
	}
	string line;
	Node * head = NULL,* after_this;
	//get the sort parameter
	while(getline(fin,line))
	{
		istringstream iss(line);
		Record FinRecord;
		iss>>FinRecord.ID>>FinRecord.date>>FinRecord.IO>>FinRecord.type>>FinRecord.account>>FinRecord.amount>>FinRecord.remark;
		double sort_pa=FinRecord.ID;
		//build a sorted linked list
		after_this = find_prev(head,sort_pa);
		if(after_this == NULL)
			head_insert(head,FinRecord,sort_pa);
		else
			insert(after_this,FinRecord,sort_pa);
	}
	fin.close();
	//end of reading from file
	int choice;//get which information to be edited
	int edit_int;
	double edit_double;
	string edit_string;
	cout<<"Edit what?\n1.date 2.income or expense 3.type 4.account 5.amount 6.remark: ";
	cin>>choice;
	switch(choice)//get the edited information
	{
	case 1:
		cout<<"Enter the edited date(yyyymmdd): ";
		cin>>edit_int;
		break;
	case 2:
		cout<<"Edit:income or expense\n(0.income 1.expense): ";
		cin>>edit_int;
		break;
	case 3:
		cout<<"Enter the edited type\n(1.food 2.rent 3.salary 4.game 5.transportation 6.transfer 7.other): ";
		cin>>edit_int;
		break;
	case 4:
		cout<<"Enter the edited account\n(1.Alipay 2.cash 3.credit card 4.Octopus 5.Wechat Pay 6.other): ";
		cin>>edit_int;
		break;
	case 5:
		cout<<"Enter the edited amount: ";
		cin>>edit_double;
		break;
	case 6:
		cout<<"Enter the edited remark\n(please do not use space): ";
		cin>>edit_string;
		break;
	}
	ofstream fout;//cover the origin txt
	fout.open("records.txt");
	if(fout.fail())
	{
		cout<<"Error in file opening when editing fout"<<endl;
		exit(1);
	}
	Node * current = head;
	while (current != NULL )
	{
		Record t = current->info;
		if(t.ID==ide)//editing 
		{
			switch(choice)
			{
			case 1:
				t.date=edit_int;
				break;
			case 2:
				t.IO=edit_int;
				break;
			case 3:
				t.type=edit_int;
				break;
			case 4:
				t.account=edit_int;
				break;
			case 5:
				t.amount=edit_double;
				break;
			case 6:
				t.remark=edit_string;
				break;	
			}
		}
		fout<<t.ID<<" "<<t.date<<" "<<t.IO<<" "<<t.type<<" "<<t.account<<" "<<t.amount<<" "<<t.remark<<endl;
		current = current->next;
	}
	fout.close();
	delete_list(head);
}
