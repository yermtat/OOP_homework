#include "Fraction.h"

short find_devisor(short number1, short number2) {

	if (number1 == number2) return number1;

	if (number1 > number2) find_devisor(number1 - number2, number2);
	else find_devisor(number2 - number1, number1);

}

short NOK(short number1, short number2) {

	return number1 * number2 / find_devisor(number1, number2);
}


Fraction Fraction::add(Fraction fraction1, Fraction fraction2) {

	Fraction tmp;
	short denominator = NOK(fraction1.denominator, fraction2.denominator);

	tmp.integer = fraction1.integer + fraction2.integer;
	tmp.denominator = denominator;
	tmp.numenator = fraction1.numenator * (denominator / fraction1.denominator) + fraction2.numenator * (denominator / fraction2.denominator);

	if (tmp.numenator >= tmp.denominator) {
		tmp.integer += tmp.numenator / tmp.denominator;
		tmp.numenator %= tmp.denominator;
	}

	return tmp;
}

Fraction Fraction::subtraction(Fraction fraction1, Fraction fraction2) {

	Fraction tmp;
	short denominator = NOK(fraction1.denominator, fraction2.denominator);

	tmp.integer = fraction1.integer - fraction2.integer;
	tmp.denominator = denominator;
	tmp.numenator = fraction1.numenator * (denominator / fraction1.denominator) - fraction2.numenator * (denominator / fraction2.denominator);

	if (tmp.numenator >= tmp.denominator) {
		tmp.integer += tmp.numenator / tmp.denominator;
		tmp.numenator %= tmp.denominator;
	}

	return tmp;
}

Fraction Fraction::multiply(Fraction fraction1, Fraction fraction2) {

	if (fraction1.integer != 0) fraction1.numenator += fraction1.integer * fraction1.denominator;
	if (fraction2.integer != 0) fraction2.numenator += fraction2.integer * fraction2.denominator;


	Fraction tmp;

	tmp.numenator = fraction1.numenator * fraction2.numenator;
	tmp.denominator = fraction1.denominator * fraction2.denominator;
	tmp.integer = tmp.numenator / tmp.denominator;
	tmp.numenator %= tmp.denominator;

	short devisor = find_devisor(tmp.numenator, tmp.denominator);

	tmp.numenator /= devisor;
	tmp.denominator /= devisor;

	return tmp;

}

Fraction Fraction::devide(Fraction fraction1, Fraction fraction2) {

	if (fraction1.integer != 0) fraction1.numenator += fraction1.integer * fraction1.denominator;
	if (fraction2.integer != 0) fraction2.numenator += fraction2.integer * fraction2.denominator;

	Fraction tmp;

	tmp.numenator = fraction1.numenator * fraction2.denominator;
	tmp.denominator = fraction1.denominator * fraction2.numenator;
	tmp.integer = tmp.numenator / tmp.denominator;
	tmp.numenator %= tmp.denominator;

	short devisor = find_devisor(tmp.numenator, tmp.denominator);

	tmp.numenator /= devisor;
	tmp.denominator /= devisor;
	return tmp;
}



