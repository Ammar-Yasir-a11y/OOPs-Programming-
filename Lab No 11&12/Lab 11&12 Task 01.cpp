#include<iostream>
using namespace std;
class Box{
	double length;
	public:
	Box(double l){
		length=l;
	}
	friend void displayLength(Box b);	
};
void displayLength(Box b){
	cout<<"Length = "<<b.length<<endl;
	
}

int main(){
	Box b(12);
	displayLength(b);
}
