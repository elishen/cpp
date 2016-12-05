#include <map> 
#include <string>
#include <algorithm>
#include <iostream> 

using namespace std;

int main()
{
	char* s1 = new char[128];
	cin.getline(s1, 128);

	int len1 = strlen(s1);
	int cnt = 0;

	for (char* c = s1; *c; c++){
		if (*c == ' '){
			cnt++;
		}
	}
	
	int len2 = len1 + cnt*2 + 1;
	char * s2 = new char[len2];

	int j = len2 -1;
	int i = len1-1;
	s2[j--] = '\0';

	for (; j >= 0; j--, i--){
		if (s1[i] == ' '){
			s2[j--] = '0';
			s2[j--] = '2';
			s2[j] = '%';
		} else{
			s2[j] = s1[i];
		}
	}

	cout << s1 << endl;
	cout << s2 << endl;

}