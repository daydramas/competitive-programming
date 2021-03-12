template<class T, int N> struct fedwick_tree {
	T tree[N];

	void init() {
		#define mem(a, x) memset(a, x, sizeof(a))
		mem(tree, 0);
	}

	T sum(int x) {
		T ret = 0;
		for (; ~x; x -= x & (-x))
			ret += tree[x];
		return ret;
	}

	void add(int x, T v) {
		for (; x < N; x += x & (-x))
			tree[x] += v;
	}
};