#pragma once
#include<iostream>
#include "Date.h"
using namespace std;

class Medication
{
public:
	Medication();
	Medication(const Medication& obj);
	Medication(string, string, Date, string, double, int);
	~Medication();

	void set_name(string);
	void set_description(string);
	void set_exp_date(Date&);
	void set_price(double);
	void set_quantity(int);
	void set_barcode(string);

	string get_name() const;
	string get_description() const;
	Date get_exp_date() const;
	double get_price() const;
	int get_quantity() const;
	string get_barcode() const;
	int get_id() const;

	void print() const;


private:
	int id;
	static int idCount;
	string name, description, barcode;
	double price;
	int quantity;
	Date exp_date;

};