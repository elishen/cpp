#include <map> 
#include <stack>
#include <list> 
#include <string>
#include <algorithm>
#include <iostream> 
#include <bitset> 

using namespace std;

int main()
{
	string s; 
	cin >> s; 

	list<char> lstW;
	list<int> lstN; 

	for (string::iterator it = s.begin(); it != s.end(); ++it){
		if (*it == ' ') {
			continue;
		} else if ('0' <= *it && *it <= '9'){
			lstN.push_back(*it);
			*it = 1;
		} else {
			lstW.push_back(*it);
			*it = 0;
		}
	}

	cout << s << endl; 


}