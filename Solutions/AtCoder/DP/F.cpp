/*
============================================================================
 Name:		LCS
 Link:		https://atcoder.jp/contests/dp/tasks/dp_f
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
 * dp[i][j] = maximum length of common subsequence 
 	* using i characters of s and j characters of t
 * Transitions:
 	* dp[i][j] = max(dp[i-1][j], dp[i][j-1])
	* if s[i] == t[j] dp[i][j] = dp[i-1][j-1] + 1
 * Answer: dp[n][m] (then backtrack to find string)
*/

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

#define F			first
#define S			second
#define PB			push_back
#define ALL(x)		begin(x), end(x)
#define SZ(x)		int((x).size())
#define F0R(i,a)	for(int i=0; i<(a); i++)
#define FOR(i,a,b)	for(int i=(a); i<=(b); i++)
#define R0F(i,a)	for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b)	for(int i=(b); i>=(a); i--)
#define EACH(a,x)	for (auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s, t; cin >> s >> t;
	int n = SZ(s), m = SZ(t);
	s = " " + s, t = " " + t;
	vector<VI> dp(n+1, VI(m+1));
	FOR(i,1,n) FOR(j,1,m) {
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
	}
	string ans;
	int x = n, y = m;
	while(x >= 1 && y >= 1) {
		if(s[x] == t[y]) {
			ans.PB(s[x]);
			x--, y--;
		} else if(dp[x-1][y] > dp[x][y-1]) {
			x--;
		} else {
			y--;
		}
	}
	reverse(ALL(ans));
	cout << ans << '\n';
}
