#pragma once
#include<iostream>
#include<string>
#include "Address.h"
using namespace std;

class Customer {
private:
	string CustomerName;
	int CustomerID;
	Address address;
	static int NumOfCustomers;
public:
	Customer();
	Customer(string n, Address ad);
	Customer(const Customer& obj);
	~Customer();
	void setCustomerName(string n);
	void setAddress(Address &ad);
	string getCustomerName()const;
	Address getAddress()const;
	int getID() const;
	void DisplayInfo()const;
};
