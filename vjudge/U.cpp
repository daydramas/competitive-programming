/**
 * U - Dollar Dayz
*/

#include <iostream>
#include <vector>
using namespace std;

#define N	(1<<18) // 2e5
typedef unsigned long long ull;

const ull MOD = 100000000000000000LL;

int main() {

	static int n, k;
	ull dp[105][1005][2];
	
	cin >> n >> k;
	dp[0][0][0] = 1;

	for(int i=1; i<=k; i++) {
		dp[i][0][1] = 1;
		for(int j=1; j<=n; j++) {
			if(j >= i) {
				dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - i][0];
				dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - i][1];
				dp[i][j][0] += dp[i][j][1] / MOD;
				dp[i][j][1] %= MOD;
			} else {
				dp[i][j][0] = dp[i - 1][j][0];
				dp[i][j][1] = dp[i - 1][j][1];
			}
		}
	}
	if (dp[k][n][0]) {
		cout << dp[k][n][0];
	}
	cout << dp[k][n][1]<<endl;
}