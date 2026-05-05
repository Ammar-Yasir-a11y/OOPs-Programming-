#include<iostream>
using namespace std;

class Student{
//	attributes
public:
string name;
int Roll_No;
float marks;
//function
void getData(){
	cout<<"Enter your name:";
	cin>>name;
	cout<<"roll no:";
	cin>>Roll_No;
	cout<<"marks is:";
	cin>>marks;
}
void displayData(){
	cout<<"Name is ="<<name<<endl;;
	cout<<"Roll no is="<<Roll_No<<endl;;
	cout<<"Marks is ="<<marks<<endl;;

}
};
int main(){
	Student s;
	s.getData();
	s.displayData();
	return 0;
}
