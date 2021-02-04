/*
============================================================================
 Name:		Fruit Feast
 Link:		http://usaco.org/index.php?page=viewproblem2&cpid=574
 Author:	Dong Liu
 Date:		2021-02-03
 Status:	************
 Tags:		DP Knapsack
============================================================================
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
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	
	int a, b, t; cin >> t >> a >> b;
	vector<VI> dp(2,VI(t+1));
	int ans = 0; dp[0][0] = 1;
	F0R(i,2) FOR(j,0,t) {
		if(j >= a) dp[i][j] |= dp[i][j-a];
		if(j >= b) dp[i][j] |= dp[i][j-b];
		if(!i) dp[i+1][j/2] |= dp[i][j];
		if(dp[i][j]) ans = max(ans, j);
	}
	cout << ans << '\n';

}