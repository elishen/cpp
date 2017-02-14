#include <iostream>
using namespace std;

void swapr(int & a, int & b) // use references 
{
	int temp;
	temp = a; a = b;
	b = temp;
}

double refcube(const double &ra) 
{
	return ra * ra * ra; 
}

int main(){

	long a = 3, b = 5; 
	//swapr(a, b);

	refcube(a);
	
	return 0;

}
