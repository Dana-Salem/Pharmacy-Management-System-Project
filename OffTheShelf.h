#include<iostream>
#include"Medication.h"
#include"Date.h"
using namespace std;
class OffTheShelf :public Medication {
	bool BOGOF;
	Date OfferEnds;
public:
	OffTheShelf();
	OffTheShelf(bool bogof, string n, string d, Date& e, string b, double p, int q);

	void set_BOGOF(bool bogof);
	void set_OfferEnds(Date& OfferEnds_);

	bool get_BOGOF()const;
	Date get_OfferEnds()const;

	void print()const;
};