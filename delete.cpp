#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include"Record.h"
using namespace std;
void deleteline(int ID){
    cin>>ID;
    cout<<endl;
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
