#include"String.h"

int main() {
	/*String str;
	cout << str.str << endl;*/

	/*string tmp("lalallal//////;;");
	String str(tmp);*/

	/*String str("Hello, World....");
	cout << str.at(9) << endl;*/

	/*String str(20, '6');
	str.clear();*/
	
	/*String str("Hi, ");
	str.insert('M');*/

	String str("H!!ello, Wo!!rld.");
	/*str.insert('!');
	str.insert(5, '.');
	str.insert(4, '*', 3);
	str.insert(4, "OH");
	
	String str1(" QUACK ");
	str.insert(5, str1);*/

	String substr("!!");
	cout << str.find(substr) << endl;
	cout << str.rfind(substr) << endl;

	str.print();
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	





}