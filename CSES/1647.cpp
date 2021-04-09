#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int M = 18;

int n, q, aa[N], ll[N], tt[N][M];

void init() {
	ll[1] = 0;
	for (int i = 2; i < N; ++i) {
		ll[i] = ll[i / 2] + 1;
	}
	for (int i = 0; i < n; i++)
    	tt[i][0] = aa[i];

	for (int j = 1; j <= M; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			tt[i][j] = min(tt[i][j-1], tt[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int j = ll[r - l + 1];
	return min(tt[l][j], tt[r - (1 << j) + 1][j]);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", aa + i);
	init();
	for (int i = 0, a, b; i < q; ++i) {
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a - 1, b - 1));
	}
}