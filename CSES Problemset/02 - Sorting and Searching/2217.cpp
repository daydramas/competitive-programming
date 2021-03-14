/**
 * CSES Collecting Numbers II
 * https://cses.fi/problemset/task/2217
 * Created on 2021-03-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

template<class T> struct segment_tree {
	int n; vector<T> tree; T id;

	T combine(const T& a, const T& b) {
		return a + b;
	}
	
	segment_tree(int n = 0, T id = 0) : n(n), id(id) {
		tree.assign(n << 1, id);
	}

	void pull(int i) {
		tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
	}
	
	void update(int i, T x) {
		tree[i += n] = x;
		for (i >>= 1; i; i >>= 1)
			pull(i);
	}
	
	T query(int l, int r) {
		T ret = id;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = combine(ret, tree[l++]);
			if (r & 1) ret = combine(ret, tree[--r]);
		}
		return ret;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	static int a[N], b[N];

	cin >> n >> m;
	segment_tree<int> tree(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; b[--a[i]] = i;
	}
	auto pull = [&](int i) -> void {
		if (i <= 0 || i >= n) ;
		else if (b[i] < b[i - 1]) {
			tree.update(i, 1);
		} else {
			tree.update(i, 0);
		}
	};
	for (int i = 1; i < n; ++i) {
		pull(i);
	}
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y; --x, --y;
		swap(b[a[x]], b[a[y]]);
		pull(a[x]), pull(a[x] + 1);
		pull(a[y]); pull(a[y] + 1);
		swap(a[x], a[y]);
		cout << 1 + tree.tree[1] << '\n';
	}

}