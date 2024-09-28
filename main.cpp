

#include<iostream>
#include "Customer.h"
#include "Medication.h"
#include "Pharmacy.h"
#include "Date.h"
#include "Address.h"
#include <string>
#include <algorithm>
using namespace std;

int resizePharma(Pharmacy* &pharma, int &prevsize) {
	cout << "What do you want the max amount of pharmacies to be?\n";
	int size; cin >> size;
	if (pharma == nullptr) pharma = new Pharmacy[size];
	else {
		Pharmacy* temp = new Pharmacy[size];
		for (int i = 0; i < min(size, prevsize); i++) { // We used min function to find the minimum between size and previous size, to handle the case that the new size is less than previous size
			temp[i].set_id(pharma[i].get_id());
			temp[i].set_name(pharma[i].get_name());
			temp[i].set_med_count(pharma[i].num_of_med());
			temp[i].set_cust_count(pharma[i].num_of_cust());
			temp[i].set_off_count(pharma[i].num_of_off());
			temp[i].set_pres_count(pharma[i].num_of_pres());
			for (int i = 0; i < pharma[i].num_of_cust(); i++) {
				temp[i].set_cust(pharma[i].get_cust(i),i);
			}
			for (int i = 0; i < pharma[i].num_of_med(); i++) {
				temp[i].set_med(pharma[i].get_med(i), i);
			}
			for (int i = 0; i < pharma[i].num_of_off(); i++) {
				temp[i].set_off(pharma[i].get_off(i), i);
			}
			for (int i = 0; i < pharma[i].num_of_pres(); i++) {
				temp[i].set_pres(pharma[i].get_pres(i), i);
			}
		}
		prevsize = min(size, prevsize);
		delete[] pharma;
		pharma = temp;
	}
	return size;
}

void addPharmacy(Pharmacy* &pharma, int &pharmCount, int max) {
	if (pharmCount == max) {
		char c;
		cout << "The maximum number of pharmacies has been reached. Do you want to increase the max number of pharmacies? (Enter Y or N)" << endl;
		cin >> c;
		if (c == 'Y' || c == 'y') {
			resizePharma(pharma, pharmCount);
		}
		else {
			return;
		}
	}
	string name;
	cout << "Enter pharmacy name:\n";
	cin >> name;
	pharma[pharmCount++].set_name(name);
}

void addMedication(Pharmacy* &pharma, int pharmCount) {
	int id;
	cout << "Enter pharmacy id:\n";
	cin >> id;
	if (id < 0 || id >= pharmCount) {
		cout << "Invalid pharmacy id" << endl;
		return;
	}
	int type;
	string n, description, barcode;
	int day, month, year;
	double price;
	int quantity;
	cout << "Please enter the type of medicine:\n- 1 for Medication\n- 2 for Off The Shelf\n- 3 for Prescription\n";
	cin >> type;
	cout << "Please enter Medicine Name\n";
	cin >> n;

	cout << "Please enter Medicine Expiry day, month, year\n";
	cin >> day >> month >> year;

	cout << "Please enter Medicine Description\n";
	cin.ignore(); // To ignore any previous new lines from output above
	getline(cin, description); // To read a full line

	cout << "Please enter Medicine  Barcode\n";
	cin >> barcode;

	cout << "Please enter Medicine Price\n";
	cin >> price;

	cout << "Please enter Medicine Quantity\n";
	cin >> quantity;
	Date expiry(day, month, year);
	if (type == 1) { // Medication
		Medication med(n, description, expiry, barcode, price, quantity);
		pharma[id].Add_medication(med);
	}
	else if (type == 2) { // Off The Shelf
		bool bogof;
		cout << "Please enter if it has a BOGOF (Buy One Get One Free) offer (enter 1 or 0)\n";
		cin >> bogof;
		OffTheShelf off(bogof, n, description, expiry, barcode, price, quantity);
		pharma[id].Add_OffTheShelf(off);
	}
	else if (type == 3) {
		int FDANumber;
		int day1, month1, year1;
		cout << "Please enter FDA Number\n";
		cin >> FDANumber;
		cout << "Please enter Approval day, month, year\n";
		cin >> day1 >> month1 >> year1;
		Date approval(day, month, year);
		Prescription pres(FDANumber, approval, n, description, expiry, barcode, price, quantity);
		pharma[id].Add_Prescription(pres);
	}
}

