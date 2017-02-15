#include <list>
#include <mutex>
#include <algorithm> 
#include <iostream> 

using namespace std; 

list<int> lst; 
mutex mut; 

void add_to_list(int new_val)
{
	lock_guard<mutex> guard(mut); 
	lst.push_back(new_val); 
}

bool list_contains(int val)
{
	lock_guard<mutex> guard(mut); 

	return find(lst.begin(), lst.end(), val) != lst.end(); 
}

int main()
{
	add_to_list(1);
	add_to_list(2);
	add_to_list(3);
	add_to_list(4);

	cout << list_contains(3) << endl; 
}