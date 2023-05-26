#pragma once
#include<iostream>

using namespace std;

/*������� �1
		���������� ����� ��������.���������� ������� � ���������� - ������ ������ : ���, ���� ��������, ���������� �������,
		�����, ������, �������� �������� ���������, ����� � ������(���
			��������� ������� ���������), ����� ������.���������� ������� - ����� ������ ��� ����� ������, ������ ������, ����������
		��������� ��� ������� � ��������� ���������� - ������.*/

#define ulong unsigned long long

class Student
{
private:
	ulong phone_number;
	ulong date_of_birth;
public:
	char name[50];
	char surname[50];
	char fathers_name[50];
	char city[50];
	char country[50];
	char school_name[50];
	char school_city[50];
	char school_country[50];
	int group_number;

	ulong get_phone_number();
	void set_phone_number(ulong number);
	ulong get_date_of_birth();
	void set_date_of_birth(ulong date);

	void setInfo();
	void getInfo();

};
