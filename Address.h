#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Address {
	string Email;
	string City;
	string MobileNO;
	string StreetName;
public:
	Address(string email = "xoxo@gmail.com", string city = "unknown", string mobile = "+962xxxxxxxxx", string street = "unknown");
	void setEmail(string email);
	void setCity(string city);
	void setMobileNO(string mobile);
	void setStreetName(string street);
	string getEmail() const;
	string getCity() const;
	string getMobileNo() const;
	string getStreetName() const;
	void print() const;

};