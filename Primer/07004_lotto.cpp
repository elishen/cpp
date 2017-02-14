#include <iostream>
using namespace std;

int main(){

	double total, choices; 

	// while (!cin.fail()){
	// 	cin >> total;
	// 	cout << total << endl;
	// }

	// while ((cin >> total >> choices) && choices < total){
	// 	cout << total << " " << choices << endl; 
	// }


	int arr[3] {1, 2, 3};

	cout << (int*)arr << endl; 
	cout << (int*)(arr+1) << endl; 

	int *ptr = arr; 

	int **p2 = &ptr;
	cout << (int*)p2 << endl; 
	cout << (int*)(p2+1) << endl; 


	return 0; 
}