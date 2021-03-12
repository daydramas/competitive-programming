template<class T, int N> struct segment_tree {
	T tree[N * 2];

	void init() {
		#define mem(a, x) memset(a, x, sizeof(a))
		mem(tree, 0);
		#undef mem
	}

	void _update(int i, T x, int k, int l, int r) {
		if (l == r) { tree[k] = x; return; }
		int m = (l + r) / 2;
		if (i <= m) _update(i, x, k * 2, l, m); 
		else _update(i, x, k * 2 + 1, m + 1, r);
		tree[k] = tree[k * 2] + tree[k * 2 + 1];
	}

	T _query(int ql, int qr, int k, int l, int r) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && qr >= r) return tree[k];
		int m = (l + r) / 2;
		T q1 = _query(ql, qr, k * 2, l, m);
		T q2 = _query(ql, qr, k * 2 + 1, m + 1, r);
		return q1 + q2;
	}

	void update(int i, T x) {
		_update(i, x, 1, 0, N - 1);
	}

	T query(int ql, int qr) {
		return _query(ql, qr, 1, 0, N - 1);
	}
};