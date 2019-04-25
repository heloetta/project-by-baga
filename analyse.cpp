#include <iostream>
#include <fstream>
#include <sstream>
#include "Record.h"
#include <string>
#include "linked_list.h"
#include "analyse.h"
using namespace std;
void analyse()
{
	ifstream fin;
	fin.open("records.txt");
	if(fin.fail())
	{
		cout<<"Error in file opening when calculating engel"<<endl;
		exit(1);
	}
	string line;
	Node * head = NULL,* after_this;
	while(getline(fin,line))
	{
		istringstream iss(line);
		Record FR;
		iss>>FR.ID>>FR.date>>FR.IO>>FR.type>>FR.account>>FR.amount>>FR.remark;
		int sort_pa=FR.date;
		//build sorted linked list by date
		after_this = find_prev(head,sort_pa);
		if(after_this == NULL )
			head_insert(head,FR,sort_pa);
		else
			insert(after_this,FR,sort_pa);
	}
	fin.close();
	cout<<"what do you want to analyse\n1.monthly income 2.monthly expense 3.monthly engel's cofficient\n4.yearly income 5.yearly expense 6.yearly engel's cofficient\nEnter your choice: ";
	int analyse_what;
	cin>>analyse_what;//get what the user want
	double sum_of_expense=0,sum_of_food=0,sum_of_income=0;
	int inputTime,start,end;//start00<date<end00
	cout<<"For which ";
	switch(analyse_what)
	{
	case 1:
	case 2:
	case 3:
		cout<<"month(yyyymm): ";
		cin>>inputTime;
		start=inputTime*100;
		end=inputTime*100+100;
		break;
	case 4:
	case 5:
	case 6:
		cout<<"year(yyyy): ";
		cin>>inputTime;
		end=start+1;
		start=inputTime*10000;
		end=inputTime*10000+10000;
		break;
	}
	Node * current = head;
	while(current!=NULL)//sum if right_time
	{
		Record t = current->info;
		if(t.date>start && t.date<end)
		{
			if(t.IO==0)
				sum_of_income+=t.amount;
			else
			{
				sum_of_expense+=t.amount;
				if(t.type==1)
					sum_of_food+=t.amount;
			}
		}
		current=current->next;
	}
	switch(analyse_what)
	{
	case 1:
	case 2:
		cout<<"monthly";
		break;
	case 4:
	case 5:
		cout<<"yearly";
		break;
	}
	switch(analyse_what)
	{
	case 1:
	case 4:
		cout<<" income of "<<inputTime<<" is "<<sum_of_income<<endl;
		break;
	case 2:
	case 5:
		cout<<" expense of "<<inputTime<<" is "<<sum_of_expense<<endl;
		break;
	case 3:
	case 6:
		if(sum_of_expense!=0)
		{
			if(analyse_what==3)
				cout<<"monthly";
			else
				cout<<"yearly";
			double ec=sum_of_food*100/sum_of_expense;
			cout<<" engel's cofficient of"<<inputTime<<" is "<<ec<<"%"<<endl;
		}
		else
			cout<<"No expense"<<endl;
		break;
	}
	delete_list(head);
}





