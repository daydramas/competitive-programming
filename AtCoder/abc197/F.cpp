#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;

template<class T> using benq = priority_queue<T, vector<T>, greater<T>>;
using F = tuple<int, int, int>;

struct L {
	int x;
	char t;
	L *next;
} *aa[N];

void link(int i, int j, char tt) {
	L *l = new L();
	l->x = j, l->t = tt;
	l->next = aa[i];
	aa[i] = l;
};

int n, m, dp[N][N];

int main() {
	scanf("%d%d", &n, &m);
	char c;
	benq<F> ben;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d %d %c", &a, &b, &c);
		link(a, b, c), link(b, a, c);
		dp[a][b] = dp[b][a] = 1;
		ben.push({1, a, b});
		ben.push({1, b, a});
	}	
	for (int i = 1; i <= n; ++i) {
		dp[i][i] = 0;
		ben.push({0, i, i});
	}
	while (ben.size()) {
		auto [l, i, j] = ben.top();
		ben.pop();
		if (dp[i][j] != l) continue;
		for (L *a = aa[i]; a; a = a->next)
			for (L *b = aa[j]; b; b = b->next) {
				if (a->t != b->t) continue;
				if (dp[a->x][b->x] > l + 2) {
					dp[a->x][b->x] = l + 2;
					ben.push({dp[a->x][b->x], a->x, b->x});
				}
			}
	}
	printf("%d\n", dp[1][n] == INF ? -1 : dp[1][n]);
}