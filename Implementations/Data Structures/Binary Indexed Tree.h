template<class T, int SZ> struct BIT {
	T tree[SZ + 1];
	T sum(int i) {
		T r = 0;
		while(i > 0) {
			r += tree[i];
			i -= i & (-i);
		}
		return r;
	}
	T query(int L, int R) {
		return sum(R) - sum(L-1);
	}
	void add(int i, T inc) {
		while(i <= SZ) {
			tree[i] += inc;
			i += i & (-i);
		}
	}
};