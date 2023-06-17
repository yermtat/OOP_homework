#pragma once

#include<iostream>
using namespace std;

#pragma region human body - body parts

class Body_parts {
	bool heart;
	bool lungs;
	bool liver;
	bool brain;
	bool kidneys;
public:
	Body_parts() : heart(true), lungs(true), liver(true), brain(true), kidneys(true) {
		cout << "There are all body parts" << endl;
	}
	Body_parts(bool heart, bool lungs, bool liver, bool brain, bool kidneys) :
		heart(heart), lungs(lungs), liver(liver), brain(brain), kidneys(kidneys) {
		cout << "There are all body parts. Unless they aren't." << endl;
	}


};

class Human_body {

	Body_parts inner_parts;
	int legs;
	int arms;
	bool skin;
public: 
	Human_body() : legs(2), arms(2), skin(true) {
		cout << "That's a human body" << endl;
	}

	Human_body(bool heart, bool lungs, bool liver, bool brain, bool kidneys, int legs, int arms, bool skin) :
		inner_parts(Body_parts(heart, lungs, liver, brain, kidneys)), legs(legs), arms(arms), skin(skin) {
		cout << "That's also a human body. Maybe not a healthy one. Or it's not a human at all" << endl;
	}
};

#pragma endregion


#pragma region quitar - strings

class Strings {

	bool string1;
	bool string2;
	bool string3;
	bool string4;
	bool string5;
	bool string6;

public:
	Strings(bool string1, bool string2, bool string3, bool string4, bool string5, bool string6)
		: string1(string1), string2(string2), string3(string3), string4(string4), string5(string5), string6(string6) {
		cout << "These are strings of a quitar" << endl;
	}

	Strings() : Strings(true, true, true, true, true, true) {
		cout << "There are all 6 strings" << endl;
	}

};	


class Quitar {
	Strings strings;
	bool tuners;
	int frets;
public:
	Quitar(bool string1, bool string2, bool string3, bool string4, bool string5, bool string6, bool tuners, int frets) :
	strings(Strings(string1, string2, string3, string4, string5, string6)), tuners(tuners), frets(frets) {
		cout << "That's a quitar. Go on, try to play." << endl;
	}

	Quitar() : Quitar(true, true, true, true, true, true, true, 12) {
		cout << "All parts are fine. Ready to play." << endl;
	}
};
#pragma endregion
	

#pragma region cinema building - cinema hall

class Cinema_hall {
	int seats;
public:
	Cinema_hall() : seats(45) { cout << "There are 45 seats in a hall" << endl; }
};

class Cinema_building {
	int halls_quant;
	Cinema_hall* halls;
public:
	Cinema_building() : halls_quant(4), halls(new Cinema_hall[4]) {
		cout << "There are " << 4 <<" halls in the cinema" << endl;
	}

	Cinema_building(int quant) : halls_quant(quant), halls(new Cinema_hall[quant]) {
		cout << "There are " << halls_quant << " halls in the cinema" << endl;
	}
};
#pragma endregion

	
	
