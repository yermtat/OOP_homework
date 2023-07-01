#include "String.h"


// helping function
int count_capacity(const int& size) {
	return size <= 15 ? 15 : ((size / 15) + 1) * 15 + 1;
}

#pragma region constructors

String::String() : str(new char[16]), m_size(0), m_capacity(15) {
	str[m_size] = '\0';
}

String::String(const string str) : m_size(str.size()), m_capacity(str.capacity()) {
	this->str = new char[m_capacity];
	const char* tmp = new char[m_capacity];
	tmp = str.c_str();
	strcpy_s(this->str, m_capacity + 1, tmp);
}

String::String(const char* str) : m_size(strlen(str)) {

	m_capacity = count_capacity(m_size);

	this->str = new char[m_capacity + 1];

	strcpy_s(this->str, m_capacity + 1, str);

}

String::String(int size, char symbol) : m_size(size), m_capacity(count_capacity(size)) {
	str = new char[m_capacity + 1];

	str[m_size] = NULL;
	_strnset_s(str, m_capacity + 1, symbol, m_size);
	
}


String::String(const String& str) : m_size(str.m_size), m_capacity(str.m_capacity), 
	str(new char[str.m_capacity + 1]) 
{
	strcpy_s(this->str, m_capacity + 1, str.str);
}

String::String(String&& str) : m_size(str.m_size), m_capacity(str.m_capacity), str(str.str) {

	str.m_size = 0;
	str.m_capacity = 0;
	str.str = nullptr;
	cout << "it worked" << endl;
}

#pragma endregion


#pragma region methods

int String::size() {
	return m_size;
}

int String::capacity() {
	return m_capacity;
}

void String::clear() {
	m_size = 0;
	str[m_size] = NULL;
}

char& String::at(int index) {
	return str[index];
}

String& String::insert(char symb) {

	if (m_size < m_capacity) {
		str[m_size] = symb;
		str[++m_size] = NULL;
	}
	else if (m_size = m_capacity) {
		m_capacity = count_capacity(m_size + 1);
		
		char* tmp = new char[m_capacity];

		for (size_t i = 0; i < m_size; i++)
		{
			tmp[i] = str[i];
		}
		tmp[m_size++] = symb;
		tmp[m_size] = NULL;
		delete[] str;
		str = tmp;
	}

	return *this;
}

String& String::insert(int index, char symb) {

	if (m_size == m_capacity) {
		m_capacity = count_capacity(m_size + 1);
	}

	char* tmp = new char[m_capacity];

	for (size_t i = 0; i < index; i++)
	{
		tmp[i] = str[i];
	}

	tmp[index] = symb;
	m_size++;

	for (size_t i = index + 1; i <= m_size; i++)
	{
		tmp[i] = str[i - 1];
	}

	delete[] str;
	str = tmp;

	return *this;
}

String& String::insert(int index, char symb, int count) {

	if (m_size + count > m_capacity) {
		m_capacity = count_capacity(m_size + count);
	}

	char* tmp = new char[m_capacity];

	for (size_t i = 0; i < index; i++)
	{
		tmp[i] = str[i];
	}

	for (size_t i = index; i < index + count; i++)
	{
		tmp[i] = symb;
	}

	for (size_t i = index; i <= m_size; i++)
	{
		tmp[i + count] = str[i];
	}

	m_size += count;
	delete[] str;
	str = tmp;

	return *this;
}

String& String::insert(int index, const char* substr) {

	int sublen = strlen(substr);

	if (m_size + sublen > m_capacity) {
		m_capacity = count_capacity(m_size + sublen);
	}

	char* tmp = new char[m_capacity];

	for (size_t i = 0; i < index; i++)
	{
		tmp[i] = str[i];
	}

	tmp[index] = NULL;

	strcat_s(tmp, m_capacity, substr);

	for (size_t i = index; i <= m_size; i++)
	{
		tmp[i + sublen] = str[i];
	}

	m_size += sublen;
	delete[] str;
	str = tmp;

	return *this;
}

String& String::insert(int index, const String substr) {

	this->insert(index, substr.str);

	return *this;
}

size_t String::find(const String substr) {

	char* ptr = strstr(str, substr.str);

	for (size_t i = 0; i < m_size; i++)
	{
		if (str + i == ptr) {
			return i;
		}
	}

	return -1;
}

