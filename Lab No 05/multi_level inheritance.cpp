#include<iostream>
using namespace std;

class Person{
	public:
	string name;
	int age;
//	function
void display_person(){
	cout<<"The person name is: "<<name<<endl;
    cout<<"The age of person is: "<<age<<endl;
}
};
class Employee : public Person{
	public:
	int employee_Id;
	
void display_employee(){
	display_person();	
   	cout<<"The  employee_Id is:  "<<employee_Id<<endl;
	}};
	class Manager : public Employee{
	public:
	string department;
	
void display_manager(){
	 display_employee();	
   	cout<<"The department of employee:  "<<department<<endl;
	}	
};

int main(){
Manager m;
m.name="Ammar Yasir";
m.age=19;
m.employee_Id=51214;
m.department="softwar Emgineering";
m.display_manager();
	
}
