#include<iostream>
using namespace std;
class Bankaccount{
	private:
	string Name;
	double balance;
	public:
	static int totalAccount;
	Bankaccount(string n,int b){
		Name=n;
		balance=b;
		totalAccount++;
	}
	void display(){
		cout<<"Name:"<<Name<<endl;
		cout<<"Balance:"<<balance<<endl;
	}};
		int Bankaccount::totalAccount=0;
		int main(){
		Bankaccount a("Ammar",1000);
		Bankaccount b("Muhadissa",2000);
		Bankaccount c("Fatima",2000);
		cout<<"total account "<<Bankaccount::totalAccount<<endl;		}
