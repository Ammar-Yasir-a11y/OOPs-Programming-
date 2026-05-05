#include<iostream>
using namespace std;
//	Task NO 01
struct student{

//	Data member
string frist_name;
string second_name;
int Roll_NO;
float marks;
//member function
void dispalySudentInfo(){
	cout<<"full name :"<<frist_name<<"  "<<second_name<<endl;
	cout<<"the marks :"<<marks;
}
};
int main(){
	student s;
	//	Task NO 02
int n;
cout<<"enter the number of student :"<<endl;
cin>>n;
//student student
    s.frist_name="Ammar";
    s.second_name="Yasir";
    s.Roll_NO=12;
    s.marks=89;
   	s.dispalySudentInfo();
}
