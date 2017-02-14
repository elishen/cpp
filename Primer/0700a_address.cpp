// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    
    int *a1, *a2;
    a1 = arr;
    a2 = &arr[0];
    auto a3 = &arr + 1;
    
    a1++;
    a2++;
    a3++;
    
    cout << (a1 - arr) << endl; 
    cout << (a2 - arr) << endl; 
    cout << ((int*)a3 - arr) << endl; 
    
    cout << sizeof arr[0] << endl; 
    
    cout << sizeof a3 << endl; 
}
