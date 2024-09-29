#include<iostream>
#include<string>
#include"Customer.h"
using namespace std;

int Customer::NumOfCustomers = 0;
 
Customer::Customer() :CustomerID(++NumOfCustomers) {
	setCustomerName("No name");
	address.setCity("unknown");
	address.setEmail("xoxo@gmail.com");
	address.setMobileNO("+962xxxxxxxxx");
	address.setStreetName("unknown");
}

Customer::Customer(string n, Address ad) :CustomerID(++NumOfCustomers), address(ad){
	setCustomerName(n);
}

Customer::Customer(const Customer& obj) :CustomerID(obj.CustomerID),address(obj.address) {
	CustomerName = obj.CustomerName;
}
Customer::~Customer() {};

void Customer::setCustomerName(string n) {
	if (n == " ") {
		CustomerName = "No name";
		cout << "Invalid customer name, set to default." << endl;
	}
	else
	CustomerName = n;
}
void Customer::setAddress(Address &ad) {
	address = ad;
}
string Customer::getCustomerName()  const {
	return CustomerName;
}
Address Customer::getAddress() const {
	return address;
}
int Customer::getID() const {
	return CustomerID;
}
void Customer::DisplayInfo()const {
	cout << "Customer Name : " << CustomerName << endl;
	cout << "Customer ID : " << CustomerID << endl;
	cout << "Address : " << endl;
	address.print();
}