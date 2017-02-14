#include <iostream>

 
int main()
{
	using namespace std;

	short things[] = {1, 5, 3, 8};
	int num_elements = sizeof things / sizeof (short);

	cout << things << endl; 

	cout << num_elements << endl; 

	char dog[8] = { 'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'};
	char cat[8] = { 'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'};

	cout << dog << endl; 

	return 0;

}
