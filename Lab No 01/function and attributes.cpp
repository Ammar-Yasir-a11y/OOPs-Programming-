#include<iostream>
using namespace std;

struct student{
//	data member
	string frist_name;
	string second_name;
	int roll_no;
	float marks;
	
	void  displayStudentInfo(){
		cout<<"full Name= "<<frist_name<<" "<<second_name<<endl;
		cout<<"marks of student: "<<marks<<endl;
	}
	};
int main(){
	student s;
	s.frist_name="Ammar";
	s.second_name="Yasir";
	s.marks=70;
	s.roll_no=38;
	
	s.displayStudentInfo();

}
	
