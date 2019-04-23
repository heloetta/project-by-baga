#include<iostream>
#include<string>
#include "Record.h"
#include<fstream>
#include "add.h"
using namespace std;

void add()
{
	
	ofstream fout;
	fout.open("records.txt",ios::app);
	if(fout.fail())
	{
		cout<<"Error in fout.open"<<endl;
		exit(1);
	}
	cout<<"amount: ";
	cin>>Record.amount;
	cout<<"date(ddmmyyyy): ";
	cin>>Record.date;
	cout<<"type:\n(1.food 2.rent 3.other) ";
	cin>>Record.type;
	cout<<"income or expense:\n(0.income 1.expense) ";
	cin>>Record.IO;
	cout<<"account:\n(1.Alipay 2.cash 3.credit card)";
	cin>>Record.account;
	cout<<"remark: ";
	cin>>Record.remark;
	fout<<Record.date<<"&"<<Record.IO<<"&"<<Record.type<<"&"<<Record.amount<<"&"<<Record.remark<<endl;
	fout.close();
}
