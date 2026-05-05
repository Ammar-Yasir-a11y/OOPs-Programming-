#include<iostream>
using namespace std;

class Employee{
	private:
	int id;
	string name;
	float salary;
	public:
	Employee(){
	id=0;
	name="Ammar Yasir";
	salary=0.0;
}
void displayDetails(){
	cout<<"The employee name is ="<<name<<endl;
	cout<<"The employee id is = "<<id<<endl;
	cout<<"The employee salary is ="<<salary;
}
};
int main(){
	Employee e;
	e.displayDetails();
}
