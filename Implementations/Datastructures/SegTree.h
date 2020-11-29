struct segTree {

    int n; vi st;

	segTree(int n_) { n = n_, st.assign(4*n, 0); }

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void upd(int id, int L, int R, int P, int value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) st[id] += value;
		if (L == R) return;
		upd(left(id), L, (R+L)/2, P, value);
		upd(right(id), (R+L)/2+1, R, P, value);
	}

	void upd(int P, int value) {
		upd(1, 1, n, P, value);
	}

	int qry(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return qry(left(id), L, (R+L)/2, l, r) + qry(right(id), (R+L)/2+1, R, l, r);
	}

	int qry(int L, int R) {
		return qry(1, 1, n, L, R);
	}
};
