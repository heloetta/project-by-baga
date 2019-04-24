#include<iostream>
#include<string>
#include "Record.h"
#include<fstream>
#include "view.h"
#include "linked_list.h"
#include<iomanip>
#include<sstream>
using namespace std;
//the following function is used when building a sorted list
Node * find_prev(Node * head,double sort_parameter)
{
	if(head == NULL || head->sort_p >= sort_parameter)
		return NULL;
	Node * current = head;
	while (current->next != NULL)
	{
		if(current->next->sort_p >= sort_parameter)
			return current;
		else
			current = current->next;
	}
	return current;
}

void view()
{
	ifstream fin;
	fin.open("records.txt");
	if(fin.fail())
	{
		cout<<"Error in file opening when viewing fin"<<endl;
		exit(1);
	}
	string line;
	Node * head = NULL,* after_this;
	//get the sort parameter
	int sort_id=1;
	cout<<"view by what?\n1.date 2.income or expense 3.type 4.account 5.amount: ";
	int sort_choice;
	cin>>sort_choice;
	while(getline(fin,line))
	{
		istringstream iss(line);
		Record FinRecord;
		iss>>FinRecord.ID>>FinRecord.date>>FinRecord.IO>>FinRecord.type>>FinRecord.account>>FinRecord.amount>>FinRecord.remark;
		double sort_pa;
		switch(sort_choice)
		{
		case 1:
			sort_pa=FinRecord.date;
			break;
		case 2:
			sort_pa=FinRecord.IO;
			break;
		case 3:
			sort_pa=FinRecord.type;
			break;
		case 4:
			sort_pa=FinRecord.account;
			break;
		case 5:
			sort_pa=FinRecord.amount;
			break;
		}
		//build a sorted linked list
		after_this = find_prev(head,sort_pa);
		if(after_this == NULL)
			head_insert(head,FinRecord,sort_pa);
		else
			insert(after_this,FinRecord,sort_pa);
	}
	fin.close();
	//end of reading from file
	//cout and fout (cover the original txt)
	ofstream fout;
	fout.open("records.txt");
	if(fout.fail())
	{
		cout<<"Error in file opening when viewing fout"<<endl;
		exit(1);
	}
	cout<<"***************************************************************************"<<endl<<endl;
	cout<<setw(5)<<"ID"<<setw(9)<<"date"<<" income/expense"<<setw(15)<<"type";
	cout<<setw(15)<<"account"<<setw(9)<<"amount"<<" remark"<<endl;
	Node * current = head;
	while (current != NULL )
	{
		Record t = current->info;
		t.ID=sort_id;
		cout<<setw(5)<<t.ID<<" "<<setw(8)<<t.date;
		switch(t.IO)
		{
		case 0:
			cout<<setw(15)<<"income";
			break;
		case 1:
			cout<<setw(15)<<"expense";
			break;
		}
		switch(t.type)
		{
		case 1:
			cout<<setw(15)<<"food";
			break;
		case 2:
			cout<<setw(15)<<"rent";
			break;
		case 3:
			cout<<setw(15)<<"salary";
			break;
		case 4:
			cout<<setw(15)<<"game";
			break;
		case 5:
			cout<<setw(15)<<"transportation";
			break;
		case 6:
			cout<<setw(15)<<"transfer";
			break;
		case 7:
			cout<<setw(15)<<"other";
			break;
		}
		switch(t.account)
		{
		case 1:
			cout<<setw(15)<<"Alipay";
			break;
		case 2:
			cout<<setw(15)<<"cash";
			break;
		case 3:
			cout<<setw(15)<<"credit card";
			break;
		case 4:
			cout<<setw(15)<<"Octopus";
			break;
		case 5:
			cout<<setw(15)<<"Wechat Pay";
			break;
		case 6:
			cout<<setw(15)<<"other";
			break;
		}
		cout<<setw(9)<<t.amount;
		cout<<" "<<t.remark<<endl;
		fout<<t.ID<<" "<<t.date<<" "<<t.IO<<" "<<t.type<<" "<<t.account<<" "<<t.amount<<" "<<t.remark<<endl;
		current = current->next;
		sort_id ++;
	}
	cout<<endl<<"****************************************************************************"<<endl;
	fout.close();
}
