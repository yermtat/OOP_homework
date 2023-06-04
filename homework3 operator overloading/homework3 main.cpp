#include"Fraction.h"
#include<iostream>

using namespace std;

int main() {


	/*short integer{}, numenator{}, denominator{};

	cout << "Enter an integer part, a numenator and denominator of first number: ";
	cin >> integer >> numenator >> denominator;

	Fraction fraction1(integer, numenator, denominator);

	cout << "Enter an integer part, a numenator and denominator of second number: ";
	cin >> integer >> numenator >> denominator;

	Fraction fraction2(integer, numenator, denominator);*/


	Fraction fraction1(3, 4, 5);
	Fraction fraction2(4, 5, 4);
	Fraction tmp;

	//tmp = fraction1 + fraction2;
	//tmp = fraction1 + 2;
	//tmp = 2 + fraction1;
	//
	//tmp = fraction2 - fraction1;
	//tmp = fraction1 - fraction2;
	//tmp = fraction1 - 2;
	//tmp = 5 - fraction1;

	//tmp = fraction1 * fraction2;
	//tmp = fraction1 * 2;
	//tmp = 2 * fraction1;

	//tmp = fraction1 / fraction2;
	//tmp = fraction1 / 2;
	//tmp = 2 / fraction1;

	//cout << tmp.integer << " " << tmp.numenator << '/' << tmp.denominator;



	Fraction fract(4, 5, 6);
	//++fract;
	//--fract;

	Fraction exp;
	// exp = fract++ + 2;
	exp = fract-- + 2;

	cout << fract.integer << " " << fract.numenator << '/' << fract.denominator;
	cout << exp.integer << " " << exp.numenator << '/' << exp.denominator;
	
	



	
}
