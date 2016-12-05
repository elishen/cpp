#include <map> 
#include <stack>
#include <string>
#include <algorithm>
#include <iostream> 
#include <bitset> 

using namespace std;

int main()
{
	string s; 

	cin >> s; 

	int nInt = stoi(s.substr(0, s.find(".")));

	double nDec = stod(s.substr(s.find(".")));

	cout << nInt << endl; 
	cout << nDec << endl; 

	stack<int> s1; 

	while (nInt) {
		s1.push(nInt % 2);
		nInt >>= 1;
	}

	while (! s1.empty()){
		cout << s1.top() ;
		s1.pop();
	}

	cout << "." ;

	nDec *= 2;
	int kDec = 1;
	while (nDec && kDec < 32){
		if (nDec > 1){
			cout << 1;
			nDec -= 1;
		} else {
			cout << 0;
		}
		nDec *= 2;
		kDec++;
	}
	cout << endl;

}