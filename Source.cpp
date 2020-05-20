#include<iostream>
#include<map>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<conio.h>
using namespace std;
multimap <string, string> savedpatient;
int c=0,s=0;
class Person{
protected:
	string name, family,address,phone;
	int age;
public:
	Person() {}
    Person(string name, string family, string address, string phone, int age) {

		this->name = name;
		(*this).family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
	}
	void printsavedpatient(string); 
	void setName(string name) {
		this->name = name;
	}
	void setFamily(string family) {
		this->family = family;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
	void setAge(int age) {
		this->age = age;
	}
	string getName() const {
		return name;
	}
	string getFamily()const {
		return family;
	}
	string getAddress()const {
		return address;
	}
	string getPhone()const {
		return phone;
	}
	int getAge()const {
		return age;
	}
	void report()  {
		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << endl;
	}
};
class Doctor:public Person{
private:
	int codedoctor;
	string group, specialty;
public:
	Doctor() {
	}
	Doctor(string name, string family, string address, string phone, int age, int codedoctor, string group,string specialty) :Person(name, family, address, phone, age) {
		this->codedoctor = codedoctor;
		(*this).group = group;
		this->specialty = specialty;
	}
	//void printsavedpatient();
	void setcodedoctor(int codedoctor) {
		this->codedoctor = codedoctor;
	}
	int getcodedoctor()const {
		return codedoctor;
	}
	void setgroup(string group) { (*this).group = group; }
	string getgroup() { return group; }
	void setspecialty(string specialty) {
		this->specialty = specialty;
	}
	string getspecialty()const {
		return specialty;
	}
	void report(){
		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << codedoctor << setw(4) << group << setw(4) << specialty << endl;
	}
};
class Patient :public Person {
private:
	int idnumber;
	string group,namedoctor,kind;
	vector<Patient> Patients;
	vector<Patient> registerdata;
public:
	Patient() {}
	Patient(string name, string family, string address, string phone, int age, int idnumber, string group,string kind, string namedoctor) :Person(name, family, address, phone, age) {
		this->idnumber = idnumber;
		this->group = group;
		this->kind = kind;
	}
	void setIdnumber(int idnumber) {
		this->idnumber = idnumber;
	}
	void setgroup(string group) {
		this->group = group;
	}
	void setkind(string specialty) {
		this->kind = kind;
	}
	void setnamedoctor(string namedoctor) {
		this->namedoctor = namedoctor;
	}
	int getIdnumber()const {
		return idnumber;
	}
	string getgroup()const {
		return group;
	}
	string getkind()const { return kind; }
	string getnamedoctor()const { return namedoctor; }
	void report(){
		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << idnumber << setw(4) << group<< setw(4)<< kind << setw(6) << namedoctor << endl;
	}
};
//========================================================================================================================================================
//
//================================================================= DOCTOR =============================================================================
vector <Doctor> listDA, listDA2;
fstream outputfileDA;
void writeDA() {
	int codedoctor, age;
	string name, family, address, phone, group, specialty;
	cout << "\n Enter the number of Doctor: ";
	cin >> codedoctor;
	cout << "\n Enter the name of Doctor: ";
	cin >> name;
	cout << "\n Enter the family of Doctor: ";
	cin >> family;
	cout << "\n Enter the address of Doctor: ";
	cin >> address;
	cout << "\n Enter the phone of Doctor: ";
	cin >> phone;
	cout << "\n Enter the group of Doctor: ";
	cin >> group;
	cout << "\n Enter the age of Doctor: ";
	cin >> age;
	cout << "\n Enter the specialty of Doctor: ";
	cin >> specialty;
	listDA.push_back(Doctor(name, family, address, phone, age, codedoctor, group, specialty));
	outputfileDA.open("doctor.csv", ios::app);
	outputfileDA << name + "," + family + "," + address + "," + to_string(age) + phone + ","
		+ to_string(codedoctor) + "," + group + "," + specialty << endl;
}
void displayalldoctor() {
	system("cls");
	cout << "\n\n\t\tALL DOCTORS RESULT \n\n";
	cout << "=====================================================================================\n";
	cout << "Name       Family        Address   Phone   age   code      group      specialty" << endl;
	cout << "=====================================================================================\n";
	for (int i = 0; i < listDA.size(); i++)
	{
		listDA[i].report();
	}
	c = 0;
	cout << "tedad  doctors 0 ast";
}
void displayoneDA(int idnumber) {
	system("cls");
	cout << "\n\n\t\t  DOCTOR RESULT \n\n";
	cout << "========================================================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   group   specialty" << endl;
	cout << "========================================================================================\n";
	for (int i = 0; i < listDA.size(); i++)
	{
		if (listDA[i].getcodedoctor() == idnumber) {
			listDA[i].report();
			
		}
	}
}
void modifyDA(int idnumber) {
	string name, family, phone, specialty;
	int a;
	for (int i = 0; i < listDA.size(); i++)
	{
		if (listDA[i].getcodedoctor() == idnumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\t4. SPECIALTY";
			cout << "\n\n\n\tEnter Choice (1/2/3/4)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listDA[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listDA[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listDA[i].setPhone(phone); break;
			case 4: cout << "Enter a specialty" << endl; cin >> specialty; listDA[i].setspecialty(specialty); break;
			}
		}
	}
}
void deleteallDA() {
	listDA.clear();
	cout << "tedad doctors 0 ast" << c << endl;;
}
void delete_DA(int danumber) {
	for (int i = 0; i < listDA.size(); i++) {
		if (listDA[i].getcodedoctor() != danumber) {

			listDA2.push_back(listDA[i]);
			c--;
			cout << "tedad doctors :" << c<<endl;
		}
	}
	listDA = listDA2;
	vector<Doctor>().swap(listDA2);
}
multimap <string, string> getsavedpatient() {
	return savedpatient;
}
void printsavedpatient(string nameofdoctor) {
			for (multimap<string, string> ::iterator it = savedpatient.begin(); it != savedpatient.end(); it++) {
				if(nameofdoctor==it->first)
				{
					cout << it->first << "  " << it->second << endl;
				}
			}
		}
		
