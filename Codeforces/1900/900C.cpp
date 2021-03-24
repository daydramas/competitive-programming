#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

int n, m, a[N], t[N << 1], L[N], R[N];

void init() {
	memset(t, 0, sizeof(t));
}

void update(int i, int x, int k = 1, int l = 0, int r = N - 1) {
	if (l == r) { t[k] = max(t[k], x); return; }
	int m = (l + r) >> 1;
	if (i <= m) update(i, x, k << 1, l, m);
	else update(i, x, k << 1 | 1, m + 1, r);
	t[k] = max(t[k << 1], t[k << 1 | 1]);
}

int query(int ql, int qr, int k = 1, int l = 0, int r = N - 1) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return t[k];
	int m = (l + r) >> 1;
	int q1 = query(ql, qr, k << 1, l, m);
	int q2 = query(ql, qr, k << 1 | 1, m + 1, r);
	return max(q1, q2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0, l, r; i < n; ++i) {
		cin >> l >> r;
		a[l]++, a[++r]--;
	}
	for (int i = 2; i <= m; ++i)
		a[i] += a[i - 1];
	init();
	for (int i = 1; i <= m; ++i) {
		L[i] = query(0, a[i]) + 1;
		update(a[i], L[i]);
	}
	init();
	for (int i = m; i >= 1; --i) {
		R[i] = query(0, a[i]) + 1;
		update(a[i], R[i]);
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
		ans = max(ans, L[i] + R[i] - 1);
	cout << ans << '\n';
}