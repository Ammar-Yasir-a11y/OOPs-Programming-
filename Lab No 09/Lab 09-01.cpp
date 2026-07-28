#include<iostream>
using namespace std;
class Employees{
	public:
	virtual double CalculateSalary(){
		cout<<"Basic Employees salary calculation called "<<endl;
	}

};
class PermanentEmployee:public Employees{
	private:
	double basicsalary;
	double bonus;
	public:
	PermanentEmployee(double bs,double b){
	basicsalary=bs;
	bonus=b;
	}
	double  CalculateSalary() override{
	return basicsalary+bonus;
	}
};
class ContractEmployee:public Employees{
    private:
    double hourlyrate;
    double hourWorked;
    public:
    ContractEmployee(double hr,double hw){
    	hourlyrate=hr;
    	hourWorked=hw;
	}
    double CalculateSalary()override{
	return hourlyrate+hourWorked;
	}
};
int main(){
	Employees *emp;
	PermanentEmployee p(4000,500);
	ContractEmployee  c(1000,8);
	emp=&p;
	cout<<"calculatesalary of premanentEmployee is  "<<emp-> CalculateSalary()<<endl;
	emp=&c;
	cout<<"calculatesalary of contractEmployee is  "<<emp-> CalculateSalary()<<endl;
}
