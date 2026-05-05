#include<iostream>
using namespace std;

class Person{
	public:
	string name;
	int age;
//	function
display_person_info(){
	cout<<"The person name is: "<<name<<endl;
    cout<<"The age of person is: "<<age<<endl;
}
};
class student : public Person{
	public:
	int student_Id;
	
    display_student_info(){	
   	cout<<"The student student_id:  "<<student_Id<<endl;
	}
		
};

int main(){
	student s;
	cout<<"Enter the Name"<<endl;
	cin>>s.name;
	cout<<"Enter the age"<<endl;
    cin>>s.age;
	cout<<"Enter the student id"<<endl;
	cin>>s.student_Id;
	s.display_person_info();
	s.display_student_info();
	
	
}
