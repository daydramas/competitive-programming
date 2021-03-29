#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

struct L {
	int x;
	L *next;
} *aa[N];

void link(int i, int j) {
	L *l = new L();
	l->x = j;
	l->next = aa[i];
	aa[i] = l;
};

int n, k1, k2, ss[N], dep, cc[N], bit[N];
bool vv[N];
long long ans = 0;

int query(int i) {
	int ans = 0; ++i;
	while (i > 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}

void update(int i, int x) {
	++i;
	while (i < N) {
		bit[i] += x;
		i += i & (-i);
	}
}

int subtree(int x, int p = 0) {
	ss[x] = 1;
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			ss[x] += subtree(y->x, x);
	return ss[x];
}

int centroid(int dd, int x, int p = 0) {
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p && ss[y->x] >= dd)
			return centroid(dd, y->x, x);
	return x;
}

void _count(int x, int p, int d = 1) {
	if (d > k2) return;
	dep = max(dep, d);
	ans += query(k2 - d) - query(k1 - d - 1);
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			_count(y->x, x, d + 1);
}

void _fill(int x, int p, int d = 1) {
	if (d > k2) return;
	cc[d]++; update(d, 1);
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			_fill(y->x, x, d + 1);
}

void decomp(int x = 1) {
	int c = centroid(subtree(x) / 2, x);
	vv[c] = 1;
	dep = 0;
	for (L *y = aa[c]; y; y = y->next)
		if (!vv[y->x]) {
			_count(y->x, c);
			_fill(y->x, c);
		}
	for (int i = 1; i <= dep; ++i)
		update(i, -cc[i]), cc[i] = 0;
	for (L *y = aa[c]; y; y = y->next)
		if (!vv[y->x])
			decomp(y->x);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k1 >> k2;
	update(0, 1);
	for (int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		link(x, y), link(y, x);
	}
	decomp();
	cout << ans << '\n';
}