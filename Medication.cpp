
#include <iostream>
#include <algorithm>
#include "Date.h"
#include "Medication.h"
using namespace std;
int Medication::idCount = 0;
Medication::Medication() : id(idCount++){
	name = "No Name";
	description = "No description";
	exp_date = Date(1,1,2023);
	barcode = "000000000000";
	price = 0;
	quantity = 0;
}
Medication::Medication(const Medication& obj) : id(obj.id) {
	name = obj.name;
	description = obj.description;
	exp_date = obj.exp_date;
	barcode = obj.barcode;
	price = obj.price;
	quantity = obj.quantity;
}
Medication::Medication(string n, string d, Date e, string b, double p, int q) : exp_date(e), id(idCount++){
	name = n;
	description = d;
	barcode = b;
	price = p;
	quantity = q;
}
Medication::~Medication() {}

// Setters
void Medication::set_name(string n) {
	if (n != "") name = n;
	else {
		name = "No Name";
		cout << "Invalid medication name, set to default" << endl;
	}
}
void Medication::set_description(string d) {
	if (d != "") description = d;
	else {
		description = "No description";
		cout << "Invalid medication description, set to default" << endl;
	}
}
void Medication::set_exp_date(Date &e) {
	exp_date = e;
}
void Medication::set_price(double p) {
	if (p >= 0) price = p;
	else {
		price = 0;
		cout << "Invalid medication price, set to default" << endl;
	}
}
void Medication::set_quantity(int q) {
	if (q >= 0) quantity = q;
	else {
		quantity = 0;
		cout << "Invalid medication quantity, set to default" << endl;
	}
}
void Medication::set_barcode(string b) {
	if (b.length() == 12) barcode = b; // Barcode length should be 12
	else {
		barcode = "000000000000";
		cout << "Invalid medication barcode, set to default" << endl;
	}
}

// Getters
string Medication::get_name() const {
	return name;
}
string Medication::get_description() const {
	return description;
}
Date Medication::get_exp_date() const {
	return exp_date;
}
double Medication::get_price() const {
	return price;
}

string Medication::get_barcode() const {
	return barcode;
}

int Medication::get_quantity() const {
	return quantity;
}

int Medication::get_id() const {
	return id;
}

void Medication::print() const {
	cout << "Medication name: " << name << "\nDescription: " << description << "\nPrice: " << price << "\nQuantity in stock: " << quantity << "\nExpiry Date: ";
	exp_date.print();
	cout << "\nBarcode: " << barcode << endl;
}
