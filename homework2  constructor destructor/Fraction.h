#pragma once

/*���������� ����� �����. ���������� ������� ��������� � ����������� � �������� ����������-������.
���������� �������-����� ��� ����� ������ � ����������-����� ��� ���������� �������������� ��������
(��������, ���������, ���������, �������, � �.�)*/

class Fraction
{
public:

	short integer;
	short numenator; // ���������
	short denominator; // �����������

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