#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m, q, dp[N][N];

char s[N][N];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int k = 0;
			auto check = [&](int i, int j, int k, int d, char c) -> bool {
				while (k--) {
					if (i < 1 || j < 1 || i > n || j > m)
						return false;
					if (s[i][j] != c)
						return false;
					i += dx[d], j += dy[d];
				}
				return 1;
			};
			while (check(i - k, j - k, k + 1, 0, 'R')
				&& check(i - k, j - k, k + 1, 1, 'R')
				&& check(i + k + 1, j - k, 1, 'Y')
				&& check(i + k + 1, j - k, 2, 'Y')
				&& check(i - k, j + k + 1, 3, 'G')
				&& check(i - k, j + k + 1, 0, 'G')
				&& check(i + k + 1, j + k + 1, 2, 'B')
				&& check(i + k + 1, j + k + 1, 3, 'B')) k++;
			dp[i][j] = k;
		}
		
}