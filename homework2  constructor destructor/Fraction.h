#pragma once

/*Реализуйте класс дробь. Необходимо хранить числитель и знаменатель в качестве переменных-членов.
Реализуйте функции-члены для ввода данных в переменные-члены для выполнения арифметических операций
(сложение, вычитание, умножение, деление, и т.д)*/

class Fraction
{
public:

	short integer;
	short numenator; // числитель
	short denominator; // знаменатель

	Fraction();
	Fraction(short integer, short numenator, short denominator);
	
	~Fraction();

};

Fraction::Fraction()
{
	integer = 0;
	numenator = 0;
	denominator = 0;
}

Fraction::Fraction(short integer, short numenator, short denominator)
{
	this->integer = integer;
	this->numenator = numenator;
	this->denominator = denominator;
}

Fraction::~Fraction()
{
}