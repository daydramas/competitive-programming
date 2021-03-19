template<class T, int N> struct fenwick_tree {
	T tree[N];

	void init() {
		#define mem(a, x) memset(a, x, sizeof(a))
		mem(tree, 0);
		#undef mem
	}

	T sum(int x) {
		T ret = 0;
		for (; x > 0; x -= x & (-x))
			ret += tree[x];
		return ret;
	}

	void add(int x, T v) {
		for (; x < N; x += x & (-x))
			tree[x] += v;
	}
};