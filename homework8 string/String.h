#pragma once

#include<iostream>

using namespace std;

class String
{
	int m_size;
	int m_capacity;

public:
	char* str;
	String();
	String(const char* str);
	String(int size, char symbol);

	int size();
	int capacity();
	void clear();
	char at(int index);
	void insert(char symb);
	void insert(int index, char symb);
	
};