//========================================================================================================================================================
//
//================================================================= PATIENT =============================================================================
vector <Patient> listpa, listpa2;
fstream outputfile;
void writepa() {
	int idnumber, age;
	string kind, namedoctor;
	string name, family, address, phone, grade, group;
	cout << "\n Enter the number of Patient: ";
	cin >> idnumber;
	cout << "\n Enter the name of Patient: ";
	cin >> name;
	cout << "\n Enter the family of Patient: ";
	cin >> family;
	cout << "\n Enter the address of Patient: ";
	cin >> address;
	cout << "\n Enter the phone of Patient: ";
	cin >> phone;
	cout << "\n Enter the group of Patient: ";
	cin >> group;
	cout << "\n Enter the age of Patient: ";
	cin >> age;
	cout << "\n Enter the kind of Patient: ";
	cin >> kind;
	cout << "\n Enter the doctorname of Patient: ";
	cin >> namedoctor;
	listpa.push_back(Patient(name, family, address, phone, age, idnumber, group, kind, namedoctor));
	outputfile.open("Patient.csv", ios::app);
	outputfile << name + "," + family + "," + address + "," + to_string(age) + phone + ","
		+ to_string(idnumber) + "," + group + "," + kind + "," + namedoctor << endl;
}
void displayallpat() {
	system("cls");
	cout << "\n\n\t\tALL PATIENTS RESULT \n\n";
	cout << "==================================================================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   group   kind   doctorname" << endl;
	cout << "==================================================================================================\n";
	for (int i = 0; i < listpa.size(); i++)
	{
		listpa[i].report();

	}
}
void displayonepa(int idnumber) {
	system("cls");
	cout << "\n\n\t\t PATIENT RESULT \n\n";
	cout << "==================================================================================================\n";
	cout << "Name       Family        Address   Phone   age   idnumber   group   kind   doctorname" << endl;
	cout << "==================================================================================================\n";
	for (int i = 0; i < listpa.size(); i++)
	{
		if (listpa[i].getIdnumber() == idnumber) {
			listpa[i].report();
		}
	}
}
void modify(int idnumber) {
	string name, family, phone,kind,namedoctor;
	int a;
	for (int i = 0; i < listpa.size(); i++)
	{
		if (listpa[i].getIdnumber() == idnumber) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\t4. KIND";
			cout << "\n\n\t5. DOCTORNAME";
			cout << "\n\n\n\tEnter Choice (1/2/3/4/5)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listpa[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listpa[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listpa[i].setPhone(phone); break;
			case 4: cout << "Enter a kind" << endl; cin >> kind; listpa[i].setkind(kind); break;
			case 5: cout << "Enter a DOCTORNAME" << endl; cin >> namedoctor; listpa[i].setnamedoctor(namedoctor); break;
			}
		}
	}
}
void deleteallpatient() {
	listpa.clear();
		cout << "tedad doctors 0" <<endl;
}
void delete_patient(int idnumber) {
	for (int i = 0; i < listpa.size(); i++) {
		if (listpa[i].getIdnumber() != idnumber) {
			listpa2.push_back(listpa[i]);
			s--;
			cout << "tedad doctors :" << s<<endl;
		}
	}
	listpa = listpa2;
	vector<Patient>().swap(listpa2);
}
/*multimap <string, string> getsavedpatient() {
	return savedpatient;
}*/
vector<Patient> getlistpa() {
	return listpa
		;
}
void registerPatient() {
	string nameofdoctor;
	cout << "Enter the doctorname of Patient for register" << endl;
	cin >> nameofdoctor;
	vector<Patient> listPATIENT = getlistpa();
	int b = listPATIENT.size();
	for (int i = 0; i < b; i++) {
			savedpatient.insert(pair<string, string>(listPATIENT[i].getnamedoctor(), listPATIENT[i].getkind()));
		}
	printsavedpatient(nameofdoctor);
	}
	/*multimap <string, string> getsavedpatient() {
		return savedpatient;*/
	

