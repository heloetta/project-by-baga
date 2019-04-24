#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include"Record.h"
using namespace std;
void edit(int ID){
    cin>>ID>>endl;
    string filename = "records.txt";
	  ifstream fin( filename.c_str() );
    if ( fin.fail() ){
		cout << "Error in file opening!" << endl;
 		exit(1);
 	  }
    string line, word,ed;
    string b[10000];
    int linecounter=0;
	  while ( getline(fin, line) ) {
        b[linecounter]=line;
        istringstream line_in(line);
        int id;
	      line_in >> id;
        if(id==ID){
            b[linecounter]="";
            int counter=0;
            int choice;
            cout<<"Edit\n(1.date 2.IO 3.type 4.account 5.amount 6.remark)"<<endl;
            cin>>choice>>endl;
            count<<"Enter the edited value"<<endl;
            cin>>ed>>endl;
            string a[100];
            while(line_in>>word){
            counter++
            a[counter]=word;
            if(counter == choice){
            a[counter]=ed;
            }
            }
            for(int i=0;i<=6;i++){
            b[linecounter]=b[linecounter]+a[i]+" ";
            }
        }
       linecounter++;
   }
	  fin.close();
    ofstream fout;
    fout.open("records.txt");
    if ( fout.fail() ) {
      cout << "Error in file opening!"<< endl;
      exit(1);
   }
    for(int i=0;i<linecounter;i++){
    fout <<b[i]<<endl;
    }
    fout.close();
}