size_t String::rfind(const String substr) {

	_strrev(str);

	char* ptr = strstr(str, substr.str);

	for (size_t i = 0; i < m_size; i++)
	{
		if (str + i == ptr) {
			_strrev(str);
			return m_size - 1 - i;
		}
	}

	_strrev(str);
	return -1;
}

#pragma endregion


#pragma region operators

String operator+(const String& left, const String& right) {

	char* tmp = new char[left.m_capacity + 1];
	strcpy_s(tmp, left.m_capacity + 1, left.str);

	strcat_s(tmp, left.m_capacity + 1, right.str);

	return String(tmp);

}

String& String::operator+=(const String& substr) {
	
	if (m_size + substr.m_size > m_capacity) {

		m_capacity = count_capacity(m_size + substr.m_size);
		char* tmp = new char[m_capacity + 1];
		strcpy_s(tmp, m_capacity + 1, str);

		delete[] str;
		str = tmp;
	}

	m_size += substr.m_size;
	strcat_s(str, m_capacity + 1, substr.str);

	return *this;
}

String& String::operator+=(const char* substr) {

	int sublen = strlen(substr);

	if (m_size + sublen > m_capacity) {

		m_capacity = count_capacity(m_size + sublen);
		char* tmp = new char[m_capacity + 1];
		strcpy_s(tmp, m_capacity + 1, str);

		delete[] str;
		str = tmp;
	}

	m_size += sublen;

	strcat_s(str, m_capacity + 1, substr);

	return *this;
}

char& String::operator[] (size_t index) {

	return str[index];
}

String& String::operator= (const String& str) {

	if (this == &str) {
		return *this;
	}

	if (m_capacity < str.m_capacity) {
		m_capacity = str.m_capacity;
		delete[] this->str;
		this->str = new char[m_capacity + 1];
	}

	m_size = str.m_size;
	strcpy_s(this->str, m_capacity + 1, str.str);

	return *this;
}

String& String::operator= (const char* str) {

	int sublen = strlen(str);

	if (m_capacity < sublen) {
		m_capacity = count_capacity(sublen);
		delete[] this->str;
		this->str = new char[m_capacity + 1];
	}

	m_size = sublen;
	strcpy_s(this->str, m_capacity + 1, str);

	return *this;
}

bool operator== (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str) == 0;
}
bool operator== (const char* lhs, const String& rhs) {
	return strcmp(lhs, rhs.str) == 0;
}
bool operator== (const String& lhs, const char* rhs) {
	return strcmp(lhs.str, rhs) == 0;
}


bool operator!= (const String& lhs, const String& rhs) {
	return !(strcmp(lhs.str, rhs.str) == 0);
}
bool operator!= (const char* lhs, const String& rhs) {
	return !(strcmp(lhs, rhs.str) == 0);
}
bool operator!= (const String& lhs, const char* rhs) {
	return !(strcmp(lhs.str, rhs) == 0);
}


bool operator<  (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str) == -1;
}
bool operator<  (const char* lhs, const String& rhs) {
	return strcmp(lhs, rhs.str) == -1;
}
bool operator<  (const String& lhs, const char* rhs) {
	return strcmp(lhs.str, rhs) == -1;
}


bool operator<= (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str) <= 0;
}
bool operator<= (const char* lhs, const String& rhs) {
	return strcmp(lhs, rhs.str) <= 0;
}
bool operator<= (const String& lhs, const char* rhs) {
	return strcmp(lhs.str, rhs) <= 0;
}


bool operator>  (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str) == 1;
}
bool operator>  (const char* lhs, const String& rhs) {
	return strcmp(lhs, rhs.str) == 1;
}
bool operator>  (const String& lhs, const char* rhs) {
	return strcmp(lhs.str, rhs) == 1;
}


bool operator>= (const String& lhs, const String& rhs) {
	return strcmp(lhs.str, rhs.str) >= 0;
}
bool operator>= (const char* lhs, const String& rhs) {
	return strcmp(lhs, rhs.str) >= 0;
}
bool operator>= (const String& lhs, const char* rhs) {
	return strcmp(lhs.str, rhs) >= 0;
}

ostream& operator<< (ostream& output, const String& str) {
	output << str.str;
	return output;
}

istream& operator>> (istream& input, String& str) {
	char* tmp = new char[str.m_capacity + 1];
	input >> tmp;

	String str_tmp(tmp);
	str = str_tmp;
	return input;
}

#pragma endregion
