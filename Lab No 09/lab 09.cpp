#include<iostream>
using namespace std;
class Distance{
	private:
	double feet;
	double inches;
	public:
	Distance(double feet,double inches){
		this->feet=feet;
		this->inches=inches;
	}
	bool operator ==(Distance d){
		return (feet==d.feet&&inches==d.inches);
	}
};
int main(){
	Distance d1(5,6);
	Distance d2(5,6);
	Distance d3(5,8);
	if(d1==d2){
		cout<<"d1 and d2 are equal"<<endl;
	}else{
		cout<<"d1 and d2 are not equal"<<endl;
	} if (d1 == d3)
        cout << "d1 and d3 are equal" << endl;
    else
        cout << "d1 and d3 are not equal" << endl;

    return 0;
}
