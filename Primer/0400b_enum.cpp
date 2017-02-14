
#include <iostream>
#include <cstring> 

int main()
{
	using namespace std; 

	enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
	spectrum band = blue; 
	// spectrum band2 = 1; //invlid
	int i = band;
	spectrum band2 = (spectrum)1; 
	spectrum band3 = (spectrum)20009; 
	
	int i2 = band + band2;
	// band3 = band + band2; 

	cout << band << " " << i << " " << band2 << " " << band3 << " " << i2 << endl; 

	enum bigstep{first, second = 0, third};

	bigstep a1 = first;
	bigstep a2 = second;
	bigstep a3 = third;

	cout << a1 << endl; 
	cout << a2 << endl; 
	cout << a3 << endl; 	

	return 0;
}