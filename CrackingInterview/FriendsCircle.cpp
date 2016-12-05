#include <map> 
#include <queue> 
#include <string>
#include <algorithm>
#include <iostream> 
#include <climits> 

using namespace std;

int friendCircles(char* friends, int n){

	int noCircles = 0; 
	queue<int> toVisit;

	for (int i = 0; i<n; i++){
		if (friends[i*n+i] != 'Y') 
			continue;

		noCircles++;
		toVisit.push(i);

		while (!toVisit.empty()){
			int j = toVisit.front();
			toVisit.pop();

			if (friends[j*n+j] != 'Y') 
				continue;

			friends[j*n+j] = 'H';

			for (int k = j+1; k<n; k++) {
				if (friends[j*n+k] == 'Y'){
					toVisit.push(k);
				}
			}

		}

	}
	return noCircles; 
}

int main()
{

	int n;
	cin >> n;

	if (n <= 0){
		cout << 0 << endl; 
		return 0;
	}

	char * friends = new char[n*n];

	for (int i = 0; i<n; i++){
		string line;
		cin >> line; 

		for (int j = 0; j<n; j++){
			friends[i*n+j] = line[j];
		}
	}


	int noCircles = friendCircles((char *)friends, n);

	// for (int i = 0; i<n; i++){
	// 	for (int j = 0; j<n; j++){
	// 		cout << friends[i][j] << " ";
	// 	}
	// 	cout << endl; 
	// }

	cout << noCircles << endl; 

}

/*
4
YYNN
YYYN
NYYN
NNNY
*/



/*
*Union Find 
*
#include <iostream>
#include <vector>

using namespace std;

bool isConnected(vector<int>, int, int);
void Union(vector<int>&, int, int);
int cnt;

int main(int argc, char** argv) {
	int N;
	cin >> N;
	cnt = N;
	vector<vector<char>> matrix(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
	}

	vector<int> id(N);
	for (int i = 0; i < N; ++i) {
		id[i] = i;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (matrix[i][j] == 'Y' and !isConnected(id, i, j)) {
				Union(id, i, j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

bool isConnected(vector<int> id, int p, int q) {
	return id[p] == id[q];
}

void Union(vector<int>& id, int p, int q) {
	int pid = id[p];
	int qid = id[q];
	for (int i = 0; i < id.size(); ++i) {
		if (id[i] == pid) {
			id[i] = qid;
			--cnt;
		}
	}
}



 */
 