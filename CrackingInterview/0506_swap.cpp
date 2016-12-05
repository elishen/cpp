#include <map> 
#include <stack>
#include <string>
#include <algorithm>
#include <iostream> 
#include <bitset> 

using namespace std;

int main()
{
	int a;
	cin >> a; 

	int b = ((a & 0xaaaaaaaa) >> 1) | ((a & 0x55555555) << 1);

	cout << bitset<16>(a) << endl; 

	cout << bitset<16>(b) << endl;

}