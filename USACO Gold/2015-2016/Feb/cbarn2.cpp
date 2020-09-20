/*
 ID: dongliu3
 TASK: cbarn2
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define ll long long
#define INF 0x3FFFFFFFFFFFFFFFLL
// global variables
int n, k;
ll r[101];
ll dp[101][8], d[101][101][8];
//functions
ll dist(ll a, ll b) {
	if (b >= a) {
		return b - a;
	}
	return b + n - a;
}
void setUp() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = INF;
		}
	}
	for (int j = 0; j <= k; j++) {
		dp[n][j] = 0;
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = INF;
	}
}
void ROTATE() {
	int t = r[1];
	for (int i = 1; i < n; i++) {
		r[i] = r[i + 1];
	}
	r[n] = t;
}
int main() {
	// local variables

	// fstream
	ifstream fin("cbarn2.in");
	ofstream fout("cbarn2.out");

	// input
	fin >> n >> k;
	for (int i = 1; i <= n; i++) {
		fin >> r[i];
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= k; j++) {
//			dp[i][j] = INF;
//		}
//	}
//	for (int j = 0; j <= k; j++) {
//		dp[0][j] = 0;
//	}
//	for (int j = 1; j <= n; j++) {
//		for (int l = 0; l <= k; l++) {
//			d[0][j][l] = 0;
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			for (int l = 0; l <= k; l++) {
//				d[i][j][l] = INF;
//			}
//		}
//	}
	// main
	ll ans = INF;
//	int arr[6] = { 0, 1, 2, 3, 4, -1 };
//	rotate(arr + 1, arr + 2, arr + 6);
//	for (int i = 0; i <= 4; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
//	rotate(arr + 1, arr + 2, arr + 6);
//	for (int i = 0; i <= 4; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
	for (int i = 1; i <= n; i++) {
		setUp();
//		cout << i << endl;
//		for (int x = 1; x <= n; x++) {
//			cout << r[x] << " ";
//		}
		cout << endl;
		for (int K = 1; K <= k; K++) {
			for (int j = 1; j <= n; j++) {
				ll sum = 0;
//				cout << "dp[" << j << "][" << K << "] = " << dp[j][K] << endl;
				for (int j2 = (j + 1); j2 <= n + 1; j2++) {
//					cout << "sum: " << sum << " dp: " << dp[j2][K - 1] << endl;
					dp[j][K] = min(dp[j][K], dp[j2][K - 1] + sum);
					sum += (j2 - j) * r[j2];
				}
//				dp[j][K] = min(dp[j][K], dp[j2][K - 1] + sum);
//				cout << "dp[" << j << "][" << K << "] = " << dp[j][K] << endl;
			}
		}
//		cout << "\n";
		ans = min(ans, dp[1][k]);
		ROTATE();
	}
	fout << ans << endl;
	return 0;
}
