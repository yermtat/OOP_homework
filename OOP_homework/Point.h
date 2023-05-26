#pragma once
#include<iostream>

/*������� �2
	���������� ����� �������.���������� ������� ����������
	x, y, z � ���������� - ������ ������.���������� ������� - �����
	������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ���������� - ������, ���������� ���������� �
	���� � �������� ������ �� �����*/

using namespace std;

class Point {

	int x;
	int y;
	int z;

public:

	void setX(int new_x);
	void setY(int new_y);
	void setZ(int new_z);

	int getX();
	int getY();
	int getZ();

	void setPoint();
	void getPoint();

	void save();
	void load();

};