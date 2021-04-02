#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int S = 1 << 18;

int n, a[N];

int tt[S << 1];

void build(int k, int l, int r) {
	tt[k] = r - l + 1;
	if (l == r) { return; }
	int m = (l + r) >> 1;
	build(k << 1, l, m);
	build(k << 1 | 1, m + 1, r);
}
int query(int x, int k, int l, int r) {
	tt[k]--;
	if (l == r) { return l; }
	int m = (l + r) >> 1;
	if (x <= tt[k << 1]) return query(x, k << 1, l, m); 
	else return query(x - tt[k << 1], k << 1 | 1, m + 1, r);
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