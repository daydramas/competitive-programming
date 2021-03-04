#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 1000

struct cow { int r; long long c; };
bool compare (cow i, cow j) {
	return i.c < j.c;
}

int main() {
	int n, k;
	long long b, dp[N + 1][N + 1];
	cow cows[N + 1];

	cin >> n >> k >> b;
	for (int i = 1; i <= n; ++i)
		cin >> cows[i].r >> cows[i].c;
	
	sort(cows + 1, cows + n + 1, compare);
	memset(dp, 0x3F3F, sizeof(dp));
	dp[0][0] = 0;
	// cout << 0x3F3F3F3F3F3F3F3F << endl;
	// for (int i = 1; i <= n; ++i)	
		// cout << "cows[" << i << "] = {" << cows[i].r << ' ' << cows[i].c << "}\n";
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= k; ++j) {
			// cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			long long m0, M0, m1, M1;
			m0 = m1 = b + 1;
			M0 = M1 = -1;
			for (int l = i + 1; l <= n; ++l) {
				if (cows[l].r == 1) 
					m0 = min(m0, cows[l].c), M0 = max(M0, cows[l].c);
				else
					m1 = min(m1, cows[l].c), M1 = max(M1, cows[l].c);
				if (l < n && cows[l + 1].c == cows[l].c)
					continue;
				// cout << "l = " << l <<", rest = " << m0 << " " << M0 << " " << m1 << " " << M1 << endl;
				if (j + 1 <= k)
					dp[l][j + 1] = min(dp[l][j + 1], dp[i][j] + 
						2 * (max(M0, M1) - min(m0, m1) + 1));
				if (M0 == -1) {
					if (j + 1 <= k)
						dp[l][j + 1] = min(dp[l][j + 1], dp[i][j] + 
							(M1 - m1 + 1));
				} else if (M1 == -1) {
					if (j + 1 <= k)
						dp[l][j + 1] = min(dp[l][j + 1], dp[i][j] + 
							(M0 - m0 + 1));	
				} else {
					if (j + 2 <= k)
						dp[l][j + 2] = min(dp[l][j + 2], dp[i][j] + 
							(M1 - m1 + 1) + (M0 - m0 + 1));	
				}
			}
		}
	cout << dp[n][k] << '\n';
}