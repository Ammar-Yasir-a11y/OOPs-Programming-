#include<iostream>
using namespace std;

class Temperature{
//	attributes
public:
double Celsius,	fahrenheit;

//function
double covertor(){
	cout<<"Enter the temperature in celsius"<<endl;
	cin>>Celsius;
	fahrenheit=(Celsius*9/5)+32;
}
void Disply(){
	cout<<"converted tmperature in fahrenhit is: "<<fahrenheit;
}
};
int main(){
	Temperature t;
	t.covertor();
	t.Disply();
}
