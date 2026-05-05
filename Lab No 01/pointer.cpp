#include<iostream>
using namespace std;

struct student{
//	Data member 
	string frist_name;
	string second_name;
	int roll_no;
	float marks;
//  function	
	void  displayStudentInfo(){
		cout<<"full Name= "<<frist_name<<" "<<second_name<<endl;
		cout<<"marks of student: "<<marks<<endl<<"***********"<<endl;
	}
	};
int main(){
student std,*ptr;
ptr=&std;
	cout<<"Enter the frist name\n";
	cin>>ptr->frist_name;
	cout<<"Enter the second name\n";
	cin>>ptr->second_name;
	cout<<"Enter the roll \n";
	cin>>ptr->roll_no;
	cout<<"Enter the marks \n";
	cin>>ptr->marks;

	ptr->displayStudentInfo();
}
