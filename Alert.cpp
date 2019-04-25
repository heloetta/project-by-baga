#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Alert.h"
using namespace std;
void alert(){
    cout<<"Set your budget"<<endl;
    int max;
    cin>>max;
    cout<<endl;
    string filename = "records.txt"
    ifstream fin( filename.c_str() );
    if ( fin.fail() ){
		cout << "Error in file opening!" << endl;
 		exit(1);
 	}
    string line;
    int sum=0;
    while(getline(fin,line)){
		istringstream iss(line);
		Record FinRecord;
		iss>>FinRecord.ID>>FinRecord.date>>FinRecord.IO>>FinRecord.type>>FinRecord.account>>FinRecord.amount>>FinRecord.remark;
    if(FinRecord.IO==0){
    sum-=FinRecord.amount;
    }
    if(FinRecord.IO==1){
    sum+=FinRecord.amount;
    }
   }
    fin.close();
    if(sum>=max){
    cout<<"expense out of range for "<<sum-max<<endl;
    }   
}
