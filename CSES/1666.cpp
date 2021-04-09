#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m, c;

struct E {
	int a, b;
} aa[N];

// Disjoint Set Union

int dd[N];

int get(int x) {
	return dd[x] < 0 ? x : dd[x] = get(dd[x]);
}

bool merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return 0;
	dd[x] += dd[y], dd[y] = x;
	return 1;
}

int main() {
	memset(dd, -1, sizeof(dd));

	scanf("%d%d", &n, &m);
	for (int i = 1, a, b; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	c = 0;
	for (int i = 1; i <= n; ++i)
		if (merge(1, i))
			aa[c++] = {1, i};
	printf("%d\n", c);
	for (int i = 0; i < c; ++i)
		printf("%d %d\n", aa[i].a, aa[i].b);
}