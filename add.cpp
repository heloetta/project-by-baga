#include<iostream>
#include<string>
#include "Record.h"
#include<fstream>
#include "add.h"
using namespace std;

void add()
{
	
	Record OneR;
	ofstream fout;
	fout.open("records.txt",ios::app);
	if(fout.fail())
	{
		cout<<"Error in fout.open"<<endl;
		exit(1);
	}
	cout<<"amount: ";
	cin>>OneR.amount;
	cout<<"date(ddmmyyyy): ";
	cin>>OneR.date;
	cout<<"type\n(1.food 2.rent 3.salary 4.game 5.transportation 6.transfer 7.other): ";
	cin>>OneR.type;
	cout<<"income or expense\n(0.income 1.expense): ";
	cin>>OneR.IO;
	cout<<"account\n(1.Alipay 2.cash 3.credit card 4.Octopus 5.Wechat_Pay 6.other): ";
	cin>>OneR.account;
	cout<<"remark(please do not use space): ";
	cin>>OneR.remark;
	fout<<"0 "<<OneR.date<<" "<<OneR.IO<<" "<<OneR.type<<" "<<OneR.account<<" "<<OneR.amount<<" "<<OneR.remark<<endl;
	fout.close();
}
