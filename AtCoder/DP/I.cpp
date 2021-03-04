
/*
============================================================================
 Name:		Coins
 Link:		https://atcoder.jp/contests/dp/tasks/dp_i
 Author:	Dong Liu
 Date:		2021-02-06
============================================================================
* dp[i][b] = probability using first i coins to make a balance of b
* Transitions:
	* dp[i][b+1] += dp[i-1][b] * p[i]
	* dp[i][b-1] += dp[i-1][b] * (1 - p[i])
* Answer: sum of dp[n][b] where b is positive
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
#define EACH(a,x)	for(auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	long double a[n+1]; FOR(i,1,n) cin >> a[i];
	long double dp[n+1][n+n+2]{}; 
	dp[0][n] = 1;
	FOR(i,1,n) FOR(b,0,n+n) {
		if(b - 1 >= 0) dp[i][b-1] += (1-a[i]) * dp[i-1][b];
		if(b + 1 <= n+n) dp[i][b+1] += (a[i]) * dp[i-1][b];
	}
	long double ans = 0;
	FOR(b,n+1,n+n) ans += dp[n][b];
	cout << fixed << setprecision(10) << ans << '\n';

}