#include<iostream>
using namespace std;
#include "Date.h"

Date::Date(int d, int  m, int y) {
	setDay(d);
	setMonth(m);
	setYear(y);

}
void Date:: setDay(int d) {
	if (d >= 1 && d <= 31) {
		Day = d;
	}
	else {
		Day = 1;
		cout << "Invalid day entered, set to default." << endl;
	}
}
void  Date::setMonth(int m){
	if (m >= 1 && m <= 12) {
		Month = m;
	}
	else {
		Month = 1;
		cout << "Invalid month entered, set to default." << endl;
	}
}
void  Date::setYear(int y) {
	if (y >= 2000) {
		Year = y;
	}
	else {
		Year = 2000;
		cout << "Invalid year entered, set to default." << endl;
	}
}
int   Date::getDay() const { return Day; }
int  Date::getMonth() const { return Month; }
int  Date::getYear() const { return Year; }

void  Date::print() const { cout << Day << "-" << Month << "-" << Year; }