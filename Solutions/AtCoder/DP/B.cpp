/*
============================================================================
 Name:		Frog 2
 Link:		https://atcoder.jp/contests/dp/tasks/dp_b
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
 * dp[i] = minimum cost to reach $i$
 * base case: dp[1] = 0
 * transitions:
	* dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]))
	* dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i]))
	* ...
	* dp[i+k] = min(dp[i+k], dp[i] + abs(h[i+k] - h[i]))
 * answer: dp[n]
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

template<class T> void MIN(T &A, const T &B) {
	A = (B < A ? B : A); }

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k; cin >> n >> k;
	VI a(n); EACH(x,a) cin >> x;
	VI dp(n,1e9); dp[0] = 0;
	F0R(i,n) FOR(j,1,k) {
		if(i+j >= n) break; 
		MIN(dp[i+j],dp[i]+abs(a[i+j]-a[i]));
	} 	
	cout << dp[n-1] << '\n';

}
