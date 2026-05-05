#include<iostream>
using namespace std;

class Printer{
	public:
	void print_document(){
    cout<<"document printing..."<<endl;
	}
	};
class Scanner{
	public:
	void sanc_document(){
	cout<<"document scanning..."<<endl;	
	}	
};
class Photocopier:public Printer,public Scanner{
	public:
	void photocopy(){
	print_document();
	sanc_document();	
	}
};
int main(){
	Photocopier p;
	p.photocopy();
}
