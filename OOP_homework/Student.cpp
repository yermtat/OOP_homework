
#include "Student.h"

ulong Student::get_date_of_birth() {
	return date_of_birth;
}

void Student::set_date_of_birth(ulong date) {

	if (date > 10000000) {
		date_of_birth = date;
	}
}

ulong Student::get_phone_number() {
	return phone_number;
}

void Student::set_phone_number(ulong number) {

	if (number > 100000000000 && number < 1000000000000)
		phone_number = number;

}

void Student::setInfo() {

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter father's name: ";
	cin >> fathers_name;
	cout << "Enter birthdate: ";
	cin >> date_of_birth;
	cout << "Enter contact number: ";
	cin >> phone_number;
	cout << "Enter city: ";
	cin >> city;
	cout << "Enter country: ";
	cin >> country;
	cout << "Enter school's name: ";
	cin >> school_name;
	cout << "Enter school's city: ";
	cin >> school_city;
	cout << "Enter school's country: ";
	cin >> school_country;
	cout << "Enter group's number: ";
	cin >> group_number;

}

void Student::getInfo() {

	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Father's name: " << fathers_name << endl;
	cout << "Birthdate: " << date_of_birth << endl;
	cout << "Contact number: " << phone_number << endl;
	cout << "City: " << city << endl;
	cout << "Country: " << country << endl;
	cout << "School's name: " << school_name << endl;
	cout << "School's city: " << school_city << endl;
	cout << "School's country: " << school_country << endl;
	cout << "Group's number: " << group_number << endl;
}