 #include<iostream>
 using namespace std;
 
 class Product{
 	private:
 	string name;
	double price;
	int quantity;
	public:
	void setName(string n){
	if(!n.empty()){
		name=n;
	}else{
	cout<<"Invalid! name.Name can not be empty."<<endl;
	}
	}	
	void setPrice(double p){
	if(p>0){
		price=p;
	}else{
	cout<<"Invalid! price. price must be greater than 0."<<endl;
	}
	}
	void setQuantity(int q){
		if(q>0){
	   quantity=q;
	}else{
	cout<<"Invalid! quantity. quantity must be gerater than zero."<<endl;
	}
	}
	 
	string getName(){
      return name;
	}	
	double getPrice(){
	 return price;
	}
	 int getQuantity(){
	 return quantity;
	}
	
 };
