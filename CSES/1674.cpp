#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int hd[N], nx[N], to[N], ei = 0;

inline void link(int i, int j) {
	nx[++ei] = hd[i], hd[i] = ei, to[ei] = j;
}

int n, ss[N];

int dfs(int x) {
	ss[x] = 1;
	for (int j = hd[x], y; j; j = nx[j])
		ss[x] += dfs(y = to[j]);
	return ss[x];
}

int main() {
	scanf("%d", &n);
	for (int i, j = 2; j <= n; ++j) {
		scanf("%d", &i);
		link(i, j);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ss[i] - 1);
	printf("\n");
}