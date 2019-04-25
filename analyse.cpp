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
	fin.open("records.txt")
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
		int sort_pa=FR.date
	}
}
