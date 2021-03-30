#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

typedef long long ll;
const int MOD = 998244353;

int add(int a, int b) {
	return (a += b) % MOD;
}

int mul(int a, int b) {
	return (a * 1LL * b) % MOD;
}

int binpow(int a, int p, int mod) {
	if (p == 0) return 1;
	int b = binpow(mul(a, a), p / 2, mod);
	if (p & 1) b = mul(b, a);
	return b;
}

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

int inv[N], c[N], d[N];

int32_t main() {
	int n;
	scanf("%d", &n);
	for (int i = 0, k, x; i < n; ++i) {
		scanf("%d", &k); d[i] = k;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &x);
			link(i, x);
			c[x]++;
		}
	}
	for (int i = 0; i < N; ++i)
		inv[i] = binpow(i, MOD - 2, MOD);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (L *j = aa[i]; j; j = j->next)
			ans = add(ans, mul(mul(inv[n], inv[d[i]]), mul(c[j->x], inv[n])));
	printf("%d\n", ans);
}