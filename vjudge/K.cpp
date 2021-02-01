/**
 * K - Dima and Salad
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N	(1<<18) // 2e5
#define K	(10000)
#define M	(20005)


int main() {

	static int n, k, a[N], b[N];
	static int dp[2][M];

	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int j=0; j<n; j++) cin >> b[j];
	
	for(int i=0; i<M; i++) {
		dp[0][i] = -1e9;
	}
	dp[0][K] = 0;
	for(int i=0; i<n; i++) {
		int v = a[i] - b[i] * k;
		for(int j=0; j<M; j++) {
			dp[1][j] = dp[0][j];
		}
		for(int j=0; j<M; j++) {
			if(j + v >= 0 && j + v < M) {
				dp[1][j + v] = max(dp[1][j + v], 
							dp[0][j] + a[i]);
			}
		}
		swap(dp[0], dp[1]);
		for(int j=0; j<M; j++) {
			dp[1][j] = -1e9;
		}
	}
	if(dp[0][K] <= 0) cout << "-1" << '\n';
	else cout << dp[0][K] << '\n';
}
