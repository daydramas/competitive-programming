#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m, q, *tt;

void pull(int i) {
	tt[i] = max(tt[i * 2], tt[i * 2 + 1]);
}

int query(int i, int x) {
	if (i >= m) {
		tt[i] -= x;
		return i - m + 1;
	}
	int p = query(i * 2 + (tt[i * 2] < x), x);
	pull(i); return p;
}

int main() {
	scanf("%d%d", &n, &q);
	m = 1; while (m < n) m *= 2;
	tt = new int[m * 2];
	for (int i = 0; i < n; ++i)
		scanf("%d", tt + i + m);
	for (int i = m - 1; i >= 1; --i)
		pull(i);
	for (int i = 0, x; i < q; ++i) {
		scanf("%d", &x);
		if (tt[1] < x)
			printf("0 ");
		else
			printf("%d ", query(1, x));
	}
	printf("\n");
}