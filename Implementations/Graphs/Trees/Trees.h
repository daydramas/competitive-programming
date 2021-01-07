struct tree {

	int n, logN;
	vector<vector<int> > adj, lca;
	vector<int> sz, depth;

	tree(int n_) {
		n = n_;
		logN = log2(n)+5;
		sz.assign(n+1, 1);
		lca.assign(n+1, vector<int>(logN+5, 0));
		depth.assign(n+1, 0);
		adj.resize(n+1);
	}

	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	void build(int source, int parent) {
		lca[source][0] = parent;
		sz[parent] += sz[source];
		if (source-1) depth[source] = depth[parent]+1;
		for (int child : adj[source]) if (parent != child) {
			build(child, source);
		}
	}

	void buildLCA() {
		for (int i=1; i<logN; i++) {
			for (int j=1; j<=n; j++) {
				lca[j][i] = lca[lca[j][i-1]][i-1];
			}
		}
	}

	int LCA(int u, int v) {
		if(depth[u] > depth[v]) swap(v, u);
		int d = depth[v] - depth[u];
		for(int i = 0; i < logN; i++) {
			if(d & (1 << i)) {
				v = lca[v][i];
			}
		}
		if(u == v) return u;
		for(int i=logN-1; i>=0; i--) {
			if(lca[u][i] != lca[v][i]) {
				u = lca	[u][i];
				v = lca[v][i];
			}
		}
		return lca[u][0];
	}

	void build() {
		build(1, 0);
		buildLCA();
	}

	int getDist(int a, int b) {
		return depth[a]+depth[b]-(2*depth[LCA(a, b)]);
	}

	int getCentroid(int source, int parent, int size) {
		for (int child : adj[source])
			if (source != parent && sz[child] > n/2) return getCentroid(child, source, size);
		return source;2
	}

	int centroidDecomp(int source) {
		int centroid = getCentroid(source, source, sz[source]);
		for (int child : adj[centroid]) {
			adj[child].erase(find(adj[child].begin(),adj[child].end(), centroid));
		}

		// do whatever you need to do

		for (int child : adj[centroid]) {
			adj[centroidDecomp(child)] = centroid;
		}
		return centroid;
	}

};