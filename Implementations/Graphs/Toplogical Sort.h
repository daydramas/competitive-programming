#include <vector>
#include <queue>
using namespace std;

template<int SZ> struct TopoSort {
	int N; vector<int> weight;
	vector<vector<int>> graph; 
	TopoSort(int N = 0) : N(N), weight(N+1), graph(N+1) {}
	void addEdge(int a, int b) {
		graph[a].push_back(b); 
		weight[b]++;
	}
	vector<int> sort(int N) {
		queue<int> q; vector<int> res;
		for(int i=1; i<=N; i++) if(!weight[i]) q.push(i);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			res.push_back(x);
			for(int y : graph[x]) if(!--weight[y]) q.push(y);
		}
		return res;
	}
};