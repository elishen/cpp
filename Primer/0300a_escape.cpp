#include <iostream>
using namespace std;

int main()
{

	cout << "Line1" << endl;
	cout.put('\v');
	cout << "Line2" ; 
	cout.put('\b');
	cout.put('\a');

	cout.put('\a');
	cout.put('\a');
	return 0;
}
 