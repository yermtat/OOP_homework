#pragma once

#include<iostream>
#include<queue>
#include<ctime>

using namespace std;

struct Client {
	char name[50];
	int pages;
	struct tm time;

};

class Printer
{	queue <Client> documents;
public:
	Printer() {}
	Printer(Client document);
	void addClient(Client document);

	void Print();

};

