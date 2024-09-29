#include<iostream>
#include"Medication.h"
#include"Date.h"
using namespace std;
class Prescription:public Medication {
	int FDANumber;
	Date ApprovalDate;
public:
	Prescription();
	Prescription(int FDANum,Date & ApprovalDate_, string n, string d, Date& e, string b, double p, int q);

	void set_FDANumber(int FDANum);
	void set_ApprovalDate(Date &ApprovalDate_);

	int get_FDANumber()const;
	Date get_ApprovalDate()const;

	void print()const;
};