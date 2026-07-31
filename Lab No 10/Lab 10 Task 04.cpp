#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream File;
	File.open("student.txt");
	File<<"Name: Ammar ,Roll No:38"<<endl;
	File<<"Name:Yasir  ,Roll No:37"<<endl;
	File<<"Name:Qadree ,Roll No:36"<<endl;
	File.close();
	ifstream readFile("student.txt");
	string line;
	while(getline(readFile,line)){
		cout<<line<<endl;
	}
	readFile.close();
}
