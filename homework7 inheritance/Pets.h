#pragma once

#include<iostream>

using namespace std;

class Pets
{
public:
	char* name;
	char* breed;
	int age;
	bool is_healthy;

	Pets(const char* name, const char* breed, int age, bool is_healthy) :
		name(new char[strlen(name) + 1]), breed(new char[strlen(breed) + 1]), age(age), is_healthy(is_healthy) {
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->breed, strlen(breed) + 1, breed);
	}
};

class Dog : public Pets {

public:

	bool is_big;
	bool is_hunting;
	bool is_trained;
	

	Dog(const char* name, const char* breed, int age, bool is_healthy, bool is_big, bool is_hunting, bool is_trained) :
		Pets(name, breed, age, is_healthy), is_big(is_big), is_hunting(is_hunting), is_trained(is_trained) {}


	void show_info();


};

class Cat : public Pets {

public:

	char* eye_color;
	char* furr_color;

	Cat(const char* name, const char* breed, int age, bool is_healthy, const char* eye_color, const char* furr_color) :
		Pets(name, breed, age, is_healthy), eye_color(new char[strlen(eye_color) + 1]), 
		furr_color(new char[strlen(furr_color) + 1]) {
		strcpy_s(this->eye_color, strlen(eye_color) + 1, eye_color);
		strcpy_s(this->furr_color, strlen(furr_color) + 1, furr_color);
	}
	
	void show_info();
};

class Parrot : public Pets {

public:
	
	bool does_talking;
	bool is_ringed;
	char* color;

	Parrot(const char* name, const char* breed, int age, bool is_healthy, bool does_talking, bool is_ringed,
		const char* color) :
		Pets(name, breed, age, is_healthy), does_talking(does_talking), is_ringed(is_ringed), 
		color(new char[strlen(color) + 1]) {
		strcpy_s(this->color, strlen(color) + 1, color);
	}

	void show_info();
};

