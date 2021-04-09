#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;
 
int bit[N][N];
 
int query(int i, int j) {
	int ans = 0;
	for (int x = i; x > 0; x -= x & (-x))
		for (int y = j; y > 0; y -= y & (-y))
			ans += bit[x][y];
	return ans;
}
 
void update(int i, int j, int k) {
	for (int x = i; x < N; x += x & (-x))
		for (int y = j; y < N; y += y & (-y))
			bit[x][y] += k;
}
 
int n, q, g[N][N];
char s[N];
 
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; ++j) {
			if (s[j] == '*') {
				update(i, j, 1);
				g[i][j] = 1;
			} else {
				g[i][j] = -1;
			}
		}
	}	
	for (int i = 0, t, x, y, X, Y; i < q; ++i) {
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			update(x, y, g[x][y] = -g[x][y]);
		} else {
			scanf("%d%d", &X, &Y);
			printf("%d\n", query(X, Y) - query(X, y - 1) - query(x - 1, Y) + query(x - 1, y - 1));
		}
	}
}