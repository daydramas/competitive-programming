#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

// Binary Indexed Tree (a.k.a. Fenwick Tree)

int bit[N];

int query(int i) {
	int ans = 0;
	while (i > 0) {
		ans ^= bit[i];
		i -= i & (-i);
	}
	return ans;
}

void update(int i, int x) {
	while (i < N) {
		bit[i] ^= x;
		i += i & (-i);
	}
}

int n, q, a[N];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		update(i, a[i]);
	}
	for (int i = 1, j, k; i <= q; ++i) {
		scanf("%d%d", &j, &k);
		printf("%d\n", query(k) ^ query(j - 1));
	}
}