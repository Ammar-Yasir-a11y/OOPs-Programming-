#include<iostream>
using namespace std;
class Employee{
	private:
	int employeeId;
	string Name;
	public:
	static string companyName;
	Employee(int id,string name){
		employeeId=id;
		 Name=name;
	}
	void Display(){
		cout<<"EmployeeId "<<employeeId<<endl;
		cout<<"Name "<<Name<<endl;
	}
	static void displayCompany(){
		cout<<"Company Name "<<companyName<<endl;
	}};
	string Employee::companyName="Qadree Software House";
	int main(){
		Employee e(101,"Yasir");
		Employee e1(102,"Muhadisa");
		
		e.Display();
		e1.Display();
		Employee::displayCompany();
	}
