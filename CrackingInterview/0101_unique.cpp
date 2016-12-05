#include <map> 
#include <string>
#include <iostream> 

using namespace std;

int main()
{
	string s;
	cin >> s;

	map<char, int> strMap;

	for(char& c : s) {
		if (strMap.find(c) == strMap.end()){
			strMap[c] = 1;
		} else {
			cout << "False: " << c << endl;
			return 0;
		}
	}
	cout << "True" << endl;
	return 0;

}