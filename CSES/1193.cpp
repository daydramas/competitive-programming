#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, d[N][N];
char s[N][N], dir[N][N], ans[N * N];

struct P {
	int i, j;
} A, B, pa[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'A') A = {i, j};
			else if (s[i][j] == 'B') B = {i, j};
	}
	queue<P> q;
	memset(d, -1, sizeof(d));
	auto add = [&](P p, int x, int y, char c) {
		if (x < 0 || x >= n || y < 0 || y >= m) return;
		if (d[x][y] != -1 || s[x][y] == '#') return;
		d[x][y] = d[p.i][p.j] + 1, dir[x][y] = c, pa[x][y] = p;
		q.push({x, y});
	};
	add(A, A.i, A.j, 'F');
	while (!q.empty()) {
		P f = q.front(); q.pop();
		add(f, f.i + 1, f.j, 'D');
		add(f, f.i - 1, f.j, 'U');
		add(f, f.i, f.j + 1, 'R');
		add(f, f.i, f.j - 1, 'L');
	}
	if (d[B.i][B.j] == -1)
		printf("NO\n");
	else {
		printf("YES\n");
		int len = 0;
		while (A.i != B.i || A.j != B.j) {
			ans[len++] = dir[B.i][B.j];
			B = pa[B.i][B.j];
		}
		printf("%d\n", len);
		for (int i = len - 1; i >= 0; --i)
			printf("%c", ans[i]);
		printf("\n");
	}
}