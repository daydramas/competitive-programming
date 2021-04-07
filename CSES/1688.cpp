#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int D = 18;

int n, q, d[N], up[N][D];

int jump(int x, int k) {
	for (int i = 0; i < D; ++i)
		if (k & (1 << i))
			x = up[x][i];
	return x;
}

int main() {
	scanf("%d%d", &n, &q);
	d[1] = 0; 
	for (int i, j = 2; j <= n; ++j) {
		scanf("%d", &i);
		up[j][0] = i, d[j] = d[i] + 1;
	}
	for (int d = 1; d < D; ++d)
		for (int i = 1; i <= n; ++i)
			up[i][d] = up[up[i][d - 1]][d - 1];
	int x, y;
	while (q--) {
		scanf("%d%d", &x, &y);
		if (d[x] < d[y]) swap(x, y);
		x = jump(x, d[x] - d[y]);
		for (int j = D - 1; j >= 0; --j)
			if (up[x][j] != up[y][j])
				x = up[x][j], y = up[y][j];
		if (x != y) x = up[x][0], y = up[y][0];
		printf("%d\n", x);
	}	
}