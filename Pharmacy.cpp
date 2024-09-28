#include"Pharmacy.h"
int Pharmacy::count_id = 0;
Pharmacy::Pharmacy() :id(count_id++)
{
	name = "No Name";
	count_med = 0;
	count_cust = 0;
	count_off = 0;
	count_pres = 0;
	med = NULL;
	cust = NULL;
	off = NULL;
	pres = NULL;
}

Pharmacy::Pharmacy(string n) :id(count_id++)
{
	if (n != "")
		name = n;
	else {
		name = "No Name";
		cout << "Invalid pharmacy name entered, set to default." << endl;
	}
	count_med = 0;
	count_cust = 0;
	count_off = 0;
	count_pres = 0;
	med = NULL;
	cust = NULL;
	off = NULL;
	pres = NULL;
}

Pharmacy::Pharmacy(Pharmacy& ph_obj) :id(ph_obj.id)
{
	name = ph_obj.name;
	count_med = ph_obj.count_med;
	count_cust = ph_obj.count_cust;
	count_off = ph_obj.count_off;
	count_pres = ph_obj.count_pres;

	med = new Medication[count_med];
	for (int i = 0; i < count_med; i++)
	{
		med[i] = ph_obj.med[i];
	}

	cust = new Customer[count_cust];
	for (int i = 0; i < count_cust; i++)
	{
		cust[i] = ph_obj.cust[i];
	}

	off = new OffTheShelf[count_off];
	for (int i = 0; i < count_off; i++)
	{
		off[i] = ph_obj.off[i];
	}

	pres = new Prescription[count_pres];
	for (int i = 0; i < count_pres; i++)
	{
		pres[i] = ph_obj.pres[i];
	}
}

Pharmacy::~Pharmacy()
{
	if (med != NULL)
		delete[] med;
	if (cust != NULL)
		delete[] cust;
	if (off != NULL)
		delete[] off;
	if (pres != NULL)
		delete[] pres;
}


void Pharmacy::Add_medication(Medication med_obj)
{

	Medication* temp = new Medication[count_med + 1];
	for (int i = 0; i < count_med; i++)
		temp[i] = med[i];
	if (med != NULL)
		delete[] med;
	med = temp;
	temp = NULL;
	med[count_med] = med_obj;
	count_med++;
}
void Pharmacy::Add_Prescription(Prescription pres_obj)
{
	Prescription* temp = new Prescription[count_pres + 1];
	for (int i = 0; i < count_pres; i++)
		temp[i] = pres[i];
	if (pres != NULL)
		delete[] pres;
	pres = temp;
	temp = NULL;
	pres[count_pres] = pres_obj;
	count_pres++;
}
void Pharmacy::Add_OffTheShelf(OffTheShelf off_obj)
{

	OffTheShelf* temp = new OffTheShelf[count_off + 1];
	for (int i = 0; i < count_off; i++)
		temp[i] = off[i];
	if (off != NULL)
		delete[] off;
	off = temp;
	temp = NULL;
	off[count_off] = off_obj;
	count_off++;
}
void Pharmacy::Remove_medication(int index, int type)
{
	if (type == 1) { // Med
		if (!(index >= 0 && index < count_med)) return;
		Medication temp1;
		med[index] = temp1;

		for (int i = index; i < count_med - 1; i++)
		{
			Medication temp;
			temp = med[i];
			med[index] = med[index + 1];
			med[index + 1] = temp;
		}
		Medication* temp = new Medication[count_med - 1];
		for (int i = 0; i < count_med - 1; i++)
			temp[i] = med[i];
		if (med != NULL)
			delete[] med;
		med = temp;
		temp = NULL;
		count_med--;
		return;
	}
	if (type == 2) { // Off The 
		if (!(index >= 0 && index < count_off)) return;
		OffTheShelf temp1;
		off[index] = temp1;

		for (int i = index; i < count_off - 1; i++)
		{
			OffTheShelf temp;
			temp = off[i];
			off[index] = off[index + 1];
			off[index + 1] = temp;
		}
		OffTheShelf* temp = new OffTheShelf[count_off - 1];
		for (int i = 0; i < count_off - 1; i++)
			temp[i] = off[i];
		if (off != NULL)
			delete[] off;
		off = temp;
		temp = NULL;
		count_off--;
		return;
	}
	if (type == 3) { // Prescription
		if (!(index >= 0 && index < count_pres)) return;
		Prescription temp1;
		pres[index] = temp1;

		for (int i = index; i < count_pres - 1; i++)
		{
			Prescription temp;
			temp = pres[i];
			pres[index] = pres[index + 1];
			pres[index + 1] = temp;
		}
		Prescription* temp = new Prescription[count_pres - 1];
		for (int i = 0; i < count_pres - 1; i++)
			temp[i] = pres[i];
		if (pres != NULL)
			delete[] pres;
		pres = temp;
		temp = NULL;
		count_pres--;
		return;
	}
}
void Pharmacy::Remove_medication(string n, int type)
{
	if (type == 1) { // Med
		int index = -1;
		for (int i = 0; i < count_med; i++) {
			if (med[i].get_name() == n)
			{
				index = i;
				break;
			}
		}
		if (index == -1) return;
		Medication temp1;
		med[index] = temp1;

		for (int i = index; i < count_med - 1; i++)
		{
			Medication temp;
			temp = med[i];
			med[index] = med[index + 1];
			med[index + 1] = temp;
		}
		Medication* temp = new Medication[count_med - 1];
		for (int i = 0; i < count_med - 1; i++)
			temp[i] = med[i];
		if (med != NULL)
			delete[] med;
		med = temp;
		temp = NULL;
		count_med--;
		return;
	}
	if (type == 2) { // Off The Shelf
		int index = -1;
		for (int i = 0; i < count_off; i++) {
			if (off[i].get_name() == n)
			{
				index = i;
				break;
			}
		}
		if (index == -1) return;
		OffTheShelf temp1;
		off[index] = temp1;

		for (int i = index; i < count_off - 1; i++)
		{
			OffTheShelf temp;
			temp = off[i];
			off[index] = off[index + 1];
			off[index + 1] = temp;
		}
		OffTheShelf* temp = new OffTheShelf[count_off - 1];
		for (int i = 0; i < count_off - 1; i++)
			temp[i] = off[i];
		if (off != NULL)
			delete[] off;
		off = temp;
		temp = NULL;
		count_off--;
		return;
	}
	if (type == 3) { // Prescription
		int index = -1;
		for (int i = 0; i < count_pres; i++) {
			if (pres[i].get_name() == n)
			{
				index = i;
				break;
			}
		}
		if (index == -1) return;
		Prescription temp1;
		pres[index] = temp1;

		for (int i = index; i < count_pres - 1; i++)
		{
			Prescription temp;
			temp = pres[i];
			pres[index] = pres[index + 1];
			pres[index + 1] = temp;
		}
		Prescription* temp = new Prescription[count_pres - 1];
		for (int i = 0; i < count_pres - 1; i++)
			temp[i] = pres[i];
		if (pres != NULL)
			delete[] pres;
		pres = temp;
		temp = NULL;
		count_pres--;
		return;
	}

}

