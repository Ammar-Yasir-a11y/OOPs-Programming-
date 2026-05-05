#include<iostream>
using namespace std;

class Employee{
	private:
	string name;
	int salary;	
	public:
	void setEmployee(string n,int s){
		name=n;
		salary=s;
	}
	void Display_employee(){
	cout<<"The name is = "<<name<<endl;
	cout<<"The salary is = "<<salary<<endl;
	}
};
class Developer:public Employee{
	private:
	string programming_language;
	public:
	void setDeveloper(string n,int s,string lang){
	           setEmployee(n,s);
	          programming_language=lang;
	}	
	void display_developer(){
		Display_employee();
		cout<<"Programming language IS = "<<programming_language<<endl<<endl;
	}	
};
class Designer:public Employee{
	private:
	string design_tool;
	public:
	void setDesigner(string n,int s,string tool){
	           setEmployee(n,s);
	           design_tool=tool ;
	}	
	void display_designer(){
		Display_employee();
		cout<<" Design tool is = "<<design_tool<<endl;
	}	
};
int main(){
	Developer dev;
	Designer  des;
	dev.setDeveloper("Yasir",40000,"c++");
	des.setDesigner("muhadesa",50000,"photoshop");
	cout<<"The developer info "<<endl;
	dev.display_developer();
	cout<<"The designer info "<<endl;
	des.display_designer();
}
