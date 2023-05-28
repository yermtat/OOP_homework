#include<iostream>		
#include"Fraction.h"

using namespace std;

			/*Реализуйте класс дробь. Необходимо хранить числитель и знаменатель в качестве переменных-членов. 
			Реализуйте функции-члены для ввода данных в переменные-члены для выполнения арифметических операций 
			(сложение, вычитание, умножение, деление, и т.д)*/

short find_devisor(short number1, short number2);
short NOK(short number1, short number2);
Fraction add(Fraction fraction1, Fraction fraction2);
Fraction subtraction(Fraction fraction1, Fraction fraction2);
Fraction multiply(Fraction fraction1, Fraction fraction2);
Fraction devide(Fraction fraction1, Fraction fraction2);

int main() {

	short integer{}, numenator{}, denominator{};
	
	cout << "Enter an integer part, a numenator and denominator of first number: ";
	cin >> integer >> numenator >> denominator;

	Fraction fraction1(integer, numenator, denominator);

	cout << "Enter an integer part, a numenator and denominator of second number: ";
	cin >> integer >> numenator >> denominator;

	Fraction fraction2(integer, numenator, denominator);
	
	Fraction tmp;
	
	/*tmp = add(fraction1, fraction2);*/

	/*tmp = subtraction(fraction1, fraction2);*/

	/*tmp = multiply(fraction1, fraction2);*/

	/*tmp = devide(fraction1, fraction2);*/

	cout << tmp.integer << " " << tmp.numenator << '/' << tmp.denominator;
}

short find_devisor(short number1, short number2) {

	if (number1 == number2) return number1;

	if (number1 > number2) find_devisor(number1 - number2, number2);
	else find_devisor(number2 - number1, number1);

}

short NOK(short number1, short number2) {

	return number1 * number2 / find_devisor(number1, number2);
}


Fraction add(Fraction fraction1, Fraction fraction2) {

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

Fraction subtraction(Fraction fraction1, Fraction fraction2) {

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

Fraction multiply(Fraction fraction1, Fraction fraction2) {

	if (fraction1.integer != 0) fraction1.numenator += fraction1.integer * fraction1.denominator;
	if (fraction2.integer != 0) fraction2.numenator += fraction2.integer * fraction2.denominator;


	Fraction tmp;

	tmp.numenator = fraction1.numenator * fraction2.numenator;
	tmp.denominator = fraction1.denominator * fraction2.denominator;
	tmp.integer = tmp.integer += tmp.numenator / tmp.denominator;
	tmp.numenator %= tmp.denominator;

	short devisor = find_devisor(tmp.numenator, tmp.denominator);

	tmp.numenator /= devisor;
	tmp.denominator /= devisor;

	return tmp;

}

Fraction devide(Fraction fraction1, Fraction fraction2) {

	if (fraction1.integer != 0) fraction1.numenator += fraction1.integer * fraction1.denominator;
	if (fraction2.integer != 0) fraction2.numenator += fraction2.integer * fraction2.denominator;

	Fraction tmp;

	tmp.numenator = fraction1.numenator * fraction2.denominator;
	tmp.denominator = fraction1.denominator * fraction2.numenator;
	tmp.integer = tmp.integer += tmp.numenator / tmp.denominator;
	tmp.numenator %= tmp.denominator;

	short devisor = find_devisor(tmp.numenator, tmp.denominator);

	tmp.numenator /= devisor;
	tmp.denominator /= devisor;
	return tmp;
}