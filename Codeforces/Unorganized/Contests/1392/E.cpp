#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n;
long long k, g[N][N], p[N][N];

typedef pair<int, int> P;
#define x first
#define y second

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	{
			g[i][j] = ((i & 1) ? 1LL << (i + j) : 0LL);
			p[i][j] = g[i][j];
			if (i) p[i][j] += p[i - 1][j];
			if (j) p[i][j] += p[i][j - 1];
			printf("%lld ", g[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%lld", &k);
		vector<P> p; P m = {n - 1, n - 1};
		while (m.x != 0 || m.y != 0) {
			// if (m.y >= 0)printf("m = {%d, %d}\n", m.x, m.y);
			// fflush(stdout);
			p.push_back(m);
			k -= g[m.x][m.y];
			if (!m.x)
				m.y--;
			else if (!m.y)
				m.x--;
			else {
				if (g[m.x - 1][m.y]) {
					if (k >= g[m.x - 1][m.y])
						--m.x;
					else
						--m.y;
				} else {
					if (k >= g[m.x][m.y - 1])
						--m.y;
					else
						--m.x;
				}
			}
		}
		p.push_back(m);
		reverse(begin(p), end(p));
		for (P m : p)
			printf("%d %d\n", m.x + 1, m.y + 1);
		printf("\n");
		fflush(stdout);
	}
}