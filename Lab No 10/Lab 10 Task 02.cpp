#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream File;
	string line;
	File.open("notes.txt");
	int count=0;
	while(getline(File,line)){
		count++;
	}
		File.close();
		cout<<"TOTAL number of line is = "<<count;
}
