#include"String.h"

int main() {
	/*String str;
	cout << str.str << endl;*/

	/*String str("Hello, World....");
	cout << str.at(9) << endl;*/

	/*String str(20, '6');
	str.clear();*/
	
	/*String str("Hi, ");
	str.insert('M');*/

	String str("Hello, World...");
	str.insert('!');
	str.insert(5, '.');

	cout << str.str << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	





}