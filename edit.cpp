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
	int ide;
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
	//cout and fout (cover the original txt)
        int choice,ed;
	string word;
        cout<<"Edit what?\n1.date 2.IO 3.type 4.account 5.amount 6.remark: ";
        cin>>choice;
        cout<<"Enter the edited value: ";
	if(choice!=6)
        cin>>ed;
	else
	cin>>word;
	ofstream fout;
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
	        if(t.ID==ide)
		{
			switch(choice)
			{
			case 1:
				t.date=ed;
				break;
			case 2:
				t.IO=ed;
				break;
			case 3:
				t.type=ed;
				break;
			case 4:
				t.account=ed;
				break;
			case 5:
				t.amount=ed;
				break;
			case 6:
				t.remark=word;
				break;	
			}
		}
		fout<<t.ID<<" "<<t.date<<" "<<t.IO<<" "<<t.type<<" "<<t.account<<" "<<t.amount<<" "<<t.remark<<endl;
		current = current->next;
	}
	fout.close();
	delete_list(head);
}
