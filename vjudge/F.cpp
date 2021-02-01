/**
 * F - Palindrome
*/

#include <iostream>
#include <string>
using namespace std;

#define N	5005

int dp[N][3];

int main() {

	static int n;
	static string s;

	cin >> n >> s;
	for(int i=0; i<n; i++) {
		dp[i][1] = 0;
	}
	// sz = 0, sz-1 = 1, sz-2 = 2
	for(int sz=1; sz<n; sz++) {
		for(int i=0; i+sz<n; i++) {
			if(s[i] == s[i+sz]) {
				if(sz == 1) dp[i][0] = 0;
				else dp[i][0] = dp[i+1][2];
			} else {
				dp[i][0] = min(dp[i][1], dp[i+1][1]) + 1;
			}
		}
		for(int i=0; i<n; i++) {
			dp[i][2] = dp[i][1];
			dp[i][1] = dp[i][0];
			dp[i][0] = 0;
		}
	}
	cout << dp[0][1] << '\n';
}