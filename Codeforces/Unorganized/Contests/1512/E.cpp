#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;
 
bool dp[N * N][N];
 
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int k = 1; k <= (r - l + 1); ++k)
				for (int j = i; j <= s; ++j)
					if (dp[j - i][k - 1])
						dp[j][k] = 1;
		if (!dp[s][r - l + 1]) {
			cout << "-1\n";
		} else {
			vector<int> pp(n + 1);
			int k = r - l + 1;
			while (k) {
				int i = 1;
				for (; i <= n; ++i)
					if (dp[s - i][k - 1])
						break;
				pp[i] = 1;
				// cout << "add " << s - p[s][k] << endl;
				s -= i, k--;
			}
			vector<int> qq;
			for (int i = 1; i <= n; ++i)
				if (!pp[i]) qq.push_back(i);
			for (int i = 0; i < l - 1; ++i) {
				cout << qq.back() << ' '; 
				qq.pop_back();
			}
			for (int i=  1; i <= n; ++i) if (pp[i]) cout << i << ' ';
			for (int i : qq) cout << i << ' ';
			cout << '\n';
		}
	}
}