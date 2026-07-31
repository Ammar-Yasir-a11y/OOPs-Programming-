#include<iostream>
using namespace std;
class Distance{
	private:
	int feet;
	int inches;
	public:
	Distance(int f,int i){
		feet=f;
		inches=i;
	}
	friend void addDistance(Distance d,Distance d1);
};
void addDistance(Distance d,Distance d1){
	int feet= d.feet+d1.feet;
	int inches=d.inches+d1.inches;
	if(inches>=12){
		feet++;
		inches-=12;
		cout<<feet<<"-feet; "<<inches<<"-inches ";
	}
}
int main(){
	Distance d(2,4);
	Distance d1(6,12);
	addDistance(d,d1);
	return 0;
	
}
