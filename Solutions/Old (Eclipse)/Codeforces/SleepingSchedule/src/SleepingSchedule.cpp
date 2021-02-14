#include <bits/stdc++.h>

using namespace std;

//structures/defines
#define INF 1000000000

//global variables

const int maxn = 2005;
int N, H, L, R;
int A[maxn];
int dp[maxn][maxn];

//functions

int main() {
	//local variables

	//input
	cin >> N >> H >> L >> R;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
	}
	//main
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=H; j++) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int i=1; i<=N; i++) {
		for (int j=0; j<=H; j++) {
			int b = (j-A[i]+H)%H;
			dp[i][j] = max(dp[i][j],dp[i-1][b]
							+ (L <= j && j <= R));
			b = (j-A[i]+H+1)%H;
			dp[i][j] = max(dp[i][j],dp[i-1][b]
							+ (L <= j && j <= R));
		}
	}
	//output
	int ans = 0;
	for (int j=0; j<=H; j++) {
		ans = max(ans, dp[N][j]);
	}
	cout << ans << endl;
	return 0;
}
