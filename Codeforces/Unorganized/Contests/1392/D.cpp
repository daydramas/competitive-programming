#include <bits/stdc++.h>
using namespace std;


const char f[2] = {'R', 'L'};

#define cmin(a, b) a = min(a, b);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0x3f3f3f3f;
		for (int _ = 0; _ < 5; ++_) {
			int dp[n][2][3];
			memset(dp, 69, sizeof(dp));
			auto c = [&](int i, char c) {
				return (c == s[i] ? 0 : 1);
			};
			dp[0][0][1] = c(0, f[0]);
			for (int i = 0; i + 1 < n; ++i)
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < 3; ++k)	{
						cmin(dp[i + 1][1 - j][1], dp[i][j][k] + c(i + 1, f[1 - j]));
						if (k != 2) cmin(dp[i + 1][j][k + 1], dp[i][j][k] + c(i + 1, f[j]));
					}
			
			for (int k = 0; k < 3; ++k)
				cmin(ans, dp[n - 1][1][k]);
			rotate(s.begin(), s.begin() + 1, s.end());
		}
		cout << ans << '\n';
	}
}