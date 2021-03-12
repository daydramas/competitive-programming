template<int N> struct union_find {
	int size[N], parent[N];

	union_find() {
		for (int i = 0; i < N; ++i)
			size[i] = 1, parent[i] = i;
	}

	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		parent[y] = x;
		size[x] += size[y];
		return true;
	}
};