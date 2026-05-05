#include<iostream>
using namespace std;

class Rectangle{
//	attributes
public:
 int length;
 int width;

void setDimension();
void area();
void parameter();

};
void Rectangle::setDimension(){
	cout<<"enter the length:";
	cin>>length;
	cout<<"enter the width";
	cin>>width;
}
void Rectangle::area(){
	int area;
	area=length+width;
	cout<<"the total area is:"<<area;
	
	
}
void Rectangle::parameter(){
	float parameter;
	parameter=2*(length*width);
	cout<<parameter;
}
int main(){
	Rectangle R;
	R.setDimension();
    R.area();
}
	
