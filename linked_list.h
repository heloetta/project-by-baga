#ifndef LL_H
#define LL_H
#include<iostream>
#include<string>
#include "Record.h"
//these are are the functions in related with linked list in Module 8
void insert(Node * after,int num);
void delete_head(Node * & head);
void delete_node(Node * after);//assume that after not equal null
void delete_list(Node * & head);
void tail_insert(Node * & head,Node * & tail,int num);//look at ppt p75
#endif
