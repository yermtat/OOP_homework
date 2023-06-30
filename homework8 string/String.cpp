#include "String.h"

void String::print() {
	cout << str << endl;
}

int count_capacity(const int& size) {
	return size <= 15 ? 15 : ((size / 15) + 1) * 15 + 1;
}


String::String() : str(new char[15]), m_size(0), m_capacity(15) {
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

char String::at(int index) {
	return str[index];
}

void String::insert(char symb) {

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
}

void String::insert(int index, char symb) {

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
}

void String::insert(int index, char symb, int count) {

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
}

void String::insert(int index, const char* substr) {

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
}

void String::insert(int index, const String substr) {

	this->insert(index, substr.str);
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

