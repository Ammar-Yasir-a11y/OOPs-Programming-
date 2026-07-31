#include<iostream>
using namespace std;
class HospitalStaff {
	protected:
     string name;
     public:
    HospitalStaff (string n){
    	name=n;
	}
     virtual void PerformDuty();
};
class Doctor:public HospitalStaff{
	public:
	Doctor(string n):HospitalStaff(n){}
	void PerformDuty(){
		cout<<name<< "treats a patients"<<endl;
	}
};
class Nurse:public HospitalStaff{
	public:
    Nurse(string n):HospitalStaff(n){}
	void PerformDuty(){
		cout<<name<< "gives medicine "<<endl;
	}
};
class Receptionist:public HospitalStaff{
	public:
	 Receptionist(string n):HospitalStaff(n){
	}
	void PerformDuty(){
		cout<<name<< "manages appointments"<<endl;
	}	
};
int main(){
	Doctor d("Dr.Yasir");
	Nurse  n("Fatima");
	Receptionist r("Raza");
	
	d.PerformDuty();
	n.PerformDuty();
	r.PerformDuty();
}