//========================================================================================================================================================
//
//================================================================= MENU =============================================================================
void intro() {
	system("cls");
	cout << "\n\n\n\t\t  SYSTEM UNIVERSITY";
	cout << "\n\n\t\t  ADVANCED C++ PROJECT";
	cout << "\n\n\n\tMADE BY : GOLNOOSH DEHGHANI";
	cout << "\n\tSCHOOL : QOM UNIVERSITY";
	cin.get();
}
void report_men() {
	int a, e, f;
	int idnumber;
	string idnum;
	system("cls");
	cout << "\n\n\n\tREPORT MENU";
	cout << "\n\n\n\t1. REPORTS";
	cout << "\n\n\t2. Back to Main Menu";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> a;
	switch (a)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tREPORTs MENU";
	cout << "\n\n\t1. PATIENT Reports";
	cout << "\n\n\t2. DOCTOR Reports";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> e;
	switch (e)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All PATIENT Report";
	cout << "\n\n\t2. PATIENT Report";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayallpat(); _getch(); break;
	case 2: cout << "\n Enter the number of patient: "; cin >> idnumber;
		displayonepa(idnumber); _getch(); break;
	default:
		break;
	}
	break; }
	//*********************************************************************+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	case 2:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All Doctor Report";
	cout << "\n\n\t2. Doctor Report";
	cout << "\n\n\t3.doctor patents Report";
	cout << "\n\n\n\tEnter Choice (1/3)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayalldoctor(); break;
	case 2: cout << "\n Enter the number of teacher: "; cin >> idnumber;
		displayoneDA(idnumber); break;
	case 3: 
		registerPatient(); _getch(); break;
	default:
		break;
	}

	break; }
	break;

	}
	case 2:break;
	}

}

}

//*********************************************************************************************************************
void entry_men() {
	int a, num;
	char choice;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\n\t1.ENTRY MENU PATIENT";
	cout << "\n\n\t2.ENTRY MENU DOCTOR";
	cout << "\n\n\t3.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-3) ";

	cin >> a;
	switch (a)
	{
	case 1:
	{    system("cls");
	cout << "\n\n\n\tENTRY MENU PATIENT";
	cout << "\n\n\t1.CREATE PATIENT RECORD";
	cout << "\n\n\t2.MODIFY PATIENT RECORD";
	cout << "\n\n\t3.DELETE PATIENT RECORD";
	cout << "\n\n\t4.DELETE PATIENT RECORDS";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			writepa();
			cout << "\n Student record has been created";
			cout << "tedad patients:" << s++ << endl;

			system("cls");
			cout << "Do you want to insert new record of student? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of student " << endl;
		cin >> num; modify(num); break;
		break;
	case 3: cout << "\nEnter the number of student " << endl;
		cin >> num; delete_patient(num); break;
		break;
	case 4:  deleteallpatient(); break;
	case 5: break;
	}
	break;
	}
	case 2:
	{   system("cls");
	cout << "\n\n\n\tENTRY MENU DOCTOR";
	cout << "\n\n\t1.CREATE DOCTOR RECORD";
	cout << "\n\n\t2.MODIFY DOCTOR RECORD";
	cout << "\n\n\t3.DELETE DOCTOR RECORD";
	cout << "\n\n\t4.DELETE DOCTOR RECORDS";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			writeDA();
			cout << "\n DOCTOR record has been created";
			cout << "tedad patients:" << c++ << endl;
			system("cls");
			cout << "Do you want to insert new record of DOCTOR? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of DOCTOR " << endl;
		cin >> num; modifyDA(num); break;
		break;
	case 3: cout << "\nEnter the number of DOCTOR " << endl;
		cin >> num; delete_DA(num); break;
		break;
	case 4:  deleteallDA(); break;
	case 5: break;
	}
	break;
	}

	case 4:break;

	}
}
//========================================================================================================================================================
//
//================================================================= MAIN =============================================================================
int main()
{
	int e;
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. REPORT MENU";
		cout << "\n\n\t02. ENTRY/EDIT MENU";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> e;
		system("cls");
		switch (e)
		{
		case 1:report_men(); break;
		case 2:entry_men();
		case 3:break;
		}
	} while (e != 3);
	system("pause");
	_getch();
	return 0;
}