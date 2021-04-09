#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, ans;
char s[N][N];

void dfs(int i, int j) {
	s[i][j] = '#';
	#define add(x, y) if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.')\
						dfs(x, y)
	add(i + 1, j); add(i, j + 1); add(i - 1, j); add(i, j - 1);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '.')
				dfs(i, j), ans++;
	printf("%d\n", ans);
}