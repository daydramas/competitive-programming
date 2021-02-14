#include <bits/stdc++.h>

using namespace std;

//structures/defines

//global variables

//functions
void solve() {
	int n; cin >> n;
	int a[2005];
	for (int i=1; i<=n; i++) cin >> a[i];
	int dp[30][2005];
	if (n == 1) {
		cout <<"1"<<endl;
		return;
	}
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=n; i++) {
		dp[a[i]][i] = 1;
	}
	for (int k = 1; k <= 26; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j=i+1; j<=n; j++) {
//				if (a[j] == k) {
					dp[k][j] = max(dp[k][j], dp[k][i]+(a[j] == k));
//				}
			}
		}
	}
//	for (int k=1; k<=3; k++) {
//		for (int i=1; i<=n; i++) {
//			cout <<"dp["<<k<<"]["<<i<<"] = "<<dp[k][i]<<endl;
//		}
//	}
	int ans = 0;
	for (int a=1; a<=26; a++) {
	for (int b=1; b<=26; b++) {
		for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			if (dp[a][i]+dp[b][j]-dp[b][i]+dp[a][n]-dp[a][j] == 3) {
//				cout<<a<<" "<<b<<" i: "<<i<<" j: "<<j<<" : "<< dp[a][i]<<"+"<<dp[b][j]<<"-"<<dp[b][i]<<"+"<<dp[a][n]<<"-"<<dp[a][j] << endl;
			}
			if (dp[a][n]-dp[a][j] == dp[a][i]) {
				ans = max(ans,dp[a][i]+dp[b][j]-dp[b][i]+dp[a][n]-dp[a][j]);
			}
		}
		}
	}
	}
	cout << ans << endl;
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
