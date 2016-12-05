#include <vector>
#include <queue>
#include <iostream> 
#include <cmath> 

using namespace std; 

class cluster
{
public:
        cluster(int p1, int p2, int p3, int p4) : work_load(p1), avg_load(p2), index(p3), num_machine(p4) {}
        int work_load;
        int avg_load;
        int index;
        int num_machine;
};
struct mycmp
{
        bool operator()(cluster& c1, cluster& c2) { return c1.avg_load < c2.avg_load; }
};

vector<int> loadBalance(vector<int>& loads, int b)
{
        vector<int> res(loads.size());
        if (b < loads.size()) return res;
        priority_queue < cluster, vector < cluster >, mycmp> pq;
        for (int i = 0; i < loads.size(); ++i)
                pq.emplace(loads[i], loads[i], i, 1);
        b -= loads.size();
        while (b--)
        {
                auto temp = pq.top();
                pq.pop();
                temp.num_machine++;
                temp.avg_load = temp.work_load / temp.num_machine;
                pq.push(temp);
        }
        while (!pq.empty())
        {
                auto temp = pq.top();
                pq.pop();
                res[temp.index] = temp.num_machine;
        }
        return res;
}


int main()
{
        vector<int> loads = { 200, 450 };
        auto res = loadBalance(loads, 7);
        
        int i = 0;
        int maxLoad = 0; 
        for (vector<int>::iterator it = res.begin(); it!=res.end(); ++it){
                int load = ceil(loads[i] / *it);
                if (load > maxLoad)
                        maxLoad = load; 
                cout << *it << " " << ceil(loads[i] / *it) << endl; 
                i++;
        }

        cout << "Max Load: " << maxLoad << endl; 
        return 0;
}