#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int S = 1 << 18;

int n, a[N];

int tt[S << 1];

void build(int k, int l, int r) {
	if (l == r) { tt[k] = 1; return; }
	int m = (l + r) >> 1;
	build(k << 1, l, m);
	build(k << 1 | 1, m + 1, r);
	tt[k] = tt[k << 1] + tt[k << 1 | 1];
}
int query(int x, int k, int l, int r) {
	if (l == r) { return tt[k] = 0, l; }
	int m = (l + r) >> 1, p;
	if (x <= tt[k << 1]) p = query(x, k << 1, l, m); 
	else p = query(x - tt[k << 1], k << 1 | 1, m + 1, r);
	tt[k] = tt[k << 1] + tt[k << 1 | 1];
	return p;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		printf("%d ", a[query(x, 1, 1, n)]);
	}
	printf("\n");
}