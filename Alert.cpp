#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Alert.h"
#include"Record.h"
using namespace std;
void alert()
{
	int tdate,startt,wmonth,dayinmonth,wyear;
	cout<<"Today's date is(yyyymmdd): ";
	cin>>tdate;
	startt=tdate/100;//get yyyymm
	wmonth=startt%100;//get month e.g. april octomber
	wyear=startt/100;
	switch(wmonth)//get how many days in the current month
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		dayinmonth=31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		dayinmonth=30;
		break;
	case 2:
		if(wyear%4==0)
		{
			if(wyear % 100 == 0 && wyear % 400 != 0)
				dayinmonth=28;
			else
				dayinmonth=29;
		}
		else
			dayinmonth=28;
		break;
	}
	startt*=100;//yyyymm00;
	cout<<"Enter your monthly budget: "<<endl;
	double max;
	cin>>max;
	string filename = "records.txt";
	ifstream fin( filename.c_str() );
	if ( fin.fail())
	{
		cout << "Error in file opening!" << endl;
		exit(1);
	}
	string line;
	double sum=0;
	while(getline(fin,line))
	{
		istringstream iss(line);
		Record FinRecord;
		iss>>FinRecord.ID>>FinRecord.date>>FinRecord.IO>>FinRecord.type>>FinRecord.account>>FinRecord.amount>>FinRecord.remark;
		if(FinRecord.IO==1&&FinRecord.date>startt&&FinRecord.date<=tdate)
			sum+=FinRecord.amount;
	}
	fin.close();
	double mav,tav;
	tav=sum/(tdate-startt);
	mav=max/dayinmonth;
	if(tav>mav)
		cout<<"WARNING!SAVE YOUR MONEY!"<<endl;
	else
		cout<<"safe"<<endl;
	delete_list(head);
}
