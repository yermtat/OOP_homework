#pragma once
#include<iostream>

/*Задание №2
	Реализуйте класс “Точка”.Необходимо хранить координаты
	x, y, z в переменных - членах класса.Реализуйте функции - члены
	класса для ввода данных, вывода данных, реализуйте аксессоры для доступа к переменным - членам, реализуйте сохранение в
	файл и загрузку данных из файла*/

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