/**
 * G - Again Palindrome
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define N	64
typedef long long ll;

ll dp[N][N];

ll solve(const string &s) {
	const int n = s.length();
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; i++) {
		dp[i][i] = 1;
	}
	for(int sz=2; sz<=n; sz++)
	for(int i=0; i+sz-1<n; i++) {
		int j = i + sz - 1;
		dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
		if(s[i] == s[j]) dp[i][j] += dp[i+1][j-1] + 1;
	}
	return dp[0][n-1];
}

int main() {

	static int t;
	static string s;

	cin >> t;
	while(t--) {
		cin >> s;
		cout << solve(s) << '\n';
	}
}