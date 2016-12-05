#include <map> 
#include <string>
#include <algorithm>
#include <iostream> 

using namespace std;

int main()
{
	char s[128];
//	char* s = new char[128];
	cin >> s;
	
	int len =strlen(s);
	int end = 1;

	if (*s and len > 1){
		for (int i = 1; i < len; i++){
			int j;
			for (j = 0; j < end; j++){
				if (s[i] == s[j]) break;
			}
			if (j == end){
				s[end] = s[i];
				end++;
			}
			cout << s << endl;
		}
		s[end] = 0;
	}

	cout << s << endl;
}