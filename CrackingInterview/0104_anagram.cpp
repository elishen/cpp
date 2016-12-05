#include <map> 
#include <string>
#include <algorithm>
#include <iostream> 

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;

	// sort(s1.begin(), s1.end());
	// sort(s2.begin(), s2.end());

	// if (s1 == s2)
	// 	cout << s1 << " " << s2 << endl;
	// else
	// 	cout << "False" << endl;

	map<char, int> m1;
	bool checked = true;

	if (s1.size() != s2.size()) {
		checked = false;
		cout << "False1" << endl;
		return 0;
	}

	for (char& c : s1){
		if (m1.find(c) != m1.end())
			m1[c]++;
		else
			m1[c] = 1;

		// for (map<char, int>::const_iterator it = m1.begin(); it != m1.end(); ++it){
		// 	cout << it->first << " " << it->second << endl;
		// }
	}

	for (char& c : s2){
		if (m1.find(c) == m1.end()) {
			checked = false;
			cout << "False1" << endl;
			return 0;
		}
		else {
			m1[c]--;
			if (m1[c] < 0){
				checked = false;
				cout << "False1" << endl;
				return 0;
			}
		}
	}

	if (checked)
		cout << "True" << endl;
	else 
		cout << "False" << endl;

}