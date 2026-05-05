#include<iostream>
using namespace std;

class Rectangle{
	private:
float length;
float width;
	public:
	Rectangle(){
	length=1.0;
    width=1.0;
}
	Rectangle(float leng,float wid){
	length=leng;
    width=wid;
}
	Rectangle(float both){
	length=both;
    width=both;
}
float arae(){
	float area;
	area=length*width;
	return area;
}

void display(){
	cout<<"The length of rectangle is ="<<length<<endl;
	cout<<"The width of reactangle is = "<<width<<endl;

}
};
int main(){
Rectangle R1;
Rectangle R2(3.5,4.6);
Rectangle R3(12.9);
R1.display();
R2.display();
R3.display();
}
