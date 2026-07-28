#include<iostream>
using namespace std;
class Shape{
	public:
	virtual double area(){
		cout<<"The area of the shape "<<endl;
	} 
};
class Ractangle: public Shape{
	public:
	double length=2;
	double width=3;
	
	double area()override {
		double area;
		area=2*(length*width);
		cout<<"the area of the rectangle is = "<<area<<endl;
	}

};
class Circle: public Shape{
	public:
	double r=12;
	double pie=3.14;
	
	double area()override {
		double area;
		area=2*(pie*r*r);
		cout<<"the area of circle is = "<<area;
	}
};

int main(){
Ractangle r;
r.area();
Circle c;
c.area();
}
