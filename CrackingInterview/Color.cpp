#include <string> 
#include <iostream> 
#include <cmath> 

using namespace std; 


int bs2int(string& bs); 

class Color{

public: 
	int rgb[3];
	int *arr_dist;
	int minIndex=-1;

	Color(string bs); 
	int bs2int(string bs);
	void computerDistance();

	const int nColors = 5; 

	const static int vertices[5][3]; 
	const static string names[6]; 

};

const int Color::vertices[5][3] = {
	{255, 0, 0},
	{0, 255, 0},
	{0, 0, 255}, 
	{0, 0, 0},
	{255, 255, 255}
};

const string Color::names[6] =
{
	"Red", "Green", "Blue", "Black", "White", "Ambiguous"
};

Color::Color(string bs){
	for (int i=0; i<3; i++){
		rgb[i] = bs2int(bs.substr(8*i, 8));
	}
	computerDistance();
}

int Color::bs2int(string bs)
{
	int n = 0; 
	for (char c : bs){
		n <<= 1;
		if (c == '1'){
			n++;
		}
	}
	return n;
}

void Color::computerDistance(){

	int minDist = INT_MAX;

	arr_dist = new int[nColors];

	for (int i=0; i<nColors; i++){
		int d = 0;
		int *vertex = (int*)vertices[i];
		for (int j=0; j<3; j++){
			d+= pow(rgb[j] - vertex[j], 2.0); 
		}
		arr_dist[i] = d; 
		if (d < minDist) {
			minDist = d; 
			minIndex = i;
		} else if (d == minDist){
			minIndex = 5;
		}
	}

}

int main()
{
	int n; 
	cin >> n; 

	string *colors = new string[n];

	for (int i=0; i<n; i++){
		cin >> colors[i];
		Color* c = new Color(colors[i]);
	}

	for (int i=0; i<n; i++){
		Color c = colors[i];
		cout << Color::names[c.minIndex] << endl; 
		for (int j=0; j<3; j++){
			cout << "\t" << c.rgb[j] << " ";
		}
		cout << endl; 
		for (int j=0; j<5; j++){
			cout << "\t" << c.arr_dist[j] << " ";
		}
		cout << endl; 

	}
}

/*
10
101111001101011000001011
000111100011101011110100
101010010001110101011101
010100101000001101000010
000110001110100010011101
011111111110110101100101
110001010101011110001010
000010111110011011010111
000000001111111100000110
000000001111111111111111

*/

