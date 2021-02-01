/**
 * E - Brackets
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define N	105

int dp[N][N];

bool check(string &s, int i, int j) {
	if(s[i] == '[' && s[j] == ']') return 1;
	if(s[i] == '(' && s[j] == ')') return 1;
	return 0;
}
int solve(string &s) {
	const int n = s.length();
	memset(dp, 0, sizeof(dp));
	for(int sz=1; sz<=n; sz++) {
		for(int i=0; i+sz-1<n; i++) {
			int j = i+sz-1;
			dp[i][j] = dp[i][j-1];
			for(int k=i; k<j; k++) {
				if(check(s, k, j)) {
					dp[i][j] = max(dp[i][j],
						dp[i][k-1] + 2 + dp[k+1][j-1]);
				}
			}
		}
	}
	return dp[0][n-1];
}

int main() {

	string s;
	while(1) {
		cin >> s;
		if(s == "end") break;
		cout << solve(s) << '\n';
	}
}