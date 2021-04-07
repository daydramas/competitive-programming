#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int D = 18;

int n, q, up[N][D];

int main() {
	scanf("%d%d", &n, &q);
	for (int i, j = 2; j <= n; ++j) {
		scanf("%d", &i);
		up[j][0] = i;
	}
	for (int d = 1; d < D; ++d)
		for (int i = 1; i <= n; ++i)
			up[i][d] = up[up[i][d - 1]][d - 1];
	int k, x;
	while (q--) {
		scanf("%d%d", &x, &k);
		for (int i = 0; i < D; ++i)
			if (k & (1 << i))
				x = up[x][i];
		printf("%d\n", (x ? x : -1));
	}	
}