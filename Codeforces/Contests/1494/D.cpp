#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N	505

struct cell {
	int i, j;
};


struct DSU {
	int size;
	std::vector<int> set;

	void init(int _size) {
		size = _size;
		set.assign(size + 1, -1);
	}

	int get(int x) {
		if (set[x] < 0)
			return x;
		return set[x] = get(set[x]);
	}

	bool merge(int x, int y) {
		x = get(x), y = get(y);
		if (x == y)
			return false;
		set[x] += set[y];
		set[y] = x;
		return true;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int k; 
	static int a[N][N], b[N], p[N], v[N];

	cin >> k;
	vector<cell> c[5005];
	DSU dsu;
	dsu.init(N);
	for (int i = 1; i <= k; ++i) {
		b[i] = i;
		for (int j = 1; j <= k; ++j) {
			cin >> a[i][j];
			if (i > j) c[a[i][j]].push_back({i, j});
		}
		v[i] = a[i][i];
	}
	sort(b + 1, b + k + 1, [&](int i , int j) {
		return v[i] < v[j];
	});
	int l = k;
	
	for (int w = 1; w <= 5000; ++w) {
		if (!c[w].size()) continue;
		v[++l] = w;
		for(cell q : c[w]) {
			q.i = dsu.get(q.i);
			q.j = dsu.get(q.j);
			if (dsu.merge(l, q.i))
				p[q.i] = l;
			if (dsu.merge(l, q.j))
				p[q.j] = l;
		}
	}
	cout << l << '\n';
	for (int i = 1; i <= l; ++i) {
		cout << v[i] << ' ';
	}
	cout << '\n';
	int ans = -1; 
	for (int i = 1; i <= l; ++i) {
		if (p[i]) {
			// ans.push_back(p[i]);
			// cout << i << ' ' << p[i] << '\n';
		} else ans = i;
	}
	cout << ans << '\n';
	for (int i = 1; i <= l; ++i) {
		if (p[i]) {
			cout << i << ' ' << p[i] << '\n';
		}
	}
}