void removeMedication(Pharmacy* &pharma, int pharmCount) {
	int id;
	cout << "Enter pharmacy id:\n";
	cin >> id;
	if (id < 0 || id >= pharmCount) {
		cout << "Invalid pharmacy id" << endl;
		return;
	}
	int option;
	cout << "Remove by name (0) or index (1). Enter the option\n";
	cin >> option;
	if (option == 0) {
		string name;
		int type;
		cout << "Enter name of medication:\n";
		cin >> name;
		cout << "Enter type of medication:\n- 1 for Medication\n- 2 for Off The Shelf\n- 3 for Prescription\n\n";
		cin >> type;
		pharma[id].Remove_medication(name, type);
	}
	else if (option == 1) {
		int index1;
		int type;
		cout << "Enter index of medication:\n";
		cin >> index1;
		cout << "Enter type of medication:\n- 1 for Medication\n- 2 for Off The Shelf\n- 3 for Prescription\n\n";
		cin >> type;
		pharma[id].Remove_medication(index1, type);
	}
}

void addCustomer(Pharmacy* &pharma, int pharmCount) {
	int id;
	cout << "Enter pharmacy id:\n";
	cin >> id;
	if (id < 0 || id >= pharmCount) {
		cout << "Invalid pharmacy id" << endl;
		return;
	}
	string n, phone, email, street, city;
	cout << "Please enter Customer Name\n";
	cin >> n;

	cout << "Please enter Customer Phone Number\n";
	cin >> phone;

	cout << "Please enter Customer Email\n";
	cin >> email;

	cout << "Please enter Customer City\n";
	cin >> city;

	cout << "Please enter Customer Street\n";
	cin.ignore(); // To ignore any previous new lines from output above
	getline(cin, street); // To read a full line
	Address address(email, city, phone, street);
	Customer cust(n, address);
	pharma[id].Add_Customer(cust);
}

void printMed(Pharmacy* &pharma, int pharmCount) {
	int id;
	cout << "Enter pharmacy id:\n";
	cin >> id;
	if (id < 0 || id >= pharmCount) {
		cout << "Invalid pharmacy id" << endl;
		return;
	}
	pharma[id].av_med();
}

void printCust(Pharmacy* &pharma, int pharmCount) {
	int id;
	cout << "Enter pharmacy id:\n";
	cin >> id;
	if (id < 0 || id >= pharmCount) {
		cout << "Invalid pharmacy id" << endl;
		return;
	}
	pharma[id].print_cust();
}

void printPharmInfo(Pharmacy* &pharma, int pharmCount) {
	if (pharmCount == 0) {
		cout << "No pharmacies in town!" << endl;
		return;
	}
	for (int i = 0; i < pharmCount; i++) {
		pharma[i].DisplayInfo();
	}
}

int main() {
	
	Pharmacy* pharma = nullptr;
	int pharmCount = 0;
	int max = 0;
	int choice;
	cout << "Welcome to our community!\n";
	max = resizePharma(pharma, pharmCount);
	system("cls");
	do {
		cout << "\nWelcome to our community!\n\n- Enter 1 to add a new pharmacy\n- Enter 2 to add a new medication to pharmacy\n- Enter 3 to remove medication from pharmacy\n- Enter 4 to add a new customer to pharmacy\n- Enter 5 to list medications in pharmacy\n- Enter 6 to list customers in pharmacy\n- Enter 7 to list pharmacies\n\n";
		cin >> choice;
		switch (choice) {
		case 1: // Add a new pharmacy
			system("cls");
			addPharmacy(pharma, pharmCount, max);
			break;
		case 2: // Add medication to pharmacy
			system("cls");
			addMedication(pharma, pharmCount);
			break;
		case 3: // Remove medication to pharmacy
			system("cls");
			removeMedication(pharma, pharmCount);
			break;
		case 4: // Add customer to pharmacy
			system("cls");
			addCustomer(pharma, pharmCount);
			break;
		case 5: // Print available medications in pharmacy
			system("cls");
			printMed(pharma, pharmCount);
			break;
		case 6: // Print customers in pharmacy
			system("cls");
			printCust(pharma, pharmCount);
			break;
		case 7:  // Print info about pharmacy
			system("cls");
			printPharmInfo(pharma, pharmCount);
			break;
		case -1: // User exited program
			system("cls");
			cout << "Thanks for visiting our Pharmacy, see you next time!";
			break;
		default: // User entered wrong input
			system("cls");
			cout << "Wrong input! Please try again";
			break;
		} 
	} while (choice != -1);

	delete[] pharma;
	return 0;

}