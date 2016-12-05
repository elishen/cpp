
#include <map> 
#include <list> 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream> 
#include <climits> 

using namespace std;


struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() > second.size();
    }
};

int main()
{
	vector<string> v;

	v.push_back("b");
	v.push_back("abd");
	v.push_back("da");

	compare cmp;
	sort(v.begin(), v.end(), cmp);

	for (int i =0; i<3; i++){
		cout << v[i] << endl; 
	}
}