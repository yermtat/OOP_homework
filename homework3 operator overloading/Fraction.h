#pragma once
class Fraction
{
public:

	short integer;
	short numenator; // числитель
	short denominator; // знаменатель

	Fraction(short integer, short numenator, short denominator) : integer{ integer }, numenator{ numenator }, denominator{ (denominator != 0) ? denominator : 1} {};
	Fraction() : Fraction(0, 0, 1) {}

	static Fraction add(Fraction fraction1, Fraction fraction2);
	static Fraction subtraction(Fraction fraction1, Fraction fraction2);
	static Fraction multiply(Fraction fraction1, Fraction fraction2);
	static Fraction devide(Fraction fraction1, Fraction fraction2);

	friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2) {
		return add(fraction1, fraction2);
	}

	friend Fraction operator+(const Fraction& fraction1, int value) {
		Fraction tmp = fraction1;
		tmp.integer += value;
		return tmp;
	}

	friend Fraction operator+(int value, const Fraction& fraction1) {
		Fraction tmp = fraction1;
		tmp.integer += value;
		return tmp;
	}


	friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2) {
		return subtraction(fraction1, fraction2);
	}

	friend Fraction operator-(const Fraction& fraction1, int value) {
		Fraction tmp = fraction1;
		tmp.integer -= value;
		return tmp;
	}

	friend Fraction operator-(int value, const Fraction& fraction1) {
		
		Fraction value_fraction(value - 1, fraction1.denominator, fraction1.denominator);
			
		return subtraction(value_fraction, fraction1);
	}


	friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2) {
		return multiply(fraction1, fraction2);
	}

	friend Fraction operator*(const Fraction& fraction1, int value) {

		Fraction value_fraction(0, value, 1);

		return multiply(value_fraction, fraction1);
	}

	friend Fraction operator*(int value, const Fraction& fraction1) {

		Fraction value_fraction(0, value, 1);

		return multiply(value_fraction, fraction1);
	}

	friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2) {
		return devide(fraction1, fraction2);
	}

	friend Fraction operator/(const Fraction& fraction1, int value) {

		Fraction value_fraction(0, value, 1);

		return devide(fraction1, value_fraction);
	}

	friend Fraction operator/(int value, const Fraction& fraction1) {

		Fraction value_fraction(0, value, 1);

		return devide(value_fraction, fraction1);
	}


	Fraction& operator++() {
		++integer;
		return *this;
	}

	Fraction& operator--() {
		--integer;
		return *this;
	}

	const Fraction operator++(int) {
		Fraction tmp(integer, numenator, denominator);
		++(*this);
		return tmp;
	}

	const Fraction operator--(int) {
		Fraction tmp(integer, numenator, denominator);
		--(*this);
		return tmp;
	}

};



