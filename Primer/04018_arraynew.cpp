// arraynew.cpp -- using the new operator for arrays 

#include <iostream>

int main()
{
	using namespace std;
	double * p3 = new double [3]; // space for 3 doubles
	p3[0] = 0.2; // treat p3 like an array name 
	p3[1] = 0.5;
	p3[2] = 0.8;

	double *p4 = p3; 

	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 + 1; // increment the pointer
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ".\n";
	cout << p4[0] << endl;  
	// p3 = p3 - 1; // point back to beginning 
	// delete [] p3; // free the memory

	cout << p4[0] << endl;  
	// cout << p3[0] << endl; 
	
	int arr2[2][2] {{1,2}, {3,4}};
	cout << arr2[0][1] << endl;

	short tell[10] {17}; // tell an array of 20 bytes 
	cout << tell + 1<< endl; // displays &tell[0]
	cout << &tell + 1 << endl; // displays address of whole array

	short (*pas)[10] = &tell;
	cout << (*pas)[0] << endl; 


 	return 0;
}