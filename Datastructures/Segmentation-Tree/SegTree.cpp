struct segTree {

	int n;
	vector<int> st;

	segTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
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

	void update(int id, int L, int R, int P, int value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) st[id] += value;
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
	}

	void update(int P, int value) {
		update(1, 1, n, P, value);
	}

	int get(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return get(left(id), L, (R+L)/2, l, r) + get(right(id), (R+L)/2+1, R, l, r);
	}

	int get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};
