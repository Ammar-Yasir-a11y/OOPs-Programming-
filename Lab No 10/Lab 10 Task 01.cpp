#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream outFile;
	outFile.open("notes.txt");
	outFile<<"The first line code"<<endl;
	outFile<<"The second line code"<<endl;
	outFile<<"The third line code"<<endl;
	outFile.close();
	ifstream inFile("notes.txt");
	string line;
	while(getline(inFile,line)){
		cout<<line<<endl;
	}
	inFile.close();
	ofstream 
	appendFile("notes.txt" ,ios::app);
	appendFile<<"Name: Ammar Yasir"<<endl;
    appendFile<<"Roll NO:2025-SE-38"<<endl;
    appendFile.close();
}
