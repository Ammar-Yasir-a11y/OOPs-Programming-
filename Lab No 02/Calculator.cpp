#include<iostream>
using namespace std;

class Calculator{
//	attributes
public:
float num1;
float num2;
//function or method
float add();
double subtract();
double multiply();
double divide();
};

float Calculator::add(){
	return num1+num2;
}
	
double Calculator::subtract(){
	return  num1-num2;
}
double Calculator::multiply(){
return num1*num2;
}
double Calculator:: divide(){
return num1/num2;
}
int main(){
Calculator cal;
cout<<"enter the values:"<<endl;
cin>>cal.num1>>cal.num2;
char op;
cout<<"enter the operator: ";
cin>>op;
switch(op)	{
	case'+':
	cout<<"num1:"<<cal.num1<<"  num2:"<<cal.num2<<endl; 
	cout<<"the sum of these number is :"<<cal.add();
	break;	
	case'-':
	cout<<"num1:"<<cal.num1<<"  num2:"<<cal.num2<<endl; 
	cout<<"the subtraction of these number is :"<<cal.subtract();
	break;	
	case'*':
    cout<<"num1:"<<cal.num1<<"  num2:"<<cal.num2<<endl; 
	cout<<"the multiply of these number is :"<<cal.multiply();
	break;
	case'/':
    cout<<"num1:"<<cal.num1<<"  num2:"<<cal.num2<<endl; 
	cout<<"the  divition of these number is :"<<cal.divide(); 
	break;	
	default:
		cout<<"invalid operator";
}
}
