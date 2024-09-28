#include<iostream>
#include<string.h>
using namespace std;
#include"Address.h"

Address::Address(string email, string city, string mobile, string street) {
    setEmail(email);
    setCity(city);
    setMobileNO(mobile);
    setStreetName(street);
}
void Address::setEmail(string email) {
    if (email == " ") {
        Email = "xoxo@gmail.com";
        cout << "Invalid customer email, set to default." << endl;
    }
    else {
        Email = email;
    }
}
void Address::setCity(string city){
    if (city == " ") {
        City = "unknown";
        cout << "Invalid customer city, set to default." << endl;
    }
    else {
        City = city;
    }
}
void Address::setMobileNO(string mobile){ 
    if (mobile == "") {
        MobileNO = "+962xxxxxxxxx";
        cout << "Invalid customer mobile no, set to default." << endl;
    }
    MobileNO = mobile;
}
void  Address::setStreetName(string street){
    if (street == " ") {
        StreetName = "unknown";
        cout << "Invalid customer street name, set to default." << endl;
    }
    StreetName = street;
}
string Address::getEmail() const { return Email; }
string  Address::getCity() const { return City; }
string Address::getMobileNo() const { return  MobileNO; }
string Address::getStreetName() const {return StreetName;}
void  Address::print() const { cout <<"Email: "<< Email << endl;
                        cout <<"City:"<< City << endl;
                        cout << "MobileNO:" << MobileNO << endl;
                        cout << "StreetName:" << StreetName << endl;
                        

}
