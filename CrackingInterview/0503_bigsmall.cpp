#include <map> 
#include <stack>
#include <string>
#include <algorithm>
#include <iostream> 
#include <bitset> 

using namespace std;

int main()
{
	int n; 
	cin >> n; 

	if (n < 0) {
		cout << -1 << endl;
		return 0;
	}

	if (n == 0) {
		cout << 0 << endl; 
		return 0;
	}

	int tmp = n;
	int idx = 0;

	while ( !tmp & 1 ) {
		tmp >>=1;
		idx++;
	}

	tmp >>= 1;
	idx++;

	while ( tmp & 1){
		tmp >>= 1;
		idx++;
	}
	

	int big = (n ^ (1 << idx) ^ (1 << (idx-1)));

	bitset<16> n2(n);
	cout << n2 << endl;

	bitset<16> big2(big);
	cout << big2 << endl;

	tmp = n;
	idx = 0;

	while ( tmp & 1 ) {
		tmp >>=1;
		idx++;
	}
	
	tmp >>= 1;
	idx++;
	
	while ( ! tmp & 1){
		tmp >>= 1;
		idx++;
	}
	

	int small = (n ^ (1 << idx) ^ (1 << (idx-1)));

	bitset<16> small2(small);
	cout << small2 << endl;

}