#include "Printer.h"

Printer::Printer(Client document) {
	documents.push(document);
}

void Printer::addClient(Client document) {
	documents.push(document);
}

void Printer::Print() {
	
	Client first;

	while (!documents.empty())
	{
		first = documents.front();

		cout << "Printing document of " << first.name << ", pages " << first.pages << ", time: "
			<< first.time.tm_hour << ':' << first.time.tm_min << ':' << first.time.tm_sec << endl;

		documents.pop();
	}
		
	
	cout << "Queue is empty" << endl;
	

}