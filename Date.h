#pragma once
#include<iostream>
using namespace std;

class Date {
private:
	int Day, Month, Year;
public:
	Date(int d=1, int  m=1, int y=2023);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay() const;
	int getYear() const;
	int getMonth() const;
	void print() const;
	

};
