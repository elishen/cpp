// address.cpp -- using the 

#include <iostream>
int main()
{
	using namespace std; 
	int donuts = 6; 
	double cups = 4.5;
	// NOTE: you may need to use unsigned (&donuts) // and unsigned (&cups)
	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl; 
	
	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl; 
	return 0;
}