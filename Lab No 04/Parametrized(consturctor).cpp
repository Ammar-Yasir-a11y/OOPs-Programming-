#include<iostream>
using namespace std;

class BankAccount{
	private:
string acccountNumber;
string accountHolder;
double balance;
	public:
 BankAccount(string accNum,string accHol,double bal){
 	acccountNumber=accNum;
 	accountHolder=accHol;
 	balance=bal;
 }	
 

void showAccountDetails(){
	cout<<"The account number is ="<<acccountNumber<<endl;
	cout<<"The account holder is = "<<accountHolder<<endl;
	cout<<"The balance is ="<<	balance;
}
};
int main(){
	BankAccount obj("PK0309800780100","Muhammad Awis",10000);
	obj.showAccountDetails();
}
