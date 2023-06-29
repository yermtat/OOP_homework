#include "String.h"

int count_capacity(const int& size) {
	return size <= 15 ? 15 : ((size / 15) + 1) * 15 + 1;
}

String::String() : str(new char[15]), m_size(0), m_capacity(15) {
	str[m_size] = '\0';
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

	char* tmp;

	tmp = new char[m_capacity];

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