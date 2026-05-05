#include<iostream>
using namespace std;

class Voter{
//	properties
public:
string name;
int age;
//function
bool isEligible();
};
 bool Voter::isEligible(){
if(age>18){
	return true;
	}else{
	return false;
	}
}
int main(){
	Voter v;
	cout<<"enter the name:"<<endl;
	cin>>v.name;
	cout<<"enter the age:"<<endl;
	cin>>v.age;
    v.isEligible();	
	if(v.isEligible()){
		cout<<v.name<<" is eligible to vote";
	}else{
		cout<<v.name<<" is not eligible to vote";
	}
	

}
