struct lazySegTree {

	int n; vi st, lz;

	lazySegTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		lz.assign(4*n, 0);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void propagate(int id, int L, int R) {
		st[id] += lz[id] * (R-L+1);
		if (L!=R) {
			lz[left(id)] += lz[id];
			lz[right(id)] += lz[id];
		}
		lz[id] = 0;
	}

	void upd(int id, int L, int R, int l, int r, int value) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return;
		if (l <= L && R <= r) {
			lz[id] += value;
			propagate(id, L, R);
			return;
		}
		if (L == R) return;
		upd(left(id), L, (R+L)/2, l, r, value);
		upd(right(id), (R+L)/2+1, R, l, r, value);
		st[id] = st[left(id)] + st[right(id)];
	}

	void upd(int L, int R, int value) {
		upd(1, 1, n, L, R, value);
	}

	int qry(int id, int L, int R, int l, int r) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return qry(left(id), L, (R+L)/2, l, r) + qry(right(id), (R+L)/2+1, R, l, r);
	}

	int qry(int L, int R) {
		return qry(1, 1, n, L, R);
	}
};
