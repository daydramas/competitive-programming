#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int f[k + 1][n + 1];
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= k; ++i)
			for (int j = 0; j <= n; ++j)
				if (i == 1 || j == 0) f[i][j] = 1;
				else f[i][j] = (f[i][j - 1] + f[i - 1][n - j]) % M;
		printf("%d\n", f[k][n]);
	}
}