void Pharmacy::Add_Customer(Customer cust_obj)
{
	Customer* temp = new Customer[count_cust + 1];
	for (int i = 0; i < count_cust; i++)
		temp[i] = cust[i];
	if (cust != NULL)
		delete[] cust;
	cust = temp;
	temp = NULL;
	cust[count_med] = cust_obj;
	count_cust++;

}

void Pharmacy::av_med()const
{
	cout << "The available medications of pharmacy no. " << id << " are the following : " << endl;
	for (int i = 0; i < count_med; i++) {
		cout << "Index: " << i << endl;
		med[i].print();
	}
	for (int i = 0; i < count_off; i++) {
		cout << "Index: " << i << endl;
		off[i].print();
	}
	for (int i = 0; i < count_pres; i++) {
		cout << "Index: " << i << endl;
		pres[i].print();
	}

}

void Pharmacy::print_cust()const
{
	cout << "Customers for Pharmacy no. " << id << " are : " << endl;
	for (int i = 0; i < count_cust; i++)
		cust[i].DisplayInfo();
}
void Pharmacy::set_id(int i) {
	if (i >= 0) {
		id = i;
	}
	else {
		id = 0;
	}
}
int Pharmacy::get_id() {
	return id;
}

void Pharmacy::set_med_count(int n) {
	count_med = n;
}
void Pharmacy::set_cust_count(int n) {
	count_cust = n;
}
void Pharmacy::set_off_count(int n) {
	count_off = n;
}
void Pharmacy::set_pres_count(int n) {
	count_pres = n;
}
void Pharmacy::set_name(string n)
{
	if (n != "")
		name = n;
	else
		name = "No Name";
}
string Pharmacy::get_name()const
{
	return name;
}
Medication Pharmacy::get_med(int i)const
{
	return med[i];
}

Customer Pharmacy::get_cust(int i)const
{
	return cust[i];
}

OffTheShelf Pharmacy::get_off(int i)const
{
	return off[i];
}
Prescription Pharmacy::get_pres(int i)const
{
	return pres[i];
}
void Pharmacy::set_cust(Customer o, int i) {
	if (i >= 0 && i < count_cust) cust[i] = o;
}
void Pharmacy::set_pres(Prescription o, int i) {
	if (i >= 0 && i < count_pres) pres[i] = o;
}
void Pharmacy::set_off(OffTheShelf o, int i) {
	if (i >= 0 && i < count_off) off[i] = o;
}
void Pharmacy::set_med(Medication o, int i) {
	if (i >= 0 && i < count_med) med[i] = o;
}
int Pharmacy::num_of_med()const
{
	return count_med;
}

int Pharmacy::num_of_cust()const
{
	return count_cust;
}

int Pharmacy::num_of_off()const
{
	return count_off;
}

int Pharmacy::num_of_pres()const
{
	return count_pres;
}

double Pharmacy::total_cash()const
{
	double total = 0;
	for (int i = 0; i < count_med; i++) total += med[i].get_price() * med[i].get_quantity();
	for (int i = 0; i < count_off; i++) total += off[i].get_price() * off[i].get_quantity();
	for (int i = 0; i < count_pres; i++) total += pres[i].get_price() * pres[i].get_quantity();
	return total;
}

void Pharmacy::DisplayInfo() const {
	cout << "Pharmacy ID: " << id << endl;
	cout << "Pharmacy Name: " << name << endl;
	cout << "Number of medications: " << count_med << endl;
	cout << "Number of off the shelf medications: " << count_med << endl;
	cout << "Number of prescriptions: " << count_med << endl;
	cout << "Number of customers: " << count_cust << endl;
}