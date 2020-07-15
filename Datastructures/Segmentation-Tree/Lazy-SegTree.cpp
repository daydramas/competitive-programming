struct lazySegTree {

	int n;
	vector<int> st, lz;

	lazySegTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		lz.assign(4*n, 0);
		build(1, 1, n);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = a[L];
			return;
		}
		build(left(id), L, (L+R)/2);
		build(right(id), (L+R)/2+1, R);
		st[id] = st[left(id)] + st[right(id)];
	}

	void propagate(int id, int L, int R) {
		st[id] += lz[id] * (R-L+1);
		if (L!=R) {
			lz[left(id)] += lz[id];
			lz[right(id)] += lz[id];
		}
		lz[id] = 0;
	}

	void update(int id, int L, int R, int l, int r, int value) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return;
		if (l <= L && R <= r) {
			lz[id] += value;
			propagate(id, L, R);
			return;
		}
		if (L == R) return;
		update(left(id), L, (R+L)/2, l, r, value);
		update(right(id), (R+L)/2+1, R, l, r, value);
		st[id] = st[left(id)] + st[right(id)];
	}

	void update(int L, int R, int value) {
		update(1, 1, n, L, R, value);
	}

	int get(int id, int L, int R, int l, int r) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return get(left(id), L, (R+L)/2, l, r) + get(right(id), (R+L)/2+1, R, l, r);
	}

	int get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};
