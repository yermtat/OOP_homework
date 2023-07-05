#include<iostream>

using namespace std;

FILE* file;

class Files
{
public:

	virtual void Display(const char* path)  {
		fopen_s(&file, path, "r");
		fseek(file, 0, SEEK_END);
		int length = ftell(file);
		

		for (int i = 0; i < length; i++)
		{
			fseek(file, i, SEEK_SET);
			cout << (char)getc(file);
		}
		cout << '\n';

		fclose(file);
	}

};

class Ascii_files : public Files {
public:
	void Display(const char* path) override {

		fopen_s(&file, path, "r");
		fseek(file, 0, SEEK_END);
		int length = ftell(file);


		for (int i = 0; i < length; i++)
		{
			fseek(file, i, SEEK_SET);
			cout << getc(file) << ' ';
		}
		cout << '\n';

		fclose(file);
	}
};

class Binary_files : public Files {
public:

	void Display(const char* path) override {
		fopen_s(&file, path, "r");
		fseek(file, 0, SEEK_END);
		int length = ftell(file);

		char* str = new char[10];

		for (int i = 0; i < length; i++)
		{
			fseek(file, i, SEEK_SET);
			_itoa_s(getc(file), str, 10, 2);
			cout << str << ' ';
		}
		cout << '\n';
		fclose(file);
	}

};

class Reverse_files : public Files {
public:

	 void Display(const char* path) override {
		fopen_s(&file, path, "r");
		fseek(file, 0, SEEK_END);
		int length = ftell(file);

		for (int i = 0; i <= length; i++)
		{
			fseek(file, -i, SEEK_END);
			cout << (char)getc(file);
		}
		cout << '\n';

		fclose(file);
	}

};

void foo(Files& text) {
	cout << "There is the text:" << endl;
	text.Display("some_file.txt");
}

int main() {

	Files force;
	/*force.Display("some_file.txt");*/

	Ascii_files ascii_force;
	/*ascii_force.Display("some_file.txt");*/

	Binary_files binary_force;
	/*binary_force.Display("some_file.txt");*/

	Reverse_files reverse_force;
	/*reverse_force.Display("some_file.txt");*/ 

	Files& origin = force;
	Files& ascii = ascii_force;
	Files& binary = binary_force;
	Files& reverse = reverse_force;

	foo(origin);
	//foo(ascii);
	//foo(binary);
	//foo(reverse);
	
}