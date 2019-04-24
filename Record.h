#ifndef RECORD_H
#define RECORD_H
#include<iostream>
#include<fstream>
#include"Record.h"
#include<string>
using namespace std;
class Record
{
public:
	double amount;
	int date;
	int type;//the same as account:wq
	bool IO;
	int account;//for better match.use int to stand for certain string
//e.g. 1.Alipay 2.cash 3.credit card .......
	string remark;
	int ID;
};
class Node
{
public:
	Record info;
	Node * next;
};
#endif
