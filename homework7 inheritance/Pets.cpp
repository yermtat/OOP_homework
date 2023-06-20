#include "Pets.h"

void Dog::show_info() {

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Breed: " << breed << endl;
	cout << "Is the dog healthy: " << boolalpha << is_healthy << endl;
	cout << "Is the dog big: " << boolalpha << is_big << endl;
	cout << "Is it a hunting dog: " << boolalpha << is_hunting << endl;
	cout << "Is the dog trained: " << boolalpha << is_trained << endl;

}

void Cat::show_info() {

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Breed: " << breed << endl;
	cout << "Is the cat healthy: " << boolalpha << is_healthy << endl;
	cout << "What is the eye color: " << eye_color << endl;
	cout << "What is the furr color: " << furr_color << endl;

}

void Parrot::show_info() {

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Breed: " << breed << endl;
	cout << "Is the parrot healthy: " << boolalpha << is_healthy << endl;
	cout << "Does it talk: " << boolalpha << does_talking << endl;
	cout << "Is it ringed: " << boolalpha << is_ringed << endl;
	cout << "Feather's color: " << color << endl;

}


