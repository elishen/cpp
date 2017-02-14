#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int M = 1000000007;

int count(vector<vector<int>> tree, int id){

	vector<int> subs = tree[id];

	int kSubTrees = 0;
	bool withLeaf = false;
	int prd = 1;

	for (int i=0; i<subs.size(); i++){
		if (tree[subs[i]].size() > 0){
			kSubTrees++;
			prd *= count(tree, subs[i]) % M;
		} else {
			withLeaf = true;
		}
	}

	cout << "kSubTrees:" << kSubTrees << endl; 
	cout << "prd:" << prd << endl; 
	
	if (kSubTrees == 0) {
		// cout << "A:";
		return 2;
	} else if (withLeaf) {
		// cout << "B:";
		return (prd << 1) % M;
	} else if (kSubTrees == 1) {
		// cout << "C:";
		return prd;
	}
	
	return (prd * (2 - 1/(2<<(kSubTrees-1)))) % M;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int nCities, n;

	cin >> nCities;
	vector<vector<int>> nodes(nCities+1);

	n = nCities -1;

	while (n--){
		int a, b;

		cin >> a >> b;
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}

		nodes[a].push_back(b);
	}

	// cout << "Tree" << endl;
	// for (int i=1; i<nCities+1; i++){
	// 	cout << i << ":";
	// 	for (int j=0; j<nodes[i].size(); j++){
	// 		cout << nodes[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << count(nodes, 1) << endl; 


    return 0;
}


/*
5
1 2
1 3
3 4
3 5

7
1 2
2 3
2 4
4 6
5 6
6 7




*/

