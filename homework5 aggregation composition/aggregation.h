#pragma once

#include<iostream>
using namespace std; 

#pragma region character - movie, book
class Character {

	char* name;
	int age;
	bool is_alive;
public:

	Character(const char* name, int age, bool is_alive) : name(new char[strlen(name) + 1]), age(age), is_alive(is_alive) {
		cout << "The character is made. Are they good or evil?" << endl;
	}

};


class Movie {

	char* movie_name;
	int release_year;
	char* director;
	Character& character;
public:

	Movie(const char* movie_name, int release_year, const char* director, Character& character) :
		movie_name(new char[strlen(movie_name) + 1]), release_year(release_year), director(new char[strlen(director) + 1]), character(character) {
		cout << "Now the character is in a movie. Hope it's a good one" << endl;
	}
};


class Book {

	char* book_name;
	int release_year;
	char* writer;
	Character& character;
public:
	Book(const char* book_name, int release_year, const char* writer, Character& character) :
		book_name(new char[strlen(book_name) + 1]), release_year(release_year), writer(new char[strlen(writer) + 1]), character(character) {
		cout << "There was even a book this whole time?!" << endl;
	}
};


#pragma endregion

#pragma region floor - different rooms

class Floor {

	char* material;
	char* color;
public: 

	Floor(const char* material, const char* color) : material(new char[strlen(material) + 1]), color(new char[strlen(color) + 1]) {
		cout << "This is a floor" << endl;
	}
};

class Livingroom {

	bool furniture;
	bool techs;
	int size;
	Floor& floor;
public: 

	Livingroom(bool furniture, bool techs, int size, Floor& floor) : furniture(furniture), techs(techs), size(size), floor(floor) {
		cout << "That's living room" << endl;
	}
};


class Bedroom {

	bool bed;
	bool curtains;
	Floor& floor;
public: 

	Bedroom(bool bed, bool curtauns, Floor& floor) : bed(bed), curtains(curtains), floor(floor) {
		cout << "It's a bedroom" << endl;
	}

};


#pragma endregion