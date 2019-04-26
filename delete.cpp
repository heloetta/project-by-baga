#include<iostream>
#include<string>
#include "Record.h"
#include<fstream>
#include "delete.h"
#include "linked_list.h"
#include<iomanip>
#include<sstream>
using namespace std;
void deleteline()
{
	int ide;
	cout<<"delete which line\nplease enter the ID of the record: ";
	cin>>ide;
	ifstream fin;
	fin.open("records.txt");
	if(fin.fail())
	{
		cout<<"Error in file opening when deleting fin"<<endl;
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
	ofstream fout;
	fout.open("records.txt");
	if (fout.fail())
	{
		cout<<"Error in file opening when deleting fout"<<endl;
		exit(1);
	}
	Node * current = head;
	while (current != NULL )
	{
		Record t = current->info;
		if(t.ID==ide)
		{
		current=current->next;
		continue;
		}
		fout<<t.ID<<" "<<t.date<<" "<<t.IO<<" "<<t.type<<" "<<t.account<<" "<<t.amount<<" "<<t.remark<<endl;
		current = current->next;
	}
	fout.close();
	delete_list(head);
}
