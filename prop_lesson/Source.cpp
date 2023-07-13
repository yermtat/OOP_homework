#include<iostream>
#include<vector> 
#include<array>

using namespace std;

void foo(int* arr) {
	cout << sizeof(arr) << endl;
}

void array_foo(const array<int, 5>& arr) {
	cout << arr.size() << endl;
}

int main() {

	//vector<int> myArr;
	//myArr.push_back(56);
	//cout << myArr[0] << endl;

	//for (size_t i = 0; i < 10; i++)
	//{
	//	myArr.push_back(i);
	//}
	//for (size_t i = 0; i < myArr.size(); i++)
	//{
	//	cout << myArr[i] << ' ';
	//}
	//cout << '\n';
	//for (size_t i = 0; i < 5; i++)
	//{
	//	myArr.pop_back();
	//}
	//for (size_t i = 0; i < myArr.size(); i++)
	//{
	//	cout << myArr[i] << ' ';
	//}
	//cout << '\n';


	//vector<char> myChar{ 'a','b','c','d','e' };
	//for (size_t i = 0; i < myChar.size(); i++)
	//{
	//	cout << myChar[i] << ' ';
	//}
	//myChar.resize(3);
	//cout << '\n';
	//for (size_t i = 0; i < myChar.size(); i++)
	//{
	//	cout << myChar[i] << ' ';
	//}
	//cout << '\n';

	
	/*int arr1[5];
	cout << sizeof(arr1) << endl;
	foo(arr1);*/


	array<int, 5> Arr;
	for (size_t i = 0; i < 5; i++)
	{
		Arr[i] = i;
	}
	for (size_t i = 0; i < 5; i++)
	{
		cout << Arr[i] << ' ';
	}
	cout << '\n';

	array_foo(Arr);




} 