#pragma once

#include<iostream>

using namespace std;

class String
{
private:

	int m_size;
	int m_capacity;
	char* str;

public:

	String();
	String(const string str);
	String(const char* str);
	String(int size, char symbol);

	String(const String& str);
	String(String&& str);
	
	~String() {
		delete[] str;
	}

	int size();
	int capacity();
	void clear();
	char& at(int index);
	String& insert(char symb);
	String& insert(int index, char symb);
	String& insert(int index, char symb, int count);
	String& insert(int index, const char* substr);
	String& insert(int index, const String substr);
	size_t find(const String substr);
	size_t rfind(const String substr);

	friend String operator+(const String& left, const String& right);
	String& operator+=(const String& substr);
	String& operator+=(const char* substr);
	char& operator[] (size_t pos); 

	String& operator= (const String& str);
	String& operator= (const char* str);

	friend bool operator== (const String& lhs, const String& rhs); 
	friend bool operator== (const char* lhs, const String& rhs); 
	friend bool operator== (const String& lhs, const char* rhs);
	
	friend bool operator!= (const String& lhs, const String& rhs); 
	friend bool operator!= (const char* lhs, const String& rhs); 
	friend bool operator!= (const String& lhs, const char* rhs);
	
	friend bool operator<  (const String& lhs, const String& rhs); 
	friend bool operator<  (const char* lhs, const String& rhs); 
	friend bool operator<  (const String& lhs, const char* rhs);
	
	friend bool operator<= (const String& lhs, const String& rhs); 
	friend bool operator<= (const char* lhs, const String& rhs); 
	friend bool operator<= (const String& lhs, const char* rhs);
	
	friend bool operator>  (const String& lhs, const String& rhs); 
	friend bool operator>  (const char* lhs, const String& rhs); 
	friend bool operator>  (const String& lhs, const char* rhs);
	
	friend bool operator>= (const String& lhs, const String& rhs); 
	friend bool operator>= (const char* lhs, const String& rhs); 
	friend bool operator>= (const String& lhs, const char* rhs);

	friend ostream& operator<< (ostream& os, const String& str);
	friend istream& operator>> (istream& is, String& str);

	

};

