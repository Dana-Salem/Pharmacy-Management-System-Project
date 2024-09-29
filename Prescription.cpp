#include<iostream>
#include"Medication.h"
#include"Date.h"
#include"Prescription.h"
using namespace std;

Prescription::Prescription():Medication("No Name", "No description", Date(1, 1, 2023), "000000000000", 0, 0), ApprovalDate(Date(1, 1, 2023)){
	FDANumber = 00000;
}
Prescription::Prescription(int FDANum, Date& ApprovalDate_, string n, string d, Date& e, string b, double p, int q) :Medication(n, d, e, b, p, q), ApprovalDate(ApprovalDate_) {
	set_FDANumber(FDANum);
}
void Prescription::set_FDANumber(int FDANum) {
	if (FDANum < 0) {
		FDANumber = 0;
		cout << "Invalid prescription FDA number entered, set to default." << endl;
	}
	else FDANumber = FDANum;
}
void Prescription::set_ApprovalDate(Date& ApprovalDate_) {
	ApprovalDate.setDay(ApprovalDate_.getDay());
	ApprovalDate.setMonth(ApprovalDate_.getMonth());
	ApprovalDate.setDay(ApprovalDate_.getYear());
}
int Prescription::get_FDANumber()const{
	return FDANumber;
}
Date Prescription::get_ApprovalDate()const{
	return ApprovalDate;
}
void Prescription::print()const {
	Medication::print();
	cout << "FDANumber: " << FDANumber << endl;
	cout << "ApprovalDate: " << endl;
	ApprovalDate.print();
	cout << endl;
}












