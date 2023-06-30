#pragma once

#include<iostream>

using namespace std;

class String
{
protected:
	int m_size;
	int m_capacity;

	char* str;
public:

	void print();

	String();
	String(const string str);
	String(const char* str);
	String(int size, char symbol);
	

	int size();
	int capacity();
	void clear();
	char at(int index);
	void insert(char symb);
	void insert(int index, char symb);
	void insert(int index, char symb, int count);
	void insert(int index, const char* substr);
	void insert(int index, const String substr);
	size_t find(const String substr);
	size_t rfind(const String substr);
	
};

