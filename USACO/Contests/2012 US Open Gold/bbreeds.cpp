#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define MOD	1000000007
#define INF	1e9
#define EPS	1e-9
#define N	1000

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);

	string s;
	int n;
	static int a[N + 1], dp[N + 1][2 * (N + 1)];

	cin >> s;
	n = s.length();
	for (int i = 0; i < n; ++i)
		a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);

	auto add = [](int& a, const int& b) {
		a = (a + b) % 2012;
	};
	
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= (2 * n); ++j) {
			int k = a[i] - j;
			if (k < 0 || k > (2 * n))
				continue;
			if (s[i] == '(') {
				if (j + 1 <= 2 * n)
					add(dp[i + 1][j + 1], dp[i][j]);
				if (k + 1 <= 2 * n)
					add(dp[i + 1][j], dp[i][j]);
			} else {
				if (j - 1 >= 0)
					add(dp[i + 1][j - 1], dp[i][j]);
				if (k - 1 >= 0)
					add(dp[i + 1][j], dp[i][j]);
			}
		}
	cout << dp[n][0] << '\n';

}