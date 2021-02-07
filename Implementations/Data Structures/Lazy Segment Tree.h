template<class T, int SZ> struct LazySegTree {
	T tree[SZ * 2], lazy[SZ * 2];
	void update(int L, int R, T inc) {
		update(L, R, inc, 1, 0, SZ - 1);
	}
	T query(int L, int R) {
		return query(L, R, 1, 0, SZ - 1);
	}
	void push(int id, int lo, int hi) {
		tree[id] += (hi - lo + 1) * lazy[id];
		if(lo != hi) {
			lazy[id * 2] += lazy[id]
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
	void update(int L, int R, T inc, int id, int lo, int hi) {
		push(id, lo, hi);
		if(L > hi || R < lo) return;
		if(L <= lo && hi <= R) { lazy[id] += inc; push(id, lo, hi); return; }
		if(lo == hi) return; int mi = (lo + hi) / 2;
		update(L, R, inc, id * 2, lo, mi);
		update(L, R, inc, id * 2 + 1, mi + 1, hi);
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}
	T query(int L, int R, int id, int lo, int hi) {
		push(id, lo, hi);
		if (L <= lo && hi <= R) return tree[id];
		if (L > hi || R < lo) return 0;
		int mi = (lo + hi) / 2;
		return query(L, R, id * 2, lo, mi) + query(L, R, id * 2 + 1, mi + 1, hi);
	}
};