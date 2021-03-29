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

int n, k, ss[N], dep, cc[N]{1};
bool vv[N];
long long ans = 0;

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
	if (d > k) return;
	dep = max(dep, d);
	ans += cc[k - d];
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			_count(y->x, x, d + 1);
}

void _fill(int x, int p, int d = 1) {
	if (d > k) return;
	cc[d]++;
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
	fill(cc + 1, cc + dep + 1, 0);
	for (L *y = aa[c]; y; y = y->next)
		if (!vv[y->x])
			decomp(y->x);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		link(x, y), link(y, x);
	}
	decomp();
	cout << ans << '\n';
}