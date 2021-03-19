template<class T, int N, T id = 0> struct lazy_segment_tree {
	T tree[N * 2], lazy[N * 2];

	T combine(const T& a, const T& b) {
		return a + b;
	}

	void init() {
		for (int i = 0; i < N * 2; ++i)
			tree[i] = id, lazy[i] = 0;
	}

	void push(int k, int l, int r) {
		tree[k] += (r - l + 1) * lazy[k];
		lazy[k * 2] += lazy[k];  
		lazy[k * 2 + 1] += lazy[k];
		lazy[k] = 0;
	}

	void _update(int ql, int qr, T x, int k, int l, int r) {
		push(k, l, r);
		if (ql > r || qr < l) return;
		if (ql <= l && qr >= r) { lazy[k] = x; push(k, l, r); return; }
		int m = (l + r) / 2;
		_update(ql, qr, x, k * 2, l, m);
		_update(ql, qr, x, k * 2 + 1, m + 1, r);
		tree[k] = combine(tree[k * 2], tree[k * 2 + 1]);
	}

	T _query(int ql, int qr, int k, int l, int r) {
		push(k, l, r);
		if (ql > r || qr < l) return id;
		if (ql <= l && qr >= r) return tree[k];
		int m = (l + r) / 2;
		T q1 = _query(ql, qr, k * 2, l, m);
		T q2 = _query(ql, qr, k * 2 + 1, m + 1, r);
		return combine(q1, q2);
	}

	void update(int ql, int qr, T x) {
		_update(ql, qr, x, 1, 0, N - 1);
	}

	T query(int ql, int qr) {
		return _query(ql, qr, 1, 0, N - 1);
	}
};