/*
============================================================================
 Name:		Grid 1
 Link:		https://atcoder.jp/contests/dp/tasks/dp_h
 Author:	Dong Liu
 Date:		2021-02-06
============================================================================
* dp[i][j] = # of ways to go to (i, j)
* Transitions:
	* dp[i][j] = 0 if grid[i][j] == '#'
	* dp[i+1][j] += dp[i][j]
	* dp[i][j+1] += dp[i][j] 
* answer:
	* dp[h][w]
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

const int MOD = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w;
	cin >> h >> w;
	vector<VI> dp(h, VI(w));
	dp[0][0] = 1;

	vector<string> grid(h);
	EACH(x, grid) cin >> x;
	F0R(i,h) F0R(j,w) {
		if(grid[i][j] == '#') dp[i][j] = 0;
		if(i+1 < h) dp[i+1][j] = ( dp[i+1][j] + dp[i][j] ) % MOD;
		if(j+1 < w) dp[i][j+1] = ( dp[i][j+1] + dp[i][j] ) % MOD;
	}
	cout << dp[h-1][w-1] << '\n';
}