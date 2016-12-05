#include <map> 
#include <list>
#include <string>
#include <algorithm>
#include <iostream> 
#include <stdlib.h>  


using namespace std;

int main()
{

	list<int> lst;

	for (int i=0; i<20; i++){
		lst.push_back(rand() % 10);
	}

	for (auto it = lst.cbegin(); it != lst.cend(); it++){
		cout << *it << " ";
	}
	cout << endl; 

	map<int, int> m1;

	for (auto it = lst.cbegin(); it != lst.cend(); it++){
		if (m1.find(*it) != m1.end()){
			lst.erase(it);
		} else {
			m1[*it] = 1;
		}
	}

	for (auto it = lst.cbegin(); it != lst.cend(); it++){
		cout << *it << " ";
	}
	cout << endl; 
	
}