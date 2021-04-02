#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int S = 1 << 18;

int n, q, a[N];
long long ll[S << 1], rr[S << 1], aa[S << 1], ss[S << 1];

void pull(int k) {
	ll[k] = max(ll[k << 1], ss[k << 1] + ll[k << 1 | 1]);
	rr[k] = max(rr[k << 1 | 1], ss[k << 1 | 1] + rr[k << 1]);
	aa[k] = max({aa[k << 1], aa[k << 1 | 1], rr[k << 1] + ll[k << 1 | 1]});
	ss[k] = ss[k << 1] + ss[k << 1 | 1];
}

void build(int k, int l, int r) {
	if (l == r) {
		aa[k] = ll[k] = rr[k] = max(0, a[l]);
		ss[k] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(k << 1, l, m);
	build(k << 1 | 1, m + 1, r);
	pull(k);
}
void update(int p, int x, int k, int l, int r) {
	if (l == r) {
		aa[k] = ll[k] = rr[k] = max(0, a[l]);
		ss[k] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, x, k << 1, l, m); 
	else update(p, x, k << 1 | 1, m + 1, r);
	pull(k);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 0, x, y; i < q; ++i) {
		scanf("%d%d", &x, &y);
		update(x, a[x] = y, 1, 1, n);
		printf("%lld\n", aa[1]);
	}
}