#include<iostream>
using namespace std;

class Locker{
	public:
	Locker(){
    cout<<"Locker allocated to custmer"<<endl;
}
	~Locker(){
    cout<<"Locker returned by custmer"<<endl;
}

};
int main(){
Locker l;
Locker* l1 =new Locker();
delete l1;
return 0;

}
