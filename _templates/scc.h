template<int N> struct scc {
	int time, scc[N], id[N], low[N];
	vector<int> adj[N], stack, sccs;

	void init() {
		#define mem(a, x) memset(a, x, sizeof(a))
		mem(scc, -1), mem(id, 0), mem(low, 0);
		stack.clear(), sccs.clear();
		time = 0;
	}
	
	void add_edge(int x, int y) {
		adj[x].push_back(y);
	}

	int search(int x) {
		low[x] = id[x] = ++time;
		stack.push_back(x);
		for (int y : adj[x]) if (scc[y] == -1) {
			low[x] = min(low[x], id[y] ?: search(y));
		}
		if (low[x] == id[x]) {
			sccs.push_back(x);
			for (int y = -1; y != x;) {
				scc[y = stack.back()] = x;
				stack.pop_back();
			}
		}
		return low[x];
	}

	void tarjan(int n) {
		for (int i = 1; i <= n; ++i)
			if (!id[i]) search(i);
		reverse(begin(sccs), end(sccs));
	}
};