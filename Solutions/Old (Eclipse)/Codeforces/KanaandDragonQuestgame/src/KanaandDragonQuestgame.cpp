#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables

//functions
void solve () {
	int x, n, m; cin >> x >> n >> m;
	int dp[35][35];
	for (int i=0; i<=n; i++)
	for (int j=0; j<=m; j++) dp[i][j] = 1000000000;
	dp[0][0] = x;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			if (i+1 <= n) {
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]/2 + 10);
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			}
			if (j+1 <= m) {
				dp[i][j+1] = min(dp[i][j+1], dp[i][j] - 10);
				dp[i][j+1] = min(dp[i][j+1], dp[i][j]);

			}
		}
	}
	if (dp[n][m] <= 0) {
		cout <<"YES"<<endl;
	} else cout <<"NO"<<endl;
//	cout << dp[n][m] << endl;
}
int main() {
	//local variables

	//input
	int t; cin >> t;
	for (int i=1; i<=t; i++) {
		solve();

	}
	//main

	//output

	return 0;
}
