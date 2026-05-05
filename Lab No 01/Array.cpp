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
		cout<<"marks of student "<<marks<<endl<<"***********"<<endl;
	}
	};
int main(){
student std[2];
for(int i=0;i<2;i++){
	cout<<"Enter the frist name\n";
	cin>>std[i].frist_name;
	cout<<"Enter the second name\n";
	cin>>std[i].second_name;
	cout<<"Enter the roll \n";
	cin>>std[i].roll_no;
	cout<<"Enter the marks \n";
	cin>>std[i].marks;
}for(int i=0;i<2;i++){
	std[i].displayStudentInfo();
}

}
	
