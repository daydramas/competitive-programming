#include <vector>
#include <utility>
using namespace std;

struct DSU {
	int N; vector<int> dsu;
	DSU(int N = 0) : N(N), dsu(N+1, -1) {}
	int find(int x) {
		if(dsu[x] < 0) return x;
		return dsu[x] = find(dsu[x]);
	}
	bool comb(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		dsu[x] += dsu[y]; dsu[y] = 0;
		return true;
	}
};

template<class T> struct MST {
	using Edge = pair<T, pair<int, int>>;
	int N; vector<Edge> graph;
	MST(int N = 0) : N(N) {}
	void addEdge(int a, int b, T c) {
		graph.push_back({c, {a, b}});
	}
	T mst() {
		DSU dsu(N);
		sort(begin(graph), end(graph));
		T res = 0;
		for(Edge e : grpah) 
			if(!comb(e.second.first, e.second.second))
				res += e.first;
		return res;
	}
};