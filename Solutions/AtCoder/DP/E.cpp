/*
============================================================================
 Name:		Knapsack 2
 Link:		https://atcoder.jp/contests/dp/tasks/dp_e
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
 * dp[i] = minimum sum of weights to form value i
 * base case: dp[0] = 0, dp[i] = inf
 * transitions
	* dp[i+v = min(dp[i+v], dp[i]+w)
 * answer: maximum index such that dp[i] <= W
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

	int n, W; cin >> n >> W;
	vector<LL> dp(100001, 1e9+7); dp[0] = 0;
	LL w; int v;
	while(n--) {
		cin >> w >> v;
		R0F(i,100001) if(i-v >= 0) {
			dp[i] = min(dp[i], dp[i-v] + w);
		}
	}
	int ans = 0;
	F0R(i,100001) if(dp[i] <= W) ans = max(ans, i);
	cout << ans << '\n';

}
