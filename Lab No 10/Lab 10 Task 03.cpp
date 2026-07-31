#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream file("notes.txt");
	string line;
	int count=0;
	while(getline(file,line)){
		count++;
	}
	cout<<"The total number of line is = "<<count;
}
