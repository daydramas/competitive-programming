template<class T> struct segment_tree {
	int n; vector<int> tree; T id;
	
	segment_tree(int n = 0, T id = 0) : n(n), id(id) {
		tree.assign(n << 1, id);
	}

	void pull(int i) {
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	
	void update(int i, T x) {
		tree[i += n] = x;
		for (i >>= 1; i; i >>= 1)
			pull(i);
	}
	
	T query(int l, int r) {
		T ret = 0;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = ret + tree[l++];
			if (r & 1) ret = ret + tree[--r];
		}
		return ret;
	}
};