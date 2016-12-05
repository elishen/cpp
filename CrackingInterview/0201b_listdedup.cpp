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

	lst.sort();
	lst.reverse();

	for (auto it = lst.cbegin(); it != lst.cend(); it++){
		cout << *it << " ";
	}
	cout << endl; 

	auto crt = lst.begin();
	crt++;

	for (; crt != lst.end(); crt++){
		for (auto it = lst.begin(); it != crt; it++){
			if (*crt == *it){
				lst.erase(crt);
				break;
			}
		}
	}


	for (auto it = lst.cbegin(); it != lst.cend(); it++){
		cout << *it << " ";
	}
	cout << endl; 
	
}