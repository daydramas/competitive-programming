/*
============================================================================
 Name:		Knapsack 1
 Link:		https://atcoder.jp/contests/dp/tasks/dp_d
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
 * dp[i] = maximum sum of values such that the weight sums up to i
 * base case: dp[0] = 0
 * transitions:
	* dp[i+w] = max(dp[i] + v)
 * answer: maximum dp value
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
	vector<LL> dp(W+1);
	int w; LL v;
	while(n--) {
		cin >> w >> v;
		ROF(i,0,W) if(i-w >= 0)
			dp[i] = max(dp[i], dp[i-w] + v);
	}
	cout << *max_element(ALL(dp)) << '\n';

}