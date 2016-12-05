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
	
	char* end = s;
	char* bgn = s;
	char tmp;

	if (bgn){
		while (*end) ++end;
		--end;

		while (bgn < end){
			tmp = *bgn;
			*bgn++ = *end;
			*end-- = tmp;
		}
	}

	cout << s << endl;
}