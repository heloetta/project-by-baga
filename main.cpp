#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct record{
	double amount;
	int date;
	string type;
	bool IO;
	string account;
	string remark;		
};

//a function to test whether to send alert after 1.2.3.6.
bool ifalert()
{
	
}
//end of the function

//a function to view the records
void
//end of this function

void print_menu()
{
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
	while(choice!="0")
	{
		if(choice=="1")
		{
			cout<<"1"<<endl;
			//add function here
			cout<<endl;
		}
		else if(choice=="2")
		{
			cout<<"2"<<endl;
			//add function here
			cout<<endl;
		}
		else if(choice == "3")
		{
			cout<<"3"<<endl;
			//add function here
			cout<<endl;
		}
		else if(choice == "4")
		{
			cout<<"4"<<endl;
			
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
