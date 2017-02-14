// init.cpp -- type changes on initialization 
#include <iostream>

 
int main()
{
	using namespace std;
	// cout.setf(ios_base::fixed, ios_base::floatfield); 
	// float tree = 3; // int converted to float 
	// int guess(3.9832); // double converted to int 
	// int debt = 7.2E12; // result not defined in C++ 
	// cout << "tree = " << tree << endl;
	// cout << "guess = " << guess << endl;
	// cout << "debt = " << debt << endl;


	// const int code = 66; 
	// int x = 66;
	// // char c1 {31325}; 
	// char c2 = {66}; 
	// char c3 {code}; 
	// // char c4 = {x}; 
	// x = 31325; 
	// char c5 = x;
	
	// cout << hex; 
	// cout << x << endl; 
	// cout << (int)c5 << endl; 

	unsigned a {'ABCD'};

	cout << hex; 

	cout << a << endl;

	cout << sizeof(a) << endl; 

	auto crat = U'\U00002155';
	// char32_t d = U'\U0010FFFF';

	cout << crat << endl; 

	return 0;
} 