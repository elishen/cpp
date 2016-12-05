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

	stack<int> fib; 
	stack<short> res; 

	int a1 = 0; 
	int a2 = 1; 
	int a3 = a1 + a2;

	while (a3 <= n){
		fib.push(a3);
		a1 = a2;
		a2 = a3;
		a3 = a1+a2;
	}

	while (! fib.empty()){
		// cout << fib.top() << endl;
		if (n >= fib.top()){
			n -= fib.top();
			res.push(1);
		} else {
			res.push(0);
		}
		// cout << n << endl;
		fib.pop();
	}

	while (! res.empty()){
		cout << res.top();
		res.pop();
	}
	cout << endl; 


}