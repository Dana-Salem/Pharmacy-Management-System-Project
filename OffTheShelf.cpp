#include<iostream>
#include <ctime>
#include"Medication.h"
#include"Date.h"
#include"OffTheShelf.h"
using namespace std;

OffTheShelf::OffTheShelf() :Medication("No Name", "No description", Date(1, 1, 2023), "000000000000", 0.0,0) {
	BOGOF = false;

	struct tm aTime;
	time_t now = time(0);
	localtime_s(&aTime, &now);

	int day = aTime.tm_mday;
	int month = aTime.tm_mon + 1; 
	int year = aTime.tm_year + 1900;
	OfferEnds = Date(day, month, year+2);
	
}
OffTheShelf::OffTheShelf(bool bogof, string n, string d, Date& e, string b, double p, int q) : Medication(n, d, e, b, p, q) {
	BOGOF = bogof;
	struct tm aTime;
	time_t now = time(0);
	localtime_s(&aTime, &now);

	int day = aTime.tm_mday;
	int month = aTime.tm_mon + 1;
	int year = aTime.tm_year + 1900;
	if (BOGOF) {
		if (month + 3 > 12) {
			month = (month + 3) - 12;
			year++;
		}
		else {
			month += 3;
		}
		OfferEnds = Date(day, month, year);
	}
	else {
		OfferEnds = Date(day, month, year+2);
	}
}
void OffTheShelf::set_BOGOF(bool bogof) {
	BOGOF = bogof;
}
void OffTheShelf::set_OfferEnds(Date& OfferEnds_) {
	OfferEnds.setDay(OfferEnds_.getDay());
	OfferEnds.setMonth(OfferEnds_.getMonth());
	OfferEnds.setYear(OfferEnds_.getYear());
}
bool OffTheShelf::get_BOGOF()const {
	return BOGOF;

}
Date OffTheShelf::get_OfferEnds()const {
	return OfferEnds;
}
void OffTheShelf::print()const {
	Medication::print();
	if (BOGOF==true)
		cout << "Yes BOGOF"<< endl;
	else
		cout << "No BOGOF" << endl;
	cout << "OfferEnds: \n";
	OfferEnds.print();
	cout << endl;
}

