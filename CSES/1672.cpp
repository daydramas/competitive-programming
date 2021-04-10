#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m, q;

long long dd[N][N];

void FloydWarshall() {
	for (int k = 1; k <= n; ++k)
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j)
		dd[i][j] = min(dd[i][j], dd[i][k] + dd[k][j]);
}

int main() {
	memset(dd, 0x3f3f, sizeof(dd));
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		dd[i][i] = 0;
	for (int i = 0, a, b, c; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		dd[a][b] = min(dd[a][b], (long long) c);
		dd[b][a] = min(dd[b][a], (long long) c);
	}
	FloydWarshall();
	for (int i = 0, a, b; i < q; ++i) {
		scanf("%d%d", &a, &b);
		if (dd[a][b] == inf)
			printf("-1\n");
		else
			printf("%lld\n", dd[a][b]);
	}
}