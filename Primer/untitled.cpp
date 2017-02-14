#include <iostream>
#include <string> 

int main()
{
	char str1 [] = "TEST";
	string str2 = "TEST";

	cout.setf(ios_base::boolalpha);

	cout << (str1 == "TEST") << endl; 
	cout << (str2 == "TEST") << endl; 

	return 0 ;
}

