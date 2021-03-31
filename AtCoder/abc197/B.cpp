#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int h, w, x, y;
char c[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	scanf("%d%d%d%d", &h, &w, &x, &y);
	for (int i = 0; i < h; ++i) {
		scanf("%s", c[i]);
	}
	--x, --y; int ans = 1;
	for (int k = 0; k < 4; ++k) {
		int i = x, j = y;
		while (1) {
			i += dx[k], j += dy[k];
			if (i < 0 || i >= h || j < 0 || j >= w) break;
			if (c[i][j] == '#') break;
			ans++;
		}
	}
	printf("%d\n", ans);
}