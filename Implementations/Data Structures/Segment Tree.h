template<class T, int SZ> struct SegTree {
	T tree[SZ * 2];
	void update(int pos, T val) {
		update(pos, val, 1, 0, SZ - 1);
	}
	T query(int L, int R) {
		return query(L, R, 1, 0, SZ - 1);
	}
	void update(int pos, T val, int id, int lo, int hi) {
		if (lo == hi) tree[id] = val;
		int mi = (lo + hi) / 2;
		if (pos <= mi) update(pos, val, id * 2, lo, mi);
		else update(pos, val, id * 2 + 1, mi + 1, hi);
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}
	T query(int L, int R, int id, int lo, int hi) {
		if (L <= lo && hi <= R) return tree[id];
		if (L > hi || R < lo) return 0;
		int mi = (lo + hi) / 2;
		return query(L, R, id * 2, lo, mi) + query(L, R, id * 2 + 1, mi + 1, hi);
	}
};