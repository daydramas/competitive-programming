/**
 * Home on the Range
 * Created on 2021-02-20
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 251

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	string s[N];
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	static int dp[N][N];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (s[i][j] == '1')
				dp[i][j] = min({dp[i][j - 1], dp[i - 1][j],
						dp[i - 1][j - 1]}) +
					   1;
			else
				dp[i][j] = 0;
	static int suf[N];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			++suf[dp[i][j]];
	for (int i = n; i >= 2; --i)
		suf[i - 1] += suf[i];
	for (int i = 2; i <= n; ++i)
		if (suf[i])
			cout << i << ' ' << suf[i] << '\n';
}