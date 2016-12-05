#include <vector>
#include <queue>
#include <iostream> 
#include <cmath> 

using namespace std; 


class Cluster{

public: 
	int workloads;
	int nMachines;
	double avgLoad;
	int idx; 

	Cluster(int wl, int m, int i): workloads(wl), nMachines(m), idx(i){
		avgLoad = workloads * 1.0 / m; 
	}

	double addMachine(int m){
		nMachines += m; 
		avgLoad = workloads * 1.0 / nMachines; 
		return avgLoad; 
	}
};

struct Compare{

	bool operator() (Cluster& c1, Cluster& c2){
		return c1.avgLoad < c2.avgLoad; 
	}
};

int maxLoad(int *workloads, int n, int b){

	if (b < n) 
		return -1;

	priority_queue<Cluster, vector<Cluster>, Compare> q; 

	for (int i = 0; i < n; i++){
		q.emplace(workloads[i], 1, i);
	}

	b -= n; 

	while (b--){
		auto c = q.top();
		q.pop();
		c.addMachine(1);
		q.push(c);
	}

	int load = ceil(q.top().avgLoad);

	// while (!q.empty()){
	// 	auto c = q.top(); 

	// 	cout << c.workloads << " " << c.nMachines << " " << c.avgLoad << endl; 
	// 	q.pop();
	// }

	return load;

}

int main()
{
	int n, b; 

	cin >> n; 
	cin >> b;

	int *workloads = new int[n];

	for (int i=0; i<n; i++){
		cin >> workloads[i]; 
	}

	int load = maxLoad(workloads, n, b); 

	cout << load << endl; 

}