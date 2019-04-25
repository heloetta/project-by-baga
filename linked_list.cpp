#include<iostream>
#include<string>
#include "Record.h"
#include<fstream>
#include "linked_list.h"
using namespace std;
//these are all functiuons copied from the guide notes of Module 8

void insert(Node * after, Record insert_record,double sort_parameter)
{
	Node * p = new Node;
	p->info = insert_record;
	p->sort_p = sort_parameter;
	p->next=after->next;
	after->next = p;
}

void delete_head(Node * & head)
{
	if (head != NULL)
	{
		Node * p =head;
		head = head->next;
		delete p;
	}
}
void delete_node(Node * after)
{
	Node * p =after->next;
	after->next = p->next;
	delete p;
}

void delete_list(Node * & head)
{
	while (head != NULL)
	{
		delete_head(head);
	}
}
void tail_insert(Node * & head,Node * & tail ,Record NextRecord)
{
	Node * p = new Node;
	p->info=NextRecord ;
	p->next=NULL;
	if(head == NULL )
	{
		head=p;
		tail=p;
	}
	else
	{
		tail->next=p;
		tail = p;
	}
}
void head_insert(Node * & head,Record NextRecord,double sort_parameter)
{
	Node * p = new Node;
	p->info = NextRecord;
	p->next = head;
	p->sort_p = sort_parameter;
	head=p;
}

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
			current=current->next;
	}
	return  current;
}


