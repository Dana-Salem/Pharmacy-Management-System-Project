#pragma once
#pragma once
#include<iostream>
#include "Medication.h"
#include "Customer.h"
#include "Prescription.h"
#include "OffTheShelf.h"
using namespace std;

class Pharmacy {
	int id;
	static int count_id;
	string name;
	int count_med;
	int count_cust;
	int count_off;
	int count_pres;
	Medication* med;
	Customer* cust;
	OffTheShelf* off;
	Prescription* pres;

public:
	Pharmacy();
	Pharmacy(string n);
	Pharmacy(Pharmacy& ph_obj);
	~Pharmacy();
	void Add_medication(Medication med_obj);
	void Add_Prescription(Prescription pres_obj);
	void Add_OffTheShelf(OffTheShelf off_obj);
	void Remove_medication(int Id, int type);
	void Remove_medication(string n, int type);
	void Add_Customer(Customer cust_obj);
	void av_med()const;
	void print_cust()const;

	void set_id(int i);
	int get_id();

	void set_name(string n);
	string get_name()const;

	Medication get_med(int i)const;
	Customer get_cust(int i)const;
	Prescription get_pres(int i)const;
	OffTheShelf get_off(int i)const;
	void set_cust(Customer o, int i);
	void set_pres(Prescription o, int i);
	void set_off(OffTheShelf o, int i);
	void set_med(Medication o, int i);

	int num_of_med()const;
	int num_of_cust()const;
	int num_of_off()const;
	int num_of_pres()const;
	void set_med_count(int n);
	void set_cust_count(int n);
	void set_off_count(int n);
	void set_pres_count(int n);
	double total_cash()const;
	void DisplayInfo()const;


};