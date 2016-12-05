#include <map> 
#include <string>
#include <algorithm>
#include <iostream> 

using namespace std;

int main()
{
	string s;
	cin >> s;
	char prev = '\0';

	sort(s.begin(), s.end());

	for (char& c:s){
		if (prev != c){
			prev = c;
		} else {
			cout << "False: " << c << endl;
		}
	}

	cout << "True" << endl;
	return 0;

}