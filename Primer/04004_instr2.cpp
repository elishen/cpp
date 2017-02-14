// instr2.cpp -- reading more than one word with getline 

#include <iostream>
#include <cstring> 

int main()
{
	using namespace std; 
	const int ArSize = 20; 
	char name[ArSize]; 
	char dessert[ArSize];
	cout << "Enter your name:\n";
	cin.getline(name, ArSize+10); // reads through newline 
	cout << "Enter your favorite dessert:\n"; 
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	char s[] = "test"; 
	cout << s << endl; 
	cout << sizeof(s) << endl; 
	return 0;
}

