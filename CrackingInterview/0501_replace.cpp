#include <map> 
#include <string>
#include <algorithm>
#include <iostream> 
#include <bitset> 

using namespace std;

int main()
{
	int a, b;
	int i, j;
	i = 2; 
	j = 6; 

	cin >> a;
	cin >> b;

	bitset<16> a2(a);
	bitset<16> b2(b);

	cout << a2 << endl;
	cout << b2 << endl;

	int max = ~0;
	cout << "Max: " << max << endl; 

	int left = max - (( 1 << j) - 1); 
	int right = (1 << i) - 1;

	int mask = left | right; 

	int res = ( a & mask ) | (b << i);

	bitset<16> res2(res);

	cout << "Result:" << res2 << endl; 

}