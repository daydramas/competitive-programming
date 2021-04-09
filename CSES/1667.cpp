#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 200010 * 2;

int n, m, qq[N], pp[N], ii = 0, ss = 0, ans[N];

int hh[N], nn[M], tt[M], ei = 0;

inline void link(int i, int j) {
	nn[++ei] = hh[i], hh[i] = ei, tt[ei] = j;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d%d", &a, &b);
		link(a, b), link(b, a);
	}
	qq[ss++] = 1;
	while (ii < ss) {
		int x = qq[ii++];
		for (int j = hh[x], y; j; j = nn[j])
			if (!pp[y = tt[j]]) {
				pp[y] = x;
				qq[ss++] = y;
			}
	}
	if (!pp[n])
		printf("IMPOSSIBLE\n");
	else {
		ii = 0;
		while (n != 1) {
			ans[ii++] = n;
			n = pp[n];
		}
		ans[ii++] = 1;
		printf("%d\n", ii);
		for (int i = ii - 1; i >= 0; --i)
			printf("%d ", ans[i]);
		printf("\n");
	}
}