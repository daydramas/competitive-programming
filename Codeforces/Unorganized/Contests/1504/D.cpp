#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, c[N][N];

int main() {
	scanf("%d", &n);
	int op = n * n;
	vector<int> tp(4);
	while (op--) {
		int t; cin >> t;
		auto cnt = [&](int i, int j, int l) {
			int r = 0;
			if (i + 1 > n || c[i + 1][j] != l) r++;
			if (i - 1 < 1 || c[i - 1][j] != l) r++;
			if (j + 1 > n || c[i][j + 1] != l) r++;
			if (j - 1 < 1 || c[i][j - 1] != l) r++;
			return r;
		};
		int pi = 0, pj = 0, pk = 0x3f, pl = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (c[i][j]) continue;
				for (int l = 1; l <= 3; ++l) {
					if (l == t) continue;
					int f = cnt(i, j, l);
					if (f == 4) {
						// if (pk > 10 || tp[l] < tp[pl]) {
							pk = f;
							pi = i;
							pj = j;
							pl = l;
						// }
					}
				}
			}
		c[pi][pj] = pl;
		tp[pl]++;
		assert(pi != 0 && pj != 0);
		printf("%d %d %d\n", pl, pi, pj);
		fflush(stdout);
	}
}