template<int N> struct scc {
	int time, comp[N], id[N], low[N];
	vector<int> adj[N], stack, comps;

	void init() {
		#define mem(a, x) memset(a, x, sizeof(a))
		mem(comp, -1), mem(id, 0), mem(low, 0);
		stack.clear(), comps.clear();
		time = 0;
		#undef mem
	}
	
	void add_edge(int x, int y) {
		adj[x].push_back(y);
	}

	int search(int x) {
		low[x] = id[x] = ++time;
		stack.push_back(x);
		for (int y : adj[x]) if (comp[y] == -1) {
			low[x] = min(low[x], id[y] ?: search(y));
		}
		if (low[x] == id[x]) {
			comps.push_back(x);
			for (int y = -1; y != x;) {
				comp[y = stack.back()] = x;
				stack.pop_back();
			}
		}
		return low[x];
	}

	void tarjan(int n) {
		for (int i = 1; i <= n; ++i)
			if (!id[i]) search(i);
		reverse(begin(comps), end(comps));
	}
};