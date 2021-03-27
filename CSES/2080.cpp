#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

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

int n, k, ss[N]; bool vv[N];
long long ans; int cc[N];

int subtree(int x, int p) {
	ss[x] = 1;
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			ss[x] += subtree(y->x, x);
	return ss[x];
}

int centroid(int dd, int x, int p) {
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p && ss[y->x] >= dd)
			return centroid(dd, y->x, x);
	return x;
}

void solve(int x, int p, int d, bool t) {
	if (d > k) return;
	if (t) cc[d]++;
	else ans += cc[k - d];
	for (L *y = aa[x]; y; y = y->next)
		if (!vv[y->x] && y->x != p)
			solve(y->x, x, d + 1, t);
}

void decomp(int x) {
	int c = centroid(subtree(x, 0) / 2, x, 0);
	vv[c] = 1;
	memset(cc, 0, sizeof(cc)); cc[0] = 1;
	for (L *y = aa[c]; y; y = y->next)
		if (!vv[y->x])
			solve(y->x, c, 1, 0), solve(y->x, c, 1, 1);
	for (L *y = aa[x]; y; y = y->next)
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
	decomp(1);
	cout << ans << '\n';
}