#include<iostream>
#include<string>
#include"Product.h"
int main(){
	Product P1;
	
	P1.setName(""); // Should print error message
	P1.setPrice(-50);// Should print error message
	P1.setQuantity(-2);// Should print error message
	
	P1.setName("Laptop");
	P1.setPrice(1200.50);
	P1.setQuantity(5);
	
	cout<< "Product: "<<P1.getName()<<endl;
	cout<< "Price: "<<P1.getPrice()<<endl;
	cout<< "Quantity: "<<P1.getQuantity()<<endl;
	return 0;
